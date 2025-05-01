#include <iostream>
#include "class.h"
#include <string>

int main(int argv, char* argc[]){
    int max_square = atoi(argc[2]);//atoi-перевод массива символов в числовой тип
    std::string rectangle;
    int c_wigth, c_hight;

    ifstream fin(argc[1]);
    if (!fin.is_open()){
        cout << "File hadn't been opened!" << endl;
        system("pause");
    }

    int n = 0;
    fin >> n;
    Rectangle* arr = new Rectangle[n];//массив объектов класса через дин память
    for (int i = 0; i < n; ++i){
        fin >> c_hight;
        fin >> c_wigth;
        arr[i].setData(c_hight, c_wigth);
    }
    fin.close();
    MyPrint(arr, n, max_square);
    delete[] arr;
    return 0;
}