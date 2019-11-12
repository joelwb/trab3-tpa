/*
Autor: Joel Will Belmiro 

Deve-se achar a mediana a cada vez que se ler um linha de entrada
*/

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(){
    vector<int> X;
    int x;
    while (cin >> x) {
        int pos = 0;
        for (int i = 0; i < X.size(); i++){
            if (X[i] > x) {
                pos = i;
                break;
            }
        }

        X.insert(X.begin() + pos, x);
        int meio = X.size() / 2;
        if (X.size() % 2 != 0) {
            cout << X[meio] << endl;
        } else {
            int median = (X[meio] + X[meio - 1]) / 2;
            cout << median << endl;
        }
    }
}