#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vector {
    double *p;
    unsigned int n;
public:
    Vector();
    ~Vector();
    Vector(unsigned int n);

    Vector(const Vector& V); //Копирование
    Vector(Vector&& V); //Перемещение

    double& operator[](unsigned int index); // Доступ к элементу
    Vector& operator=(const Vector& V); // Присваивание копированием
    Vector& operator=(Vector&& V); // Присваивание перемещением

    friend std::ostream& operator<<(std::ostream& out, const Vector& V);
    friend std::istream& operator>>(std::istream& in, Vector& V);

    //Vector operator+(const double* arr);

    friend Vector operator+(const double* arr, Vector& V);

};

#endif