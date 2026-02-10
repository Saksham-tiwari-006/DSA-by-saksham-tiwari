#include <iostream>
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

Node* sortList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    int count0 = 0, count1 = 0, count2 = 0;
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp->data == 0) count0++;
        else if (temp->data == 1) count1++;
        else if (temp->data == 2) count2++;
        temp = temp->next;
    }
    
    temp = head;
    while (temp != nullptr) {
        if (count0 > 0) {
            temp->data = 0;
            count0--;
        } else if (count1 > 0) {
            temp->data = 1;
            count1--;
        } else {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    
    return head;
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

Node* sortListOptimized(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* zeroHead = nullptr;
    Node* zeroTail = nullptr;
    Node* oneHead = nullptr;
    Node* oneTail = nullptr;
    Node* twoHead = nullptr;
    Node* twoTail = nullptr;
    
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp->data == 0) {
            insertAtTail(zeroHead, zeroTail, 0);
        } else if (temp->data == 1) {
            insertAtTail(oneHead, oneTail, 1);
        } else {
            insertAtTail(twoHead, twoTail, 2);
        }
        temp = temp->next;
    }
    
    if (zeroHead != nullptr) {
        if (oneHead != nullptr) {
            zeroTail->next = oneHead;
            oneTail->next = twoHead;
        } else {
            zeroTail->next = twoHead;
        }
        return zeroHead;
    } else {
        if (oneHead != nullptr) {
            oneTail->next = twoHead;
            return oneHead;
        } else {
            return twoHead;
        }
    }
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

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

int main() {
    Node* head = nullptr;
    
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    
    cout << "Original List: ";
    printList(head);
    
    head = sortList(head);
    
    cout << "Sorted List: ";
    printList(head);
    
    return 0;
}
