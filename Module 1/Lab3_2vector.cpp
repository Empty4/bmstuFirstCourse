#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    int n, m;
    cout << "Count of strok: ";
    cin >> n;
    cout << "Count of stolbcov: ";
    cin >> m;
    vector < vector <int> > matrix;
    float* sr_snach = new float[n];
    float summ = 0;

    for (int i = 0; i<n; ++i){
        vector <int> temp;
        for (int j = 0; j<m; ++j){
            int randi = rand()%100;
            temp.push_back(randi);
            summ  += randi;
        }
        matrix.push_back(temp);
        sr_snach[i] = summ/m;
        cout << "Sr_snach str№ " << i+1 << ": " << sr_snach << endl;
        
    }
    delete[] sr_snach;
    return 0;
}