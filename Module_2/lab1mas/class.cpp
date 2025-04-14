#include <iostream>
#include "class.h"

Rectangle::Rectangle() {
    weigth = 0;
    hight = 0;
}
Rectangle::~Rectangle() {}
void Rectangle::setData(int weigth, int hight) {
    this->weigth = weigth;
    this->hight = hight;
}
int Rectangle::getWeigth() {
    return weigth;
}
int Rectangle::getHight() {
    return hight;
}
float Rectangle::getSquare() {
    float square = hight * weigth;
    return square;
}

void MyPrint(Rectangle* arr, int n, int max)
{
    std::ofstream fout("res.txt");
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Rectangle " << i + 1 << "\nHight: " << arr[i].getHight() << "\nWeigth: " << arr[i].getWeigth() << "\nSquare: " << arr[i].getSquare() << "\n";
        fout << "Rectangle " << i + 1 << "\nHight: " << arr[i].getHight() << "\nWeigth: " << arr[i].getWeigth() << "\nSquare: " << arr[i].getSquare() << "\n";
    }
    std::cout << "\nSquare >= max\n\n"; fout << "\nSquare >= max\n\n";
    for (int i = 0; i < n; ++i) {
        if (arr[i].getSquare() >= max) {
            std::cout << "Rectangle " << i + 1 << "\nSquare: " << arr[i].getSquare() << "\n";
            fout << "Rectangle " << i + 1 << "\nSquare: " << arr[i].getSquare() << "\n";
        }
    }
    fout.close();
}