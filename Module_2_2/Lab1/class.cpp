#include <iostream>
#include "class.h"

using namespace std;

Rectangle::Rectangle(){
    weigth = 0;
    hight = 0;
}
Rectangle::~Rectangle(){}
int Rectangle::getHight(){
    return hight;
}
int Rectangle::getWeigth(){
    return weigth;
}
float Rectangle::getSquare(){
    return weigth*hight;
}
void Rectangle::setData(int weigth, int hight){
    this->hight = hight;
    this->weigth = weigth;
}

void MyPrint(Rectangle* arr, int n, int max){
    //работа с файлами?
    ofstream file("test_res.txt");
    for (int i = 0; i < n; ++i)
    {
        cout << "Rectangle " << i + 1 << "\nHight: " << arr[i].getHight() << "\nWeigth: " << arr[i].getWeigth() << "\nSquare: " << arr[i].getSquare() << "\n";
        file << "Rectangle " << i + 1 << "\nHight: " << arr[i].getHight() << "\nWeigth: " << arr[i].getWeigth() << "\nSquare: " << arr[i].getSquare() << "\n";
    }
    cout << "\nSquare >= max\n\n"; file << "\nSquare >= max\n\n";
    for (int i = 0; i < n; ++i) {
        if (arr[i].getSquare() >= max) {
            cout << "Rectangle " << i + 1 << "\nSquare: " << arr[i].getSquare() << "\n";
            file << "Rectangle " << i + 1 << "\nSquare: " << arr[i].getSquare() << "\n";
        }
    }
    file.close();
}
