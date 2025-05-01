#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

struct bankDeposit {
    string name;
    string amount;
    string type;
    string interestRate;
};

deque<bankDeposit> employees;

bool sorted(const bankDeposit & ob1, const bankDeposit & ob2) {
    return ob1.type < ob2.type;
};

int main (int argc, const char *argv[]) {
    ifstream fin;
    fin.open(argv[1]);
    if (fin.is_open()) {
        string line;
        bankDeposit new_employee;
        while (getline(fin, line)) {
            new_employee.name = line;
            getline(fin, line);
            new_employee.amount = line;
            getline(fin, line);
            new_employee.type = line;
            getline(fin, line);
            new_employee.interestRate = line;
            employees.push_back(new_employee);
        }
    }
    fin.close();
    cout << "Веfore sorting" << endl;
    for (auto &p : employees) {
        cout << p.type << endl;
    }
    sort(employees.begin(), employees.end(), sorted);
    cout << "After sorting" << endl;
    for (auto &p : employees) {
        cout << p.type << endl;
    }
    return 0;
}