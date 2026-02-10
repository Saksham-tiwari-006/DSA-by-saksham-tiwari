#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minSwapBruteForce(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }
    
    if (count == 0 || count == n) {
        return 0;
    }
    
    int minSwaps = INT_MAX;
    
    for (int i = 0; i <= n - count; i++) {
        int bad = 0;
        for (int j = i; j < i + count; j++) {
            if (arr[j] > k) {
                bad++;
            }
        }
        minSwaps = min(minSwaps, bad);
    }
    
    return minSwaps;
}

int minSwapBetter(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }
    
    if (count == 0 || count == n) {
        return 0;
    }
    
    int bad = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > k) {
            bad++;
        }
    }
    
    int minSwaps = bad;
    
    for (int i = count; i < n; i++) {
        if (arr[i - count] > k) {
            bad--;
        }
        if (arr[i] > k) {
            bad++;
        }
        minSwaps = min(minSwaps, bad);
    }
    
    return minSwaps;
}

int minSwapOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    int goodCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            goodCount++;
        }
    }
    
    if (goodCount == 0 || goodCount == n) {
        return 0;
    }
    
    int badCount = 0;
    for (int i = 0; i < goodCount; i++) {
        if (arr[i] > k) {
            badCount++;
        }
    }
    
    int minBad = badCount;
    int left = 0;
    int right = goodCount;
    
    while (right < n) {
        if (arr[left] > k) {
            badCount--;
        }
        if (arr[right] > k) {
            badCount++;
        }
        
        left++;
        right++;
        
        minBad = min(minBad, badCount);
    }
    
    return minBad;
}

int minSwapCircular(vector<int>& arr, int k) {
    int n = arr.size();
    int goodCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            goodCount++;
        }
    }
    
    if (goodCount == 0 || goodCount == n) {
        return 0;
    }
    
    vector<int> extended(arr.begin(), arr.end());
    extended.insert(extended.end(), arr.begin(), arr.end());
    
    int badCount = 0;
    for (int i = 0; i < goodCount; i++) {
        if (extended[i] > k) {
            badCount++;
        }
    }
    
    int minBad = badCount;
    
    for (int i = goodCount; i < n + goodCount; i++) {
        if (extended[i - goodCount] > k) {
            badCount--;
        }
        if (extended[i] > k) {
            badCount++;
        }
        minBad = min(minBad, badCount);
    }
    
    return minBad;
}

int minSwapToMakeKTogether(vector<int>& arr, int k) {
    int n = arr.size();
    int countK = 0;
    
    for (int num : arr) {
        if (num == k) {
            countK++;
        }
    }
    
    if (countK == 0 || countK == n) {
        return 0;
    }
    
    int maxKInWindow = 0;
    int currentK = 0;
    
    for (int i = 0; i < countK; i++) {
        if (arr[i] == k) {
            currentK++;
        }
    }
    maxKInWindow = currentK;
    
    for (int i = countK; i < n; i++) {
        if (arr[i - countK] == k) {
            currentK--;
        }
        if (arr[i] == k) {
            currentK++;
        }
        maxKInWindow = max(maxKInWindow, currentK);
    }
    
    return countK - maxKInWindow;
}

void printArray(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    cout << "=== MINIMUM SWAPS TO BRING ELEMENTS <= K TOGETHER ===" << endl;
    
    vector<int> arr1 = {2, 1, 5, 6, 3};
    int k1 = 3;
    cout << "\nTest Case 1:" << endl;
    cout << "Array: ";
    printArray(arr1);
    cout << "K = " << k1 << endl;
    cout << "Brute Force: " << minSwapBruteForce(arr1, k1) << " swaps" << endl;
    cout << "Better Approach: " << minSwapBetter(arr1, k1) << " swaps" << endl;
    cout << "Optimal Approach: " << minSwapOptimal(arr1, k1) << " swaps" << endl;
    
    vector<int> arr2 = {2, 7, 9, 5, 8, 7, 4};
    int k2 = 5;
    cout << "\nTest Case 2:" << endl;
    cout << "Array: ";
    printArray(arr2);
    cout << "K = " << k2 << endl;
    cout << "Brute Force: " << minSwapBruteForce(arr2, k2) << " swaps" << endl;
    cout << "Better Approach: " << minSwapBetter(arr2, k2) << " swaps" << endl;
    cout << "Optimal Approach: " << minSwapOptimal(arr2, k2) << " swaps" << endl;
    
    vector<int> arr3 = {1, 3, 5, 2, 4, 6};
    int k3 = 4;
    cout << "\nTest Case 3:" << endl;
    cout << "Array: ";
    printArray(arr3);
    cout << "K = " << k3 << endl;
    cout << "Brute Force: " << minSwapBruteForce(arr3, k3) << " swaps" << endl;
    cout << "Better Approach: " << minSwapBetter(arr3, k3) << " swaps" << endl;
    cout << "Optimal Approach: " << minSwapOptimal(arr3, k3) << " swaps" << endl;
    
    cout << "\n=== CIRCULAR ARRAY VARIATION ===" << endl;
    
    vector<int> arr4 = {10, 12, 20, 30, 25, 23, 32, 33, 19};
    int k4 = 20;
    cout << "\nCircular Array Test:" << endl;
    cout << "Array: ";
    printArray(arr4);
    cout << "K = " << k4 << endl;
    cout << "Circular Approach: " << minSwapCircular(arr4, k4) << " swaps" << endl;
    
    cout << "\n=== BRING ALL K VALUES TOGETHER ===" << endl;
    
    vector<int> arr5 = {1, 2, 3, 2, 1, 2, 3, 2};
    int k5 = 2;
    cout << "\nBring all " << k5 << "'s together:" << endl;
    cout << "Array: ";
    printArray(arr5);
    cout << "Minimum swaps: " << minSwapToMakeKTogether(arr5, k5) << " swaps" << endl;
    
    return 0;
}
