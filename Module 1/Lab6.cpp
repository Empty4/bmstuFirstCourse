#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//using namespace std;

struct ProgrammOfKriptograf{
    std::string nameRazrab;
    std::string vertion;
    std::string alg;
    std::string license;
};

int main(int argc, char* argv[]){
    int n;
    std::string wr = argv[1];
    std::string bt = argv[2]; 
    if (wr == "write" and bt == "text"){
        std::cout << "Please enter number of programm: ";
        std::cin >> n;
        std::ofstream file(argv[3], std::ios_base::app);
        if (file.is_open()){
            for (int i = 0; i < n; i++)
            {
                ProgrammOfKriptograf programm;
                std::cout << "Enter programm name: ";
                std::cin.ignore();
                std::getline(std::cin, programm.nameRazrab);
                std::cout << "Enter vertion of this programm: ";
                std::cin >> programm.vertion;
                std::cout << "Enter name of algoritm: ";
                std::cin.ignore();
                std::getline(std::cin, programm.alg);
                std::cout << "Do it have license? Yes/no: ";
                std::cin >> programm.license;
                file << programm.nameRazrab << " " << programm.vertion << " " << programm.alg << " " << programm.license << std::endl;
            }
            file.close();
        }
        else{
            std::cout << "Error" << std::endl;
        }
    }
    if (wr == "read" and bt == "text"){
        std::ifstream file(argv[3], std::ios_base::in);
        if (file.is_open()){
            std::string line;
            while (getline(file, line)){
                std::cout << line << std::endl;
            }
        }
        else{
            std::cout << "Error" << std::endl;
        }
    }
    if (wr == "write" && bt == "binary") {
        std::cout << "Please enter number of programm: ";
        std::cin >> n;
        std::vector<ProgrammOfKriptograf> prog(n);

        for (int i = 0; i < n; i++) {
            std::cout << "Enter name of razrab: ";

            std::cin.ignore();
            std::getline(std::cin, prog[i].nameRazrab);
            std::cout << "Enter vertion of this programm: ";
            std::cin >> prog[i].vertion;
            std::cout << "Enter name of algoritm: ";
            std::cin >> prog[i].alg;
            std::cout << "Do it have license? Yes/no: ";
            std::cin >> prog[i].license;
        }

        std::ofstream file(argv[3], std::ios_base::binary | std::ios_base::app);
        char separator[2] = "!";
        if (file.is_open()) {
            file.write((char*)(&n), sizeof(int));
            for (int i = 0; i<n; i++) {
                file.write(prog[i].nameRazrab.c_str(), sizeof(prog[i].nameRazrab.c_str()));
                file.write(separator, 1);
                file.write(prog[i].vertion.c_str(), sizeof(prog[i].vertion.c_str()));
                file.write(separator, 1);
                file.write(prog[i].alg.c_str(), sizeof(prog[i].alg.c_str()));
                file.write(separator, 1);
                file.write(prog[i].license.c_str(), sizeof(prog[i].license.c_str()));
                file.write(separator, 1);
                
            }
            file.close();
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }

    if (wr == "read" && bt == "binary") {
        std::ifstream file(argv[3], std::ios_base::binary);

        if (file.is_open()) {
            std::vector<ProgrammOfKriptograf> prog;

            while (true) {
                int n;
                file.read(reinterpret_cast<char*>(&n), sizeof(int));

                if (file.eof()) {
                    break; // Если достигнут конец файла, выходим из цикла
                }

                for (int i = 0; i < n; ++i) {
                    ProgrammOfKriptograf pros;
                    std::string::size_type nameSize;


                    std::cout << "Programms read from file: " << std::endl;
                    std::string nameRazrab;
                    std::getline(file, nameRazrab, '!');
                    std::cout << nameRazrab << std::endl;
                    std::getline(file, nameRazrab, '!');
                    std::cout << nameRazrab << std::endl;
                    std::getline(file, nameRazrab, '!');
                    std::cout << nameRazrab << std::endl;
                    std::getline(file, nameRazrab, '!');
                    std::cout << nameRazrab << std::endl;    
                }
                
            }

            file.close();
            
            for (int i = 0; i < n; ++i) {
                std::cout << "Name: " << prog[i].nameRazrab << ", Vertion: " << prog[i].vertion << ", Name of alg: " << prog[i].alg << ", License: " << prog[i].license << std::endl;
            }
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }

    if (wr == "clear" and bt == "all") {
        std::ofstream file(argv[3], std::ios_base::trunc);
        file.close();
        std::cout << "File has been cleared." << std::endl;
    }
    return 0;
}