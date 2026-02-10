#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* reverseKGroupBruteForce(Node* head, int k) {
    if (head == nullptr || k == 1) return head;
    
    vector<int> values;
    Node* temp = head;
    
    while (temp != nullptr) {
        values.push_back(temp->data);
        temp = temp->next;
    }
    
    int n = values.size();
    for (int i = 0; i < n; i += k) {
        int left = i;
        int right = min(i + k - 1, n - 1);
        
        if (right - left + 1 == k) {
            while (left < right) {
                swap(values[left], values[right]);
                left++;
                right--;
            }
        }
    }
    
    temp = head;
    int index = 0;
    while (temp != nullptr) {
        temp->data = values[index++];
        temp = temp->next;
    }
    
    return head;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

Node* getKthNode(Node* head, int k) {
    k--;
    while (head != nullptr && k > 0) {
        head = head->next;
        k--;
    }
    return head;
}

Node* reverseKGroupBetter(Node* head, int k) {
    if (head == nullptr || k == 1) return head;
    
    Node* temp = head;
    Node* prevGroupEnd = nullptr;
    Node* newHead = nullptr;
    
    while (temp != nullptr) {
        Node* kthNode = getKthNode(temp, k);
        
        if (kthNode == nullptr) {
            if (prevGroupEnd != nullptr) {
                prevGroupEnd->next = temp;
            }
            break;
        }
        
        Node* nextGroupStart = kthNode->next;
        kthNode->next = nullptr;
        
        Node* reversedHead = reverseLinkedList(temp);
        
        if (newHead == nullptr) {
            newHead = reversedHead;
        }
        
        if (prevGroupEnd != nullptr) {
            prevGroupEnd->next = reversedHead;
        }
        
        prevGroupEnd = temp;
        temp = nextGroupStart;
    }
    
    return newHead;
}

Node* reverseKGroupOptimal(Node* head, int k) {
    if (head == nullptr || k == 1) return head;
    
    Node* temp = head;
    Node* prevGroupEnd = nullptr;
    
    while (temp != nullptr) {
        Node* kthNode = getKthNode(temp, k);
        
        if (kthNode == nullptr) {
            if (prevGroupEnd != nullptr) {
                prevGroupEnd->next = temp;
            }
            break;
        }
        
        Node* nextGroupStart = kthNode->next;
        kthNode->next = nullptr;
        
        Node* reversedHead = reverseLinkedList(temp);
        
        if (temp == head) {
            head = reversedHead;
        } else {
            prevGroupEnd->next = reversedHead;
        }
        
        prevGroupEnd = temp;
        temp = nextGroupStart;
    }
    
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* createList(vector<int> values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : values) {
        insertAtTail(head, tail, val);
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    
    Node* head1 = createList(values);
    cout << "Original List: ";
    printList(head1);
    cout << "\nBrute Force Approach (k = " << k << "):" << endl;
    head1 = reverseKGroupBruteForce(head1, k);
    cout << "Reversed List: ";
    printList(head1);
    
    Node* head2 = createList(values);
    cout << "\nBetter Approach (k = " << k << "):" << endl;
    head2 = reverseKGroupBetter(head2, k);
    cout << "Reversed List: ";
    printList(head2);
    
    Node* head3 = createList(values);
    cout << "\nOptimal Approach (k = " << k << "):" << endl;
    head3 = reverseKGroupOptimal(head3, k);
    cout << "Reversed List: ";
    printList(head3);
    
    return 0;
}
