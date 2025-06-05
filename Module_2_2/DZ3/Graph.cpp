#include "Graph.h"
#include <algorithm>
#include <iostream>

// Конструктор по умолчанию
Graph::Graph(bool directed) : isDirected(directed) {
    adjacencyMatrix = {}; // Инициализация пустой матрицы
}

// Конструктор с матрицей смежности
Graph::Graph(const std::vector<std::vector<int>>& matrix, bool directed) 
    : isDirected(directed), adjacencyMatrix(matrix) {
    // Проверка корректности матрицы
    for (const auto& row : adjacencyMatrix) {
        if (row.size() != adjacencyMatrix.size()) {
            throw std::invalid_argument("Матрица смежности должна быть квадратной");
        }
    }
}

// Конструктор копирования
Graph::Graph(const Graph& other) 
    : isDirected(other.isDirected), adjacencyMatrix(other.adjacencyMatrix) {}

// Конструктор перемещения
Graph::Graph(Graph&& other) noexcept 
    : isDirected(other.isDirected), adjacencyMatrix(std::move(other.adjacencyMatrix)) {
    other.isDirected = false;
}

// Оператор присваивания
Graph& Graph::operator=(const Graph& other) {
    if (this != &other) {
        isDirected = other.isDirected;
        adjacencyMatrix = other.adjacencyMatrix;
    }
    return *this;
}

// Оператор перемещающего присваивания
Graph& Graph::operator=(Graph&& other) noexcept {
    if (this != &other) {
        isDirected = other.isDirected;
        adjacencyMatrix = std::move(other.adjacencyMatrix);
        other.isDirected = false;
    }
    return *this;
}

Graph Graph::operator+(const Graph& other) const { //не изм текущ obj
    if (isDirected != other.isDirected) {
        throw std::invalid_argument("Графы должны быть одного типа (ориентированные/неориентированные)");
    }
    
    size_t maxSize = std::max(adjacencyMatrix.size(), other.adjacencyMatrix.size());
    std::vector<std::vector<int>> newMatrix(maxSize, std::vector<int>(maxSize, 0));
    
    // Копируем данные из первого графа
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            newMatrix[i][j] = adjacencyMatrix[i][j];
        }
    }
    
    // Добавляем данные из второго графа
    for (size_t i = 0; i < other.adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < other.adjacencyMatrix[i].size(); ++j) {
            if (other.adjacencyMatrix[i][j] != 0) {
                newMatrix[i][j] = other.adjacencyMatrix[i][j];
            }
        }
    }
    
    return Graph(newMatrix, isDirected);
}

// Добавление вершины
void Graph::addVertex() {
    for (auto& row : adjacencyMatrix) {
        row.push_back(0); // Добавляем столбец в каждую строку
    }
    adjacencyMatrix.push_back(std::vector<int>(adjacencyMatrix.size() + 1, 0)); // Добавляем новую строку
}

// Удаление вершины
void Graph::removeVertex(int vertex) {
    if (vertex < 0 || vertex >= adjacencyMatrix.size()) {
        throw std::out_of_range("Неверный индекс вершины");
    }
    
    adjacencyMatrix.erase(adjacencyMatrix.begin() + vertex); // Удаляем строку
    for (auto& row : adjacencyMatrix) {
        row.erase(row.begin() + vertex); // Удаляем столбец из каждой строки
    }
}

// Добавление ребра
void Graph::addEdge(int from, int to, int weight) {
    if (from < 0 || from >= adjacencyMatrix.size() || 
        to < 0 || to >= adjacencyMatrix.size()) {
        throw std::out_of_range("Неверные индексы вершин");
    }
    
    adjacencyMatrix[from][to] = weight;
    if (!isDirected) {
        adjacencyMatrix[to][from] = weight; // Для неориентированного графа
    }
}

// Удаление ребра
void Graph::removeEdge(int from, int to) {
    if (from < 0 || from >= adjacencyMatrix.size() || 
        to < 0 || to >= adjacencyMatrix.size()) {
        throw std::out_of_range("Неверные индексы вершин");
    }
    
    adjacencyMatrix[from][to] = 0;
    if (!isDirected) {
        adjacencyMatrix[to][from] = 0;
    }
}

// Проверка наличия ребра
bool Graph::hasEdge(int from, int to) const {
    if (from < 0 || from >= adjacencyMatrix.size() || 
        to < 0 || to >= adjacencyMatrix.size()) {
        throw std::out_of_range("Неверные индексы вершин");
    }
    
    return adjacencyMatrix[from][to] != 0;
}

// Поиск всех циклов (DFS)
void Graph::dfsFindCycles(int vertex, std::vector<bool>& visited, 
                         std::vector<int>& path, std::vector<std::vector<int>>& allCycles) {
    visited[vertex] = true;
    path.push_back(vertex);
    
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[vertex][i] != 0) { // Есть ребро
            if (!visited[i]) {
                dfsFindCycles(i, visited, path, allCycles);
            } else {
                // Проверяем, является ли это циклом
                auto it = std::find(path.begin(), path.end(), i);
                if (it != path.end()) {
                    // Формируем цикл
                    std::vector<int> cycle(it, path.end());
                    allCycles.push_back(cycle);
                }
            }
        }
    }
    
    path.pop_back();
    visited[vertex] = false;
}

// Найти все циклы
std::vector<std::vector<int>> Graph::findAllCycles() {
    std::vector<bool> visited(adjacencyMatrix.size(), false);
    std::vector<int> path;
    std::vector<std::vector<int>> allCycles;
    
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        if (!visited[i]) {
            dfsFindCycles(i, visited, path, allCycles);
        }
    }
    
    return allCycles;
}

// Найти самый длинный цикл
std::vector<int> Graph::findLongestCycle() {
    auto allCycles = findAllCycles();
    if (allCycles.empty()) {
        return {};
    }
    
    auto longest = allCycles[0];
    for (const auto& cycle : allCycles) {
        if (cycle.size() > longest.size()) {
            longest = cycle;
        }
    }
    
    return longest;
}

// Количество вершин
int Graph::getVertexCount() const {
    return adjacencyMatrix.size();
}

// Проверка ориентированности
bool Graph::getIsDirected() const {
    return isDirected;
}

// Печать графа
void Graph::print() const {
    std::cout << (isDirected ? "Ориентированный" : "Неориентированный") 
              << " граф с " << adjacencyMatrix.size() << " вершинами:\n";
    
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}
