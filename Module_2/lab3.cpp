#include <iostream>
#include <cmath>

using namespace std;

// Базовый класс "Вещественное число"
class RealNumber {
protected:
    double value;

public:
    RealNumber(double val = 0.0) : value(val) {}

    double getModule() const {
        return abs(value);
    }

    void print() const {
        cout << "Вещественное число: " << value << endl;
        cout << "Модуль: " << getModule() << endl;
    }
};

// Производный класс "Комплексное число"
class ComplexNumber : public RealNumber {
protected:
    double imaginary;

public:
    ComplexNumber(double real = 0.0, double imag = 0.0) : RealNumber(real), imaginary(imag) {}

    double getModule() const override { // Переопределенная функция
        return sqrt(value * value + imaginary * imaginary);
    }

    void print() const override { // Переопределенная функция
        cout << "Комплексное число: " << value << " + " << imaginary << "i" << endl;
        cout << "Модуль: " << getModule() << endl;
    }
};

int main() {
    // Создание объектов
    RealNumber realNum(5.0);
    ComplexNumber complexNum(3.0, 4.0);

    // Статический полиморфизм
    cout << "Статический полиморфизм:" << endl;
    realNum.print();
    complexNum.print();

    // Динамический полиморфизм
    cout << "\nДинамический полиморфизм:" << endl;
    RealNumber ptr = &complexNum; // Указатель на базовый класс, но объект производного
    ptr->print(); // Вызов функции из производного класса

    return 0;
}