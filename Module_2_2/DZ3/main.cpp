#include <iostream>
#include <string>
#include "Graph.h"
#include "FileHandler.h"

void printMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Загрузить граф из файла\n";
    std::cout << "2. Сохранить граф в файл\n";
    std::cout << "3. Добавить вершину\n";
    std::cout << "4. Удалить вершину\n";
    std::cout << "5. Добавить ребро\n";
    std::cout << "6. Удалить ребро\n";
    std::cout << "7. Найти все циклы\n";
    std::cout << "8. Найти самый длинный цикл\n";
    std::cout << "9. Показать граф\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
}

int main() {
    Graph graph;
    std::string filename;
    int choice;
    
    try {
        do {
            printMenu();
            std::cin >> choice;
            
            switch (choice) {
                case 1: {
                    std::cout << "Введите имя файла: ";
                    std::cin >> filename;
                    graph = FileHandler::readGraphFromFile(filename);
                    std::cout << "Граф успешно загружен.\n";
                    graph.print();
                    break;
                }
                case 2: {
                    std::cout << "Введите имя файла: ";
                    std::cin >> filename;
                    FileHandler::writeGraphToFile(filename, graph);
                    std::cout << "Граф успешно сохранен.\n";
                    break;
                }
                case 3: {
                    graph.addVertex();
                    std::cout << "Вершина добавлена. Теперь вершин: " 
                              << graph.getVertexCount() << "\n";
                    break;
                }
                case 4: {
                    int vertex;
                    std::cout << "Введите номер вершины для удаления: ";
                    std::cin >> vertex;
                    graph.removeVertex(vertex);
                    std::cout << "Вершина удалена. Теперь вершин: " 
                              << graph.getVertexCount() << "\n";
                    break;
                }
                case 5: {
                    int from, to;
                    std::cout << "Введите начальную и конечную вершины: ";
                    std::cin >> from >> to;
                    graph.addEdge(from, to);
                    std::cout << "Ребро добавлено.\n";
                    break;
                }
                case 6: {
                    int from, to;
                    std::cout << "Введите начальную и конечную вершины: ";
                    std::cin >> from >> to;
                    graph.removeEdge(from, to);
                    std::cout << "Ребро удалено.\n";
                    break;
                }
                case 7: {
                    auto cycles = graph.findAllCycles();
                    if (cycles.empty()) {
                        std::cout << "Циклов не найдено.\n";
                    } else {
                        std::cout << "Найдено циклов: " << cycles.size() << "\n";
                        for (const auto& cycle : cycles) {
                            std::cout << "Цикл: ";
                            for (int v : cycle) {
                                std::cout << v << " ";
                            }
                            std::cout << "\n";
                        }
                    }
                    break;
                }
                case 8: {
                    auto longestCycle = graph.findLongestCycle();
                    if (longestCycle.empty()) {
                        std::cout << "Циклов не найдено.\n";
                    } else {
                        std::cout << "Самый длинный цикл (" << longestCycle.size() 
                                  << " вершин): ";
                        for (int v : longestCycle) {
                            std::cout << v << " ";
                        }
                        std::cout << "\n";
                    }
                    break;
                }
                case 9: {
                    graph.print();
                    break;
                }
                case 0: {
                    std::cout << "Выход...\n";
                    break;
                }
                default: {
                    std::cout << "Неверный выбор. Попробуйте снова.\n";
                }
            }
        } while (choice != 0);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}

