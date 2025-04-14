#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand(TIME_UTC);
    int n = rand();
    cout << n;
}