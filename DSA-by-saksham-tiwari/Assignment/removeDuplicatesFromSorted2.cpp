#include <iostream>
#include <vector>
#include <set>
using namespace std;

int removeDuplicatesBruteForce(vector<int>& nums) {
    set<int> uniqueSet;
    for (int num : nums) {
        uniqueSet.insert(num);
    }
    
    int index = 0;
    for (int num : uniqueSet) {
        nums[index++] = num;
    }
    
    return index;
}

int removeDuplicatesBetter(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    vector<int> temp;
    temp.push_back(nums[0]);
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) {
            temp.push_back(nums[i]);
        }
    }
    
    for (int i = 0; i < temp.size(); i++) {
        nums[i] = temp[i];
    }
    
    return temp.size();
}

int removeDuplicatesOptimal(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    
    return i + 1;
}

int removeDuplicates2BruteForce(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    vector<int> temp;
    temp.push_back(nums[0]);
    int count = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == temp.back()) {
            count++;
            if (count <= 2) {
                temp.push_back(nums[i]);
            }
        } else {
            count = 1;
            temp.push_back(nums[i]);
        }
    }
    
    for (int i = 0; i < temp.size(); i++) {
        nums[i] = temp[i];
    }
    
    return temp.size();
}

int removeDuplicates2Better(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    int index = 1;
    int count = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) {
            count++;
        } else {
            count = 1;
        }
        
        if (count <= 2) {
            nums[index++] = nums[i];
        }
    }
    
    return index;
}

int removeDuplicates2Optimal(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    int i = 2;
    for (int j = 2; j < nums.size(); j++) {
        if (nums[j] != nums[i-2]) {
            nums[i] = nums[j];
            i++;
        }
    }
    
    return i;
}

int removeDuplicatesK(vector<int>& nums, int k) {
    if (nums.size() <= k) return nums.size();
    
    int i = k;
    for (int j = k; j < nums.size(); j++) {
        if (nums[j] != nums[i-k]) {
            nums[i] = nums[j];
            i++;
        }
    }
    
    return i;
}

void printArray(vector<int>& nums, int length) {
    cout << "[";
    for (int i = 0; i < length; i++) {
        cout << nums[i];
        if (i < length - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    cout << "=== REMOVE DUPLICATES (Keep Only 1 Occurrence) ===" << endl;
    
    vector<int> arr1 = {1, 1, 2, 2, 3, 3, 4};
    cout << "\nBrute Force:" << endl;
    cout << "Original: ";
    printArray(arr1, arr1.size());
    int len1 = removeDuplicatesBruteForce(arr1);
    cout << "After removing duplicates (length = " << len1 << "): ";
    printArray(arr1, len1);
    
    vector<int> arr2 = {1, 1, 2, 2, 3, 3, 4};
    cout << "\nBetter Approach:" << endl;
    cout << "Original: ";
    printArray(arr2, arr2.size());
    int len2 = removeDuplicatesBetter(arr2);
    cout << "After removing duplicates (length = " << len2 << "): ";
    printArray(arr2, len2);
    
    vector<int> arr3 = {1, 1, 2, 2, 3, 3, 4};
    cout << "\nOptimal Approach (Two Pointers):" << endl;
    cout << "Original: ";
    printArray(arr3, arr3.size());
    int len3 = removeDuplicatesOptimal(arr3);
    cout << "After removing duplicates (length = " << len3 << "): ";
    printArray(arr3, len3);
    
    cout << "\n\n=== REMOVE DUPLICATES II (Keep At Most 2 Occurrences) ===" << endl;
    
    vector<int> arr4 = {1, 1, 1, 2, 2, 2, 3, 3};
    cout << "\nBrute Force:" << endl;
    cout << "Original: ";
    printArray(arr4, arr4.size());
    int len4 = removeDuplicates2BruteForce(arr4);
    cout << "After removing duplicates (length = " << len4 << "): ";
    printArray(arr4, len4);
    
    vector<int> arr5 = {1, 1, 1, 2, 2, 2, 3, 3};
    cout << "\nBetter Approach:" << endl;
    cout << "Original: ";
    printArray(arr5, arr5.size());
    int len5 = removeDuplicates2Better(arr5);
    cout << "After removing duplicates (length = " << len5 << "): ";
    printArray(arr5, len5);
    
    vector<int> arr6 = {1, 1, 1, 2, 2, 2, 3, 3};
    cout << "\nOptimal Approach:" << endl;
    cout << "Original: ";
    printArray(arr6, arr6.size());
    int len6 = removeDuplicates2Optimal(arr6);
    cout << "After removing duplicates (length = " << len6 << "): ";
    printArray(arr6, len6);
    
    cout << "\n\n=== REMOVE DUPLICATES (Keep At Most K Occurrences) ===" << endl;
    
    vector<int> arr7 = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3};
    int k = 3;
    cout << "\nGeneralized Approach (k = " << k << "):" << endl;
    cout << "Original: ";
    printArray(arr7, arr7.size());
    int len7 = removeDuplicatesK(arr7, k);
    cout << "After removing duplicates (length = " << len7 << "): ";
    printArray(arr7, len7);
    
    vector<int> arr8 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << "\nAnother Test Case:" << endl;
    cout << "Original: ";
    printArray(arr8, arr8.size());
    int len8 = removeDuplicatesOptimal(arr8);
    cout << "After removing all duplicates (length = " << len8 << "): ";
    printArray(arr8, len8);
    
    return 0;
}
