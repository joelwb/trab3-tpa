#include <iostream>
#include <stack> 
#include<vector>
#include <string> 
using namespace std;


int main() {
	int qnt = 0;
	while (true) {
		vector<stack<char>> pilhas;
		string containers;
		cin >> containers;
		if (containers == "end") break;

		for (int i = 0; i < containers.size(); i++) {
			if (pilhas.empty()) {
				stack<char> pilhaInicial;
				pilhaInicial.push(containers[i]);
				pilhas.push_back(pilhaInicial);
			}
			else {
				bool achou = false;
				for (int z = 0; z < pilhas.size(); z++) {
					if (pilhas[z].top() >= containers[i]) {
						pilhas[z].push(containers[i]);
						achou = true;
						break;
					}
				}
				if (!achou) {
					stack<char> novaPilha;
					novaPilha.push(containers[i]);
					pilhas.push_back(novaPilha);
				}
			}
		}
		qnt = qnt + 1;
		auto qntS = std::to_string(qnt);
		auto totalPilha = std::to_string(pilhas.size());
		
		cout << "Case " + qntS + ": " + totalPilha << endl;
	}	

	

}