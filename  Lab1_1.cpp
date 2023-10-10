#include <iostream>
#include <math.h>

using namespace std;


int main(){
    float grad;
    cout << "Enter gradys for taken radian, min and sec: ";
    cin >> grad;
    
    float rad = (grad*M_PI)/180;
    cout << "Radian: " << rad << endl;

    float min = grad*60;
    cout << "Min: " << min << endl;

    float sec = grad*60*60;
    cout << "Sec: " << sec << endl;
    
    return 0;
}