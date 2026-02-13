#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Approach 1: Using Stack (Most Common)
// Time Complexity: O(n)
// Space Complexity: O(n)
void reverseQueueUsingStack(queue<int>& q) {
    stack<int> s;
    
    // Push all elements from queue to stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Pop all elements from stack to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// Approach 2: Using Recursion
// Time Complexity: O(n)
// Space Complexity: O(n) - recursion stack
void reverseQueueUsingRecursion(queue<int>& q) {
    // Base case
    if (q.empty()) {
        return;
    }
    
    // Remove front element
    int front = q.front();
    q.pop();
    
    // Reverse the remaining queue
    reverseQueueUsingRecursion(q);
    
    // Add the front element at the end
    q.push(front);
}

// Approach 3: Reverse first K elements of queue
// Time Complexity: O(n)
// Space Complexity: O(k)
void reverseFirstKElements(queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) {
        return;
    }
    
    stack<int> s;
    
    // Push first k elements to stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    // Push stack elements back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    // Move remaining (n-k) elements to back
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Helper function to print queue
void printQueue(queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    
    cout << "Front -> ";
    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << " ";
    }
    cout << " <- Rear" << endl;
}

// Helper function to create queue from user input
queue<int> createQueue() {
    queue<int> q;
    int n, value;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }
    
    return q;
}

int main() {
    int choice;
    
    cout << "=== Queue Reversal Program ===" << endl;
    cout << "1. Reverse entire queue (using Stack)" << endl;
    cout << "2. Reverse entire queue (using Recursion)" << endl;
    cout << "3. Reverse first K elements" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    queue<int> q = createQueue();
    
    cout << "\nOriginal Queue: " << endl;
    printQueue(q);
    
    switch (choice) {
        case 1:
            reverseQueueUsingStack(q);
            cout << "\nReversed Queue (using Stack): " << endl;
            printQueue(q);
            break;
            
        case 2:
            reverseQueueUsingRecursion(q);
            cout << "\nReversed Queue (using Recursion): " << endl;
            printQueue(q);
            break;
            
        case 3: {
            int k;
            cout << "Enter K (number of elements to reverse): ";
            cin >> k;
            reverseFirstKElements(q, k);
            cout << "\nQueue after reversing first " << k << " elements: " << endl;
            printQueue(q);
            break;
        }
            
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    
    return 0;
}
