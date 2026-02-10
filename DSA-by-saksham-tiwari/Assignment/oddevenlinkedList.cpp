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

Node* oddEvenListBruteForce(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    vector<int> oddValues;
    vector<int> evenValues;
    
    Node* temp = head;
    int position = 1;
    
    while (temp != nullptr) {
        if (position % 2 == 1) {
            oddValues.push_back(temp->data);
        } else {
            evenValues.push_back(temp->data);
        }
        temp = temp->next;
        position++;
    }
    
    temp = head;
    for (int val : oddValues) {
        temp->data = val;
        temp = temp->next;
    }
    for (int val : evenValues) {
        temp->data = val;
        temp = temp->next;
    }
    
    return head;
}

Node* oddEvenListBetter(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    
    Node* temp = head;
    int position = 1;
    
    while (temp != nullptr) {
        Node* newNode = new Node(temp->data);
        
        if (position % 2 == 1) {
            if (oddHead == nullptr) {
                oddHead = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else {
            if (evenHead == nullptr) {
                evenHead = newNode;
                evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        
        temp = temp->next;
        position++;
    }
    
    if (oddTail != nullptr) {
        oddTail->next = evenHead;
    }
    
    return oddHead;
}

Node* oddEvenListOptimal(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    
    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenHead;
    
    return head;
}

Node* oddEvenListByValue(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    
    Node* temp = head;
    
    while (temp != nullptr) {
        Node* newNode = new Node(temp->data);
        
        if (temp->data % 2 == 1) {
            if (oddHead == nullptr) {
                oddHead = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else {
            if (evenHead == nullptr) {
                evenHead = newNode;
                evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        
        temp = temp->next;
    }
    
    if (oddTail != nullptr) {
        oddTail->next = evenHead;
    }
    
    return oddHead != nullptr ? oddHead : evenHead;
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
    
    cout << "=== ODD EVEN LIST BY POSITION ===" << endl;
    
    Node* head1 = createList(values);
    cout << "\nOriginal List: ";
    printList(head1);
    cout << "Brute Force (by position): ";
    head1 = oddEvenListBruteForce(head1);
    printList(head1);
    
    Node* head2 = createList(values);
    cout << "\nOriginal List: ";
    printList(head2);
    cout << "Better Approach (by position): ";
    head2 = oddEvenListBetter(head2);
    printList(head2);
    
    Node* head3 = createList(values);
    cout << "\nOriginal List: ";
    printList(head3);
    cout << "Optimal Approach (by position): ";
    head3 = oddEvenListOptimal(head3);
    printList(head3);
    
    cout << "\n=== ODD EVEN LIST BY VALUE ===" << endl;
    
    vector<int> values2 = {1, 6, 3, 8, 5, 2, 7, 4};
    Node* head4 = createList(values2);
    cout << "\nOriginal List: ";
    printList(head4);
    cout << "Grouped by odd/even values: ";
    head4 = oddEvenListByValue(head4);
    printList(head4);
    
    return 0;
}
