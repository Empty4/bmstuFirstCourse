#include <iostream>
#include "revers.h"

using namespace std;

//void revers();

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    
    //int n,m;
   /* cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >> m;*/

    char** matrix = new char*[n];
    for (int i = 0; i < n; ++i){
        matrix[i] = new char[m];//динамич
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    revers(matrix, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
