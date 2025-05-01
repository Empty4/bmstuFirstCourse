#include <iostream>
#include <fstream>
#include "Vector.h"

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    int n;
    input >> n;
    int arr;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        input >> arr[i];
    }

    // Создание вектора из массива
    Vector v1(arr, n);
    output << "Исходный вектор v1: ";
    v1.print();

    // Копирование вектора
    Vector v2 = v1;
    output << "Вектор v2, скопированный из v1: ";
    v2.print();

    // Перемещение вектора
    Vector v3 = std::move(v1);
    output << "Вектор v3, переместившийся из v1: ";
    v3.print();
    output << "Вектор v1 после перемещения: ";
    v1.print();

    // Присваивание с копированием
    v2 = v3;
    output << "Вектор v2 после присваивания с копированием из v3: ";
    v2.print();

    // Присваивание с перемещением
    v2 = std::move(v3);
    output << "Вектор v2 после присваивания с перемещением из v3: ";
    v2.print();
    output << "Вектор v3 после перемещения: ";
    v3.print();

    // Постфиксный декремент
    Vector v4 = v2--;
    output << "Вектор v4, декрементированный из v2: ";
}