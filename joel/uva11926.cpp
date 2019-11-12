/*
Autor: Joel Will Belmiro 

O problema se resume em saber se existe conflitos entre os horários das tarefas
onde haverá conflito se o horário de 2 ou mais tarefas estiverem em intersseção
*/

#include <iostream>
#include <bitset>
#include <string>
using namespace std;

const int tam = 1000001;

bool setAndCheck(bitset<tam> * mins, int start, int end){
    for (int j = start; j < end; j++){
        if (mins->test(j)) return true;
        mins->set(j);
    }

    return false;
}

int main() {
    int n, m, start, end, interv;

    while (cin >> n >> m && (n != 0 || m != 0)) {
        bitset<tam> mins;

        bool conflict = false;
        for (int i = 0; i < n; i++){
            cin >> start >> end;

            if (!conflict) conflict = setAndCheck(&mins, start, end);
        }

        for (int i = 0; i < m; i++){
            cin >> start >> end >> interv;

            int sumInterv = 0;

            while (!conflict && start + sumInterv < tam - 1 ) {
                conflict = setAndCheck(&mins, start + sumInterv, min(end + sumInterv, tam - 1));
                sumInterv += interv;
            }
        }

        if (conflict) cout << "CONFLICT" << endl;
        else cout << "NO CONFLICT" << endl;
    }
}