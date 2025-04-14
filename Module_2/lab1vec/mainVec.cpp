#include "vector1.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // Для atoi

using namespace std;

int main(int argv, char* argc[]) 
{
    int max_square = atoi(argc[2]);
    string rectangle;
    int c_wigth, c_hight;
    ifstream fin(argc[1]);
    if (!fin.is_open()) 
    {
        cout << "\nError, file doesn`t exist\n"; 
        system("pause"); // Ожидание ввода
        return 1;
    }

    int n = 0;
    fin >> n;
    vector<Rectangle> arr(n); // Создание вектора вместо массива
    for (int i = 0; i < n; ++i) {
        fin >> c_hight;
        fin >> c_wigth; 
        arr[i].setData(c_hight, c_wigth);
    }

    fin.close();
    MyPrint(arr, max_square);

    // Не нужно удалять вектор, память автоматически освобождается
    return 0;
}