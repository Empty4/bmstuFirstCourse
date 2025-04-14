#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

class Rectangle {
private:
    int weigth;
    int hight;
public:
    Rectangle();
    ~Rectangle();
    void setData(int, int);
    int getWeigth();
    int getHight();
    float getSquare();
};


void MyPrint(Rectangle* arr, int n, int max);