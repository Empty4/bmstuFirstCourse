#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
	LinkedList mem;
	int n;
	file >> n;
	for (int i = 0; i < n; ++i) {
		bankDeposit bankk;
		file >> bankk.name >> bankk.amount >> bankk.type >> bankk.interestRate;
		mem.push_back(bankk);
	}
    Node* ptr = mem.head;



	for (int i = 1; i < n; i++){
        int key = mas[i];
        int j = i-1;
        while (j>=0 && mas[j]>key){
            mas[j+1] = mas[j];
            mas[j] = key;
            j--;
        }
    }



	
    return 0;
}*/


/*
using namespace std;

void main(){
    int n, m;
    cout << "Count of strok: ";
    cin >> n;
    cout << "Count of stolbcov: ";
    cin >> m;
    vector <int> matrix(n);
    matrix.push_back(vector <int> matr(m));
    srand(time(NULL));
    for (int i = 0; i<n; i++){
        matrix[i] = rand()%100;
        for (int j = 0; j<m; j++){
            
            cout << matrix[i, j];
        }
    }
}
*/
/*
struct ProgrammOfKriptograf{
    std::string nameRazrab;//char*
    //char chname[prog[i].nameRazrab.length()];
    float vertion;
    std::string alg;
    std::string license;
};

int main(int argc, char* argv[]){
    int n;
    std::string wr = argv[1];
    std::string bt = argv[2]; 
    if (wr == "write" && bt == "binary") {
        std::cout << "Please enter number of programm: ";
        std::cin >> n;
        std::vector<ProgrammOfKriptograf> prog(n);

        for (int i = 0; i < n; i++) {
            std::cout << "Enter name of razrab: ";

            //std::cin >> prog[i].nameRazrab;//повтор
            //char chname[prog[i].nameRazrab.length()];
            //std::cin >> chname;//повтор
            //prog[i].nameRazrab = chname;

            std::cin.ignore();
            std::getline(std::cin, prog[i].nameRazrab);

            std::cout << "Enter vertion of this programm: ";
            std::cin >> prog[i].vertion;
            std::cout << "Enter name of algoritm: ";
            //std::cin >> prog[i].alg;

            std::cin.ignore();
            std::getline(std::cin, prog[i].alg);
            std::cout << "Do it have license? Yes/no: ";
            std::cin >> prog[i].license;
        }

        std::ofstream file(argv[3], std::ios_base::binary | std::ios_base::app);

        if (file.is_open()) {
            file.write((char*)(&n), sizeof(int));

            for (int i; i<n; i++) {
                file.write((char*)&prog[i], sizeof(prog[i]));
            }
            file.close();
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }
}
*/