#include <iostream>

using namespace std;

void reverseRow(char* row, int start, int end) {
    if (start >= end)
        return;
    
    swap(row[start], row[end]);
    reverseRow(row, start + 1, end - 1);
}

void reverseMatrix(char** matrix, int n, int m, int row) {
    if (row >= n)
        return;
    
    reverseRow(matrix[row], 0, m - 1);
    reverseMatrix(matrix, n, m, row + 2);
}

void revers(char** matrix, int n, int m) {
    reverseMatrix(matrix, n, m, 0);
}

/*
void revers(char** matrix, int n, int m){
    //cout << matrix[0][1];
    for (int i = 0; i < n; i+=2) {
        int start = 0;
        int end = m - 1;
        while (start < end) {
            swap(matrix[i][start], matrix[i][end]);
            start += 1;
            end -= 1;   
        }
    }
}
*/