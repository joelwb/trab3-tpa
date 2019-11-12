/*
Autor: Joel Will Belmiro 

Deve-se descobrir se dentro de uma sequência de números a diferença entre
valores vizinhos será menor do que o tamanho da sequência menos 1
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int n;

    while (cin >> n){
        int seq[n];
        int diffSeq[n-1] = {0};

        for (int i = 0; i < n; i++){
            cin >> seq[i];
        }

        bool flag = false;

        for (int i = 1; i < n; i++){
            int diff = abs(seq[i] - seq[i-1]);
            if (diff > n-1) {
                flag = true;
                break;
            }

            diffSeq[diff-1] = 1;
        }

        if (!flag) {
            for (int i = 0; i < n-1; i++){
                if (diffSeq[i] != 1) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            cout << "Not jolly" << endl;
        } else {
            cout << "Jolly" << endl;
        }
    }
}