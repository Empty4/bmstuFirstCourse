#include <iostream>
#include <fstream>
#include <vector>
#include "vector1.h" 

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

void MyPrint(std::vector<Rectangle>& arr, int max) {
    std::ofstream fout("res.txt");
    
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "Rectangle " << i + 1 << "\nHight: " << arr[i].getHight() << "\nWeigth: " << arr[i].getWeigth() << "\nSquare: " << arr[i].getSquare() << "\n";
        fout << "Rectangle " << i + 1 << "\nHight: " << arr[i].getHight()<< "\nWeigth: " << arr[i].getWeigth()<< "\nSquare: " << arr[i].getSquare() << "\n";
    }
    std::cout << "\nSquare >= max\n\n"; 
    fout << "\nSquare >= max\n\n"; 

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i].getSquare() >= max) {
            std::cout << "Rectangle " << i + 1 << "\nSquare: " << arr[i].getSquare() << "\n";
            fout << "Rectangle " << i + 1 << "\nSquare: " << arr[i].getSquare() << "\n";
        }
    }

    fout.close();
}