#include <iostream>
#include <vector>
using namespace std;

void printMatrixInSnakePattern(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();
    
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            // Even row: print left to right
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
        } else {
            // Odd row: print right to left
            for (int j = cols - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int rows, cols;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nOriginal Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nMatrix in Snake Pattern: " << endl;
    printMatrixInSnakePattern(matrix);
    
    return 0;
}
