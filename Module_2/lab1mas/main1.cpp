#include "class.h"


int main(int argv, char* argc[]) 
{
    int max_square = atoi(argc[2]);//atoi-перевод массива символов в числовой тип
    std::string rectangle;
    int c_wigth, c_hight;
    std::ifstream fin(argc[1]);
    if (!fin.is_open()) 
    {
        std::cout << "\nError, file doesn`t exist\n"; system("pause");
        return 1;
    }
    int n = 0;
    fin >> n;
    Rectangle* arr = new Rectangle[n];
    for (int i = 0; i < n; ++i) {
        fin >> c_hight;
        fin >> c_wigth; 
        arr[i].setData(c_hight, c_wigth);
    }
    fin.close();
    MyPrint(arr, n, max_square);
    delete[] arr;
    return 0;
}