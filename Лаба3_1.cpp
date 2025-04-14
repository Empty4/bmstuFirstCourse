#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int a;
    int i = 1;
    int An_1 = 0;
    int mini = 0;
    while (a != 0){
        cout << "Enter a" << i << ": ";
        cin >> a;
        if (a+An_1<mini){
            mini = a+An_1;
        }
        An_1 = a;
    }
    
    return 0;
    //git init
    //git remote
    //git add . #всё
    //git commit -m ""
    // git push origin master
    //токен как пароль

}