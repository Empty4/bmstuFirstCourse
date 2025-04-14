#include "vector2.h"
#include <iostream>
#include <fstream>

Vector::Vector() {
    p = nullptr;
    n = 0;
}

Vector::~Vector() {
    if (p != nullptr){
        delete[] p;
    }
    std::cout << "Destructor" << std::endl;
}

Vector::Vector(unsigned int n) {
    this->n = n;
    p = new double[n];
    for (unsigned int i = 0; i < n; i++){
        p[i] = 0;
    }
}

Vector::Vector(const Vector& V) {
    n = V.n;
    p = new double[n];
    for (unsigned int i = 0; i < n; i++){
        p[i] = V.p[i];
    }
    std::cout << "Constructor Copy" << std::endl;
}

Vector::Vector(Vector&& V) {
    n = V.n;
    p = V.p;
    V.n = 0;
    V.p = nullptr;
}

double& Vector::operator[](unsigned int index) {
    return p[index];
}

Vector& Vector::operator=(const Vector& V) {
    if (this != &V) {
        if (p != nullptr) delete[] p;
        n = V.n;
        p = new double[n];
        for (unsigned int i = 0; i < n; i++) p[i] = V.p[i];
    }
    std::cout << "operator= copy" << std::endl;
    return *this;
}

Vector& Vector::operator=(Vector&& V) {
    if (this != &V) {
        if (p != nullptr) delete[] p;
        n = V.n;
        p = V.p;
        V.n = 0;
        V.p = nullptr;
    }
    std::cout << "operator= move" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector& V) {
    if (V.p != nullptr) {
        for (unsigned int i = 0; i < V.n; i++) out << V.p[i] << " ";
    }
    else out << "Empty";
    return out;
}

std::istream& operator>>(std::istream& in, Vector& V) {
    in >> V.n;
    delete[] V.p;
    V.p = new double[V.n];
    for (unsigned int i = 0; i < V.n; i++){
        in >> V.p[i];
    }
    return in;
}

/*Vector Vector::operator+(const double* arr) {// перегруз опер как метод класса - первый оперант это объект класса
    Vector result(this->n + n); // Новый вектор размером arr_size + vector_size
    unsigned int i = 0;
    for (; i < n; i++){ 
        result.p[i] = arr[i]; // Копируем элементы из текущего вектора
    }
    
    for (unsigned int j = 0; j < this->n; j++){
        result.p[i + j] = p[j];//во вторую часть рез вектора добавляется эл с нуля
    }


    return result;
}*/

Vector operator+(const double* arr, Vector& V) {
    Vector result(V.n + V.n); // Новый вектор размером arr_size + vector_size = просто длинна вектора дважды
    unsigned int i = 0;
    for (; i < V.n; i++){ 
        result.p[i] = arr[i]; 
    }
    
    for (unsigned int j = 0; j < V.n; j++){
        result.p[i + j] = V.p[j];//во вторую часть рез вектора добавляется эл с нуля
    }

    return result;
}