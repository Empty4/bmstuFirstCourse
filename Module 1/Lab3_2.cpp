
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

int main(){//ранд+, динам/стат, STL/без
    int n;
    int m;
    srand(time(NULL));
    cout << "Count of strok: ";
    cin >> n;
    cout << "Count of stolbzov: ";
    cin >> m;
    float* mas_sr_znach = new float[n];
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[m];
    for (int i = 0; i<n; i++){
        float sum = 0;
        for (int j = 0; j<m; j++){
            cout << "El mass[" << i << "][" << j << "]: "; //i=n j=m
            matrix[i][j] = rand()%100;
            cout << matrix[i][j] << endl;
            sum += matrix[i][j];
        }
        mas_sr_znach[i] = sum/m;
    }
    for (int i = 0; i<n; i++){
        cout << "This is average value of the " << i << "string: ";
        cout << mas_sr_znach[i] << endl;
    }
    delete[] mas_sr_znach;
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}