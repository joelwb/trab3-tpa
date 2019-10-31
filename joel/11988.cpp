#include <iostream>
#include <string>
#include <locale>
#include <list>
using namespace std;

int main() {
    string line;

    while (getline(cin, line) && line != "") {
        list<string> stack;
        string buffer = "";

        bool home = false;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ']' || line[i] == '[') {
                if (!buffer.empty()) stack.push_front(buffer);
                buffer = "";
                home = line[i] == '[';
            } else if (home) {
                buffer += line[i];
            }
        }

        if (!buffer.empty()) stack.push_front(buffer);

        buffer = "";
        home = false;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ']' || line[i] == '[' ) {
                if (!buffer.empty()) stack.push_back(buffer);
                buffer = "";
                home = line[i] == '[';
            } else if (!home) {
                buffer += line[i];
            }
        }

        if (!buffer.empty()) stack.push_back(buffer);

        int size = stack.size();
        for (int i = 0; i < size; i++) {
            cout << stack.front();
            stack.pop_front();
        }

        cout << endl;
    }
}