#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "Graph.h"
#include <string>
#include <fstream>

class FileHandler {
public:
    static Graph readGraphFromFile(const std::string& filename);
    static void writeGraphToFile(const std::string& filename, const Graph& graph);
};

#endif // FILE_HANDLER_H
