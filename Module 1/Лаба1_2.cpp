#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int i = 0;
    float a;
    float summ = 0;
    cout << "Enter 3 number: " << endl;
    for (i=0; i<3; i++){
        cin >> a;
        if (a >= 0){
            summ = summ+a;
        }
    }
    cout<<"a= "<<a<<endl;
    cout << "Summa: " << summ << endl;
    return 0;
}