#include <iostream>
#include <fstream>

using namespace std;

class Rectangle
{
private:
    int weigth;
    int hight;
public:
    Rectangle();
    ~Rectangle();
    int getHight();
    int getWeigth();
    float getSquare();
    void setData(int, int);
    void print();
};
//функция вывода. почему отдельно? потому что содержит массив объектов класса
void MyPrint(Rectangle* arr, int n, int max);
/*
{
    for i in range(len(arr)):
        arr[i].print(); //cout<<arr[i].getHight<<arr[i].
};//печать весь массив эл*/
