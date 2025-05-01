#include <fstream> 
#include <sstream> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm>
class Vector {
protected:
    int n;
    int* ptr; 
public:
    Vector(); 
    Vector(int, int*); 
    Vector(Vector &); 
    Vector(Vector &&); 
    ~Vector();
    int get_size(); 
    int* get_ptr();
    int operator[](int);
    Vector operator=(const Vector&);
    Vector operator=(Vector&&);
    friend Vector operator^(Vector&, Vector&);
    friend std::istream& operator>>(std::istream&, Vector&);
    Vector& operator++();
    Vector operator++(int); 
};
bool findValue(const std::vector<int>&, int); 
std::ostream& operator<<(std::ostream&, Vector&);

/*
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    int data;
    int size;

public:
    // Конструктор без параметров
    Vector();

    // Конструктор из массива
    Vector(const int arr, int n);

    // Конструктор копирования
    Vector(const Vector& other);

    // Конструктор перемещения
    Vector(Vector&& other) noexcept;

    // Деструктор
    ~Vector();

    // Перегрузка операции постфиксного декремента
    Vector operator--(int);

    // Операция присваивания с копированием
    Vector& operator=(const Vector& other);

    // Операция присваивания с перемещением
    Vector& operator=(Vector&& other) noexcept;

    // Метод для вывода вектора
    void print() const;
};

#endif // VECTOR_H
*/