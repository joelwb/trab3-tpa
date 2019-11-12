/*
Autor: Joel Will Belmiro 

O problema quer que se a partir de uma linha de texto com caracteres especiais
servindo de auxiliadores, se obtenha o que ele chama de "Beiju Text",
sem esses caracteres especiais
*/

#include <iostream>
#include <string>
#include <locale>
#include <list>
using namespace std;

int main() {
    string line;

    while (getline(cin, line) && line != "") {
        list<string> list;
        string buffer = "";

        bool home = false;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ']' || line[i] == '[') {
                if (!buffer.empty()) list.push_front(buffer);
                buffer = "";
                home = line[i] == '[';
            } else if (home) {
                buffer += line[i];
            }
        }

        if (!buffer.empty()) list.push_front(buffer);

        buffer = "";
        home = false;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ']' || line[i] == '[' ) {
                if (!buffer.empty()) list.push_back(buffer);
                buffer = "";
                home = line[i] == '[';
            } else if (!home) {
                buffer += line[i];
            }
        }

        if (!buffer.empty()) list.push_back(buffer);

        int size = list.size();
        for (int i = 0; i < size; i++) {
            cout << list.front();
            list.pop_front();
        }

        cout << endl;
    }
}