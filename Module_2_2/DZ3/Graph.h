#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <stdexcept>

class Graph {
private:
    bool isDirected; // Флаг ориентированности графа
    std::vector<std::vector<int>> adjacencyMatrix; // Матрица смежности
    
    // Вспомогательная функция для поиска циклов (DFS)
    void dfsFindCycles(int vertex, std::vector<bool>& visited, 
                      std::vector<int>& path, std::vector<std::vector<int>>& allCycles);
    
public:
    // Конструкторы
    Graph(bool directed = false); // Конструктор по умолчанию
    Graph(const std::vector<std::vector<int>>& matrix, bool directed); // Конструктор с матрицей
    Graph(const Graph& other); // Конструктор копирования
    Graph(Graph&& other) noexcept; // Конструктор перемещения
    
    // Операторы
    Graph& operator=(const Graph& other); // Оператор присваивания
    Graph& operator=(Graph&& other) noexcept; // Оператор перемещающего присваивания
    Graph operator+(const Graph& other) const; // Объединение графов
    
    // Основные методы
    void addVertex(); // Добавление вершины
    void removeVertex(int vertex); // Удаление вершины
    void addEdge(int from, int to, int weight = 1); // Добавление ребра
    void removeEdge(int from, int to); // Удаление ребра
    bool hasEdge(int from, int to) const; // Проверка наличия ребра
    
    // Поиск циклов
    std::vector<std::vector<int>> findAllCycles(); // Найти все циклы
    std::vector<int> findLongestCycle(); // Найти самый длинный цикл
    
    // Геттеры
    int getVertexCount() const; // Количество вершин
    bool getIsDirected() const; // Проверка ориентированности
    
    // Ввод/вывод
    void print() const; // Печать графа
};

#endif // GRAPH_H