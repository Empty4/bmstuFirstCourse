#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

class Ractangle {
private:
    int weigth;
    int hight;
public:
    Ractangle();
    ~Ractangle();
    void setData(int, int);
    int getWeigth();
    int getHight();
    float getSquare();
};


//void MyPrint(Ractangle* arr, int n, int max);
void MyPrint(std::vector<Ractangle>& arr, int max);