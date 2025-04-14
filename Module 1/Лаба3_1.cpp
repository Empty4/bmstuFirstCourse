#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

int main(){
    int count_of_el;
    srand(time(NULL));
    cout << "Enter count of elements in massiv: ";
    cin >> count_of_el;
    //int mass[10];//стат
    int *mass = new int[count_of_el];//динамический
    int min_sum = 1000;
    for (int i; i<count_of_el; i++){
        cout << "Element № " << i <<": ";
        mass[i] = rand()%100;
        cout << mass[i]<<endl;
    }
    for (int i = 1; i<count_of_el; i++){
        if (mass[i-1]+mass[i]<min_sum){
            min_sum = mass[i-1]+mass[i];
        }
    }
    delete [] mass;
    mass = nullptr;
    cout << min_sum << endl;
    return 0;
}
    //git init
    //git remote
    //git add . #всё
    //git commit -m ""
    // git push origin master
    //токен как пароль