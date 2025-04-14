#include <iostream>
#include <stdexcept>

using namespace std;

// Класс для исключения, производный от invalid_argument
class InvalidGeometricProgressionException : public invalid_argument {
public:
    // Конструктор
    InvalidGeometricProgressionException(const char msg, const GeometricProgression& invalidProg)
        : invalid_argument(msg), invalidProgression(invalidProg) {}

    // Метод для печати всех данных недопустимого объекта
    void printInvalidProgressionData() const {
        cerr << "Недопустимая геометрическая прогрессия:" << endl;
        cerr << "Первый элемент: " << invalidProgression.firstElement << endl;
        cerr << "Знаменатель: " << invalidProgression.commonRatio << endl;
        cerr << "Массив:" << endl;
        for (int i = 0; i < invalidProgression.size; i++) {
            cerr << invalidProgression.array[i] << " ";
        }
        cerr << endl;
    }

private:
    GeometricProgression invalidProgression;
};

// Класс "Массив - геометрическая прогрессия"
class GeometricProgression {
public:
    // Конструктор для инициализации полей
    GeometricProgression(double firstElement, double commonRatio, double array, int size)
        : firstElement(firstElement), commonRatio(commonRatio), size(size) {
        // Проверка, является ли массив геометрической прогрессией
        if (!isValidGeometricProgression(array, size)) {
            throw InvalidGeometricProgressionException("Массив не является геометрической прогрессией", this);
        }
        // Выделение памяти для массива
        this->array = new double[size];
        // Копирование элементов из переданного массива
        for (int i = 0; i < size; i++) {
            this->array[i] = array[i];
        }
    }

    // Деструктор
    ~GeometricProgression() {
        delete[] array;
    }

    // Метод для проверки, является ли массив геометрической прогрессией
    bool isValidGeometricProgression(const double array, int size) const {
        if (size < 2) {
            return false; // Недостаточно элементов для проверки
        }
        double ratio = array[1] / array[0];
        for (int i = 2; i < size; i++) {
            if (array[i] / array[i - 1] != ratio) {
                return false; // Неверный знаменатель
            }
        }
        return true; // Массив - геометрическая прогрессия
    }

    // Методы доступа
    double getFirstElement() const {
        return firstElement;
    }

    double getCommonRatio() const {
        return commonRatio;
    }

    int getSize() const {
        return size;
    }

    // Метод для получения элемента по индексу
    double getElement(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Индекс вне допустимого диапазона");
        }
        return array[index];
    }

    // Перегрузка оператора << для вывода информации о прогрессии
    friend ostream& operator<<(ostream& os, const GeometricProgression& prog) {
        os << "Первый элемент: " << prog.firstElement << endl;
        os << "Знаменатель: " << prog.commonRatio << endl;
        os << "Массив: " << endl;
        for (int i = 0; i < prog.size; i++) {
            os << prog.array[i] << " ";
        }
        os << endl;
        return os;
    }

private:
    double firstElement;
    double commonRatio;
    double array;
    int size;
};

int main() {
    // Пример работы с объектом без исключения
    cout << "Пример без исключения:" << endl;
    double arr1[] = {1, 2, 4, 8, 16};
    GeometricProgression gp1(1, 2, arr1, 5);
    cout << gp1 << endl;

    // Пример работы с объектом с возникновением исключения
    cout << "Пример с исключением:" << endl;
    double arr2[] = {1, 2, 4, 7, 16}; // Не является геометрической прогрессией
    try {
        GeometricProgression gp2(1, 2, arr2, 5);
        cout << gp2 << endl; //