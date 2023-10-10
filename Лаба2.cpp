#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int k = 1;
    float e = pow(10,-2);
    float s = 1;
    float ts = log(2);
    while (abs(ts-s)>e){
        k++;
        s += (pow(-1,(k-1)))/k;
    }
    cout << ts << "/" << s <<endl;
    cout << "Count of opiration " << k <<endl;
    return 0;
} // namespace std;

