#include <iostream>
#include <thread>
#include <chrono>
#include <random>

using namespace std;

// Функция для потока умножения
void multiplicationThread(const string& threadName, int n, double arr1, double arr2) {
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(0.0, 10.0);

    for (int i = 0; i < n; i++) {
        this_thread::sleep_for(chrono::milliseconds(10)); // Задержка
        cout << threadName << endl;
        cout << arr1[i] << "  " << arr2[i] << " = " << arr1[i]  arr2[i] << endl;
    }
}

// Функция для потока сложения
void additionThread(const string& threadName, int n, double arr1, double arr2) {
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(0.0, 10.0);

    for (int i = 0; i < n; i++) {
        this_thread::sleep_for(chrono::milliseconds(10)); // Задержка
        cout << threadName << endl;
        cout << arr1[i] << " + " << arr2[i] << " = " << arr1[i] + arr2[i] << endl;
    }
}

// Функция для потока ГПСЧ
void randomThread(const string& threadName, int n) {
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(0.0, 10.0);

    for (int i = 0; i < n; i++) {
        this_thread::sleep_for(chrono::milliseconds(10)); // Задержка
        cout << threadName << endl;
        cout << distribution(generator) << endl;
    }
}

int main() {
    // Задание констант или ввод с клавиатуры
    int n1 = 25;
    int n2 = 20;
    int n3 = 30;

    // Создание массивов для вещественных чисел
    double arr1 = new double[max(n1, n2)];
    double arr2 = new double[max(n1, n2)];

    // Заполнение массивов значениями ГПСЧ
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(0.0, 10.0);
    for (int i = 0; i < max(n1, n2); i++) {
        arr1[i] = distribution(generator);
        arr2[i] = distribution(generator);
    }

    // Создание и запуск потоков
    thread thread1(multiplicationThread, "thread1", n1, arr1, arr2);
    thread thread2(additionThread, "thread2", n2, arr1, arr2);
    thread thread3(randomThread, "thread3", n3);

    // Ожидание завершения дочерних потоков
    thread1.join();
    thread2.join();
    thread3.join();

    // Вывод сообщения об окончании работы
    cout << "Все потоки завершили работу." << endl;

    // Освобождение памяти
    delete[] arr1;
    delete[] arr2;

    return 0;
}