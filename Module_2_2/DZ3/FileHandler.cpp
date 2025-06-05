#include "FileHandler.h"
#include <sstream>
#include <stdexcept>

Graph FileHandler::readGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }
    
    bool isDirected;
    file >> isDirected;
    
    int vertexCount;
    file >> vertexCount;
    
    std::vector<std::vector<int>> matrix(vertexCount, std::vector<int>(vertexCount, 0));
    
    for (int i = 0; i < vertexCount; ++i) {
        for (int j = 0; j < vertexCount; ++j) {
            if (!(file >> matrix[i][j])) {
                throw std::runtime_error("Ошибка чтения данных из файла");
            }
        }
    }
    
    return Graph(matrix, isDirected);
}

void FileHandler::writeGraphToFile(const std::string& filename, const Graph& graph) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось создать файл: " + filename);
    }
    
    file << graph.getIsDirected() << "\n";
    file << graph.getVertexCount() << "\n";
    
    // Для простоты будем сохранять всю матрицу смежности
    for (int i = 0; i < graph.getVertexCount(); ++i) {
        for (int j = 0; j < graph.getVertexCount(); ++j) {
            file << (graph.hasEdge(i, j) ? "1 " : "0 ");
        }
        file << "\n";
    }
}