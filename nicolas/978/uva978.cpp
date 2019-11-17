/*
Autor: Nicolas Pereira Sampaio
Deve-se descobrir qual dos 2 exércitos irá ganhar a guerra, baseado no número de campos
*/


#include <iostream>
#include <set> 

using namespace std;



int main() {
	int qntTeste;
	cin >> qntTeste;
	while (qntTeste > 0)
	{
		int b;
		int sb;
		int sg;

		cin >> b >> sg >> sb;

		int item;

		multiset<int, greater<int>> soldadosSg;
		for (int i = 0; i < sg; i++) {
			cin >> item;
			soldadosSg.insert(item);
		}

		multiset<int, greater<int>> soldadosSb;
		for (int i = 0; i < sb; i++) {
			cin >> item;
			soldadosSb.insert(item);
		}

		while (!soldadosSb.empty() && !soldadosSg.empty()) {
			multiset<int, greater<int>> lutaramSg;
			multiset<int, greater<int>> lutaramSb;
			int escolhidoSg;
			int escolhidoSb;

			//BATALHA
			for (int i = 0; i < b; i++) {
				if (!soldadosSb.empty() && !soldadosSg.empty()) {
					escolhidoSg = *(soldadosSg.begin());
					escolhidoSb = *(soldadosSb.begin());
					soldadosSg.erase(soldadosSg.lower_bound(escolhidoSg));
					soldadosSb.erase(soldadosSb.lower_bound(escolhidoSb));

					if (escolhidoSg > escolhidoSb) {
						escolhidoSg = escolhidoSg - escolhidoSb;
						lutaramSg.insert(escolhidoSg);
					}
					else {
						escolhidoSb = escolhidoSb - escolhidoSg;
						if (escolhidoSb != 0) {
							lutaramSb.insert(escolhidoSb);
						}
					}
				}
			}

			//RECOLOCA ESCOLHIDOS NOS SOLDADOS
			if (!lutaramSg.empty()) {
				for (auto it = lutaramSg.begin(); it != lutaramSg.end(); ++it) {
					soldadosSg.insert(*it);
				}
			}
			if (!lutaramSb.empty()) {
				for (auto it = lutaramSb.begin(); it != lutaramSb.end(); ++it) {
					soldadosSb.insert(*it);
				}
			}
		}



		multiset <int, greater <int> > ::iterator itr;
		//VERIFICA VENCEDORES
		if (soldadosSb.empty() && soldadosSg.empty()) {
			cout << "green and blue died" << endl;
		}
		else {
			if (soldadosSb.empty()) {
				cout << "green wins" << endl;
				for (itr = soldadosSg.begin(); itr != soldadosSg.end(); ++itr) {
					cout << *itr << endl;
				}
			}
			else {
				cout << "blue wins" << endl;
				for (itr = soldadosSb.begin(); itr != soldadosSb.end(); ++itr) {
					cout << *itr << endl;
				}
			}
		}
		soldadosSb.clear();
		soldadosSg.clear();
		qntTeste--;
	}

}