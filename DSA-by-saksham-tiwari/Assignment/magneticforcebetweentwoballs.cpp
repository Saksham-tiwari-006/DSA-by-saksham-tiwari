#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceBalls(vector<int>& position, int m, int minDist) {
    int count = 1;
    int lastPosition = position[0];
    
    for (int i = 1; i < position.size(); i++) {
        if (position[i] - lastPosition >= minDist) {
            count++;
            lastPosition = position[i];
            if (count >= m) {
                return true;
            }
        }
    }
    
    return false;
}

int maxDistanceBruteForce(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    
    int n = position.size();
    int maxDist = 0;
    
    for (int dist = 1; dist <= position[n-1] - position[0]; dist++) {
        if (canPlaceBalls(position, m, dist)) {
            maxDist = dist;
        }
    }
    
    return maxDist;
}

int maxDistanceBetter(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    
    int n = position.size();
    int low = 1;
    int high = position[n-1] - position[0];
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlaceBalls(position, m, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

int maxDistanceOptimal(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    
    int n = position.size();
    int low = 1;
    int high = position[n-1] - position[0];
    
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        
        if (canPlaceBalls(position, m, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    return low;
}

bool canPlaceWithLinearSearch(vector<int>& position, int m, int minDist) {
    int count = 1;
    int lastPosition = position[0];
    
    for (int i = 1; i < position.size(); i++) {
        if (position[i] - lastPosition >= minDist) {
            count++;
            lastPosition = position[i];
        }
    }
    
    return count >= m;
}

int maxDistanceGreedy(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    
    int n = position.size();
    int low = 1;
    int high = position[n-1] - position[0];
    int answer = 0;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (canPlaceWithLinearSearch(position, m, mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return answer;
}

void printVector(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    cout << "=== MAGNETIC FORCE BETWEEN TWO BALLS ===" << endl;
    
    vector<int> position1 = {1, 2, 3, 4, 7};
    int m1 = 3;
    cout << "\nTest Case 1:" << endl;
    cout << "Position: ";
    printVector(position1);
    cout << "Number of balls (m): " << m1 << endl;
    
    vector<int> temp1 = position1;
    cout << "Brute Force: " << maxDistanceBruteForce(temp1, m1) << endl;
    
    vector<int> temp2 = position1;
    cout << "Better Approach (Binary Search): " << maxDistanceBetter(temp2, m1) << endl;
    
    vector<int> temp3 = position1;
    cout << "Optimal Approach: " << maxDistanceOptimal(temp3, m1) << endl;
    
    vector<int> position2 = {5, 4, 3, 2, 1, 1000000000};
    int m2 = 2;
    cout << "\nTest Case 2:" << endl;
    cout << "Position: ";
    printVector(position2);
    cout << "Number of balls (m): " << m2 << endl;
    
    vector<int> temp4 = position2;
    cout << "Better Approach (Binary Search): " << maxDistanceBetter(temp4, m2) << endl;
    
    vector<int> temp5 = position2;
    cout << "Optimal Approach: " << maxDistanceOptimal(temp5, m2) << endl;
    
    vector<int> position3 = {1, 2, 8, 4, 9};
    int m3 = 3;
    cout << "\nTest Case 3:" << endl;
    cout << "Position: ";
    printVector(position3);
    cout << "Number of balls (m): " << m3 << endl;
    
    vector<int> temp6 = position3;
    cout << "Brute Force: " << maxDistanceBruteForce(temp6, m3) << endl;
    
    vector<int> temp7 = position3;
    cout << "Better Approach (Binary Search): " << maxDistanceBetter(temp7, m3) << endl;
    
    vector<int> temp8 = position3;
    cout << "Optimal Approach: " << maxDistanceOptimal(temp8, m3) << endl;
    
    vector<int> temp9 = position3;
    cout << "Greedy Binary Search: " << maxDistanceGreedy(temp9, m3) << endl;
    
    return 0;
}
