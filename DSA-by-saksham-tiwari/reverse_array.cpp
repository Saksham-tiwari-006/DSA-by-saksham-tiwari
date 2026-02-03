#include <bits/stdc++.h>
using namespace std;

// Function to display vector
void displayVector(const vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Method 1: Using reverse() function from algorithm library
void reverseUsingAlgorithm(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
}

// Method 2: Using two pointers approach
void reverseUsingTwoPointers(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    
    while(start < end) {
        // Swap elements at start and end positions
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Method 3: Using manual swap without swap function
void reverseManualSwap(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

// Method 4: Creating a new reversed vector
vector<int> createReversedVector(const vector<int>& arr) {
    vector<int> reversed;
    for(int i = arr.size() - 1; i >= 0; i--) {
        reversed.push_back(arr[i]);
    }
    return reversed;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 60};
    
    cout << "Original Array: ";
    displayVector(arr);
    
    // Method 1: Using reverse() function
    vector<int> arr1 = arr;  // Create a copy
    reverseUsingAlgorithm(arr1);
    cout << "Method 1 - Using reverse() function: ";
    displayVector(arr1);
    
    // Method 2: Using two pointers
    vector<int> arr2 = arr;  // Create a copy
    reverseUsingTwoPointers(arr2);
    cout << "Method 2 - Using two pointers: ";
    displayVector(arr2);
    
    // Method 3: Manual swap
    vector<int> arr3 = arr;  // Create a copy
    reverseManualSwap(arr3);
    cout << "Method 3 - Manual swap: ";
    displayVector(arr3);
    
    // Method 4: Create new reversed vector
    vector<int> arr4 = createReversedVector(arr);
    cout << "Method 4 - New reversed vector: ";
    displayVector(arr4);
    
    return 0;
}