#include <iostream>
#include <fstream>
#include <deque>
#include <list>
#include <algorithm>
#include "class.h"
#include "file.h"

int main() {
    try {
        // 1. Создаем контейнер deque и читаем данные из файла
        std::deque<Employee> employees;
        readEmployeesFromFile("input.txt", employees);

        // 2. Открываем выходной файл
        std::ofstream outFile("output.txt");
        if (!outFile) {
            throw std::runtime_error("Cannot open output file: output.txt");
        }

        // 3. Выводим исходный контейнер
        writeContainerToFile(outFile, employees, "Исходный контейнер (deque)");

        // 4. Сортируем контейнер по ФИО с помощью std::sort
        std::sort(employees.begin(), employees.end());

        // 5. Выводим отсортированный контейнер
        writeContainerToFile(outFile, employees, "Отсортированный контейнер (deque)");

        // 6. Копируем deque в list с помощью std::copy
        std::list<Employee> employeeList;
        std::copy(employees.begin(), employees.end(), std::back_inserter(employeeList));

        // 7. Выводим скопированный контейнер (list)
        writeContainerToFile(outFile, employeeList, "Скопированный контейнер (list)");

        std::cout << "Программа успешно выполнена. Результаты записаны в output.txt\n";
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}