#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to store array element with its array index and element index
struct Element {
    int value;
    int arrayIndex;
    int elementIndex;
    
    Element(int val, int arrIdx, int elemIdx) 
        : value(val), arrayIndex(arrIdx), elementIndex(elemIdx) {}
};

// Comparator for min heap
struct CompareElement {
    bool operator()(const Element& a, const Element& b) {
        return a.value > b.value; // Min heap
    }
};

// Efficient approach using Min Heap
// Time Complexity: O(N log K) where N is total elements, K is number of arrays
// Space Complexity: O(K) for heap
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    vector<int> result;
    
    // Min heap to store elements
    priority_queue<Element, vector<Element>, CompareElement> minHeap;
    
    // Insert first element from each array into the heap
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push(Element(arrays[i][0], i, 0));
        }
    }
    
    // Extract minimum element and insert next element from the same array
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        
        result.push_back(current.value);
        
        // If there's a next element in the same array, insert it
        int nextIndex = current.elementIndex + 1;
        if (nextIndex < arrays[current.arrayIndex].size()) {
            minHeap.push(Element(
                arrays[current.arrayIndex][nextIndex],
                current.arrayIndex,
                nextIndex
            ));
        }
    }
    
    return result;
}

// Simple approach: Merge arrays one by one
// Time Complexity: O(N * K) where N is average array size, K is number of arrays
vector<int> mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }
    
    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }
    
    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }
    
    return merged;
}

vector<int> mergeKArraysSimple(vector<vector<int>>& arrays) {
    if (arrays.empty()) return {};
    
    vector<int> result = arrays[0];
    
    for (int i = 1; i < arrays.size(); i++) {
        result = mergeTwoSortedArrays(result, arrays[i]);
    }
    
    return result;
}

// Helper function to print array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int k;
    
    cout << "Enter number of sorted arrays (K): ";
    cin >> k;
    
    vector<vector<int>> arrays(k);
    
    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter number of elements in array " << (i + 1) << ": ";
        cin >> n;
        
        arrays[i].resize(n);
        cout << "Enter " << n << " sorted elements: ";
        for (int j = 0; j < n; j++) {
            cin >> arrays[i][j];
        }
    }
    
    cout << "\nInput Arrays:" << endl;
    for (int i = 0; i < k; i++) {
        cout << "Array " << (i + 1) << ": ";
        printArray(arrays[i]);
    }
    
    // Using efficient Min Heap approach
    vector<int> mergedResult = mergeKSortedArrays(arrays);
    
    cout << "\nMerged Sorted Array: ";
    printArray(mergedResult);
    
    return 0;
}
