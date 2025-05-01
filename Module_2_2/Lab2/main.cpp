#include "vector2.h"
#include <fstream>
#include <iostream>

int main() {
    std::ifstream inputfile("input.txt");
    if (!inputfile) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    unsigned int arr_size;
    inputfile >> arr_size;
    double* arr = new double[arr_size];
    for (unsigned int i = 0; i < arr_size; i++) 
        inputfile >> arr[i];

    Vector v2;
    inputfile >> v2;
    inputfile.close();

    Vector result = arr + v2; //нужно arr + v2

    std::ofstream outputfile("output.txt");
    if (outputfile) {
        outputfile << "Array: ";
        for (unsigned int i = 0; i < arr_size; i++) 
            outputfile << arr[i] << " ";
        
        outputfile << "\nVector: " << v2 << std::endl;
        outputfile << "Result (Array + Vector): " << result << std::endl;
    } else {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }

    delete[] arr;
    outputfile.close();

    return 0;
}