#include <iostream>
using namespace std;

// Node structure for linked list
struct ListNode {
    int data;
    ListNode* next;
    
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to simplify the logic
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    // Traverse both lists and merge
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // Attach remaining nodes
    if (list1 != nullptr) {
        current->next = list1;
    }
    if (list2 != nullptr) {
        current->next = list2;
    }
    
    ListNode* mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

// Recursive approach (alternative method)
ListNode* mergeTwoSortedListsRecursive(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    
    if (list1->data <= list2->data) {
        list1->next = mergeTwoSortedListsRecursive(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoSortedListsRecursive(list1, list2->next);
        return list2;
    }
}

// Helper function to insert node at the end
void insertAtEnd(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper function to print linked list
void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "Empty List" << endl;
        return;
    }
    
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to delete the linked list
void deleteList(ListNode*& head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;
    
    int n1, n2, value;
    
    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    cout << "Enter " << n1 << " sorted values for list1: ";
    for (int i = 0; i < n1; i++) {
        cin >> value;
        insertAtEnd(list1, value);
    }
    
    cout << "\nEnter number of nodes in second sorted list: ";
    cin >> n2;
    cout << "Enter " << n2 << " sorted values for list2: ";
    for (int i = 0; i < n2; i++) {
        cin >> value;
        insertAtEnd(list2, value);
    }
    
    cout << "\nList 1: ";
    printList(list1);
    
    cout << "List 2: ";
    printList(list2);
    
    // Merge using iterative approach
    ListNode* mergedList = mergeTwoSortedLists(list1, list2);
    
    cout << "\nMerged Sorted List: ";
    printList(mergedList);
    
    // Clean up memory
    deleteList(mergedList);
    
    return 0;
}
