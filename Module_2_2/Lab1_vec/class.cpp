#include <iostream>
#include <fstream>
#include <vector>
#include "classV.h" 

Ractangle::Ractangle() {
    weigth = 0;
    hight = 0;
}
Ractangle::~Ractangle() {}
void Ractangle::setData(int weigth, int hight) {
    this->weigth = weigth;
    this->hight = hight;
}
int Ractangle::getWeigth() {
    return weigth;
}
int Ractangle::getHight() {
    return hight;
}
float Ractangle::getSquare() {
    float square = hight * weigth;
    return square;
}

void MyPrint(std::vector<Ractangle>& arr, int max) {
    std::ofstream fout("test_v_res.txt");
    
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "Ractangle " << i + 1 << "\nHight: " << arr[i].getHight() << "\nWeigth: " << arr[i].getWeigth() << "\nSquare: " << arr[i].getSquare() << "\n";
        fout << "Ractangle " << i + 1 << "\nHight: " << arr[i].getHight()<< "\nWeigth: " << arr[i].getWeigth()<< "\nSquare: " << arr[i].getSquare() << "\n";
    }
    std::cout << "\nSquare >= max\n\n"; 
    fout << "\nSquare >= max\n\n"; 

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i].getSquare() >= max) {
            std::cout << "Ractangle " << i + 1 << "\nSquare: " << arr[i].getSquare() << "\n";
            fout << "Ractangle " << i + 1 << "\nSquare: " << arr[i].getSquare() << "\n";
        }
    }

    fout.close();
}