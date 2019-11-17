/*
Autor: Nicolas Pereira Sampaio
Deve-se descobrir a soma das potências de cada canto, sendo que um cubo tem esquinas, e a sua potência é a soma do peso de esquinas vizinhas
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		vector<int> pesos;
		for (int canto = 0; canto < 1 << N; ++canto)
		{
			int peso;
			cin >> peso;
			pesos.push_back(peso);
		}
		
		vector<int> potencias;
		for (int canto = 0; canto < 1 << N; ++canto)
		{
			int potencia = 0;
			
			for (int digit = 0; digit < N; ++digit)
				potencia += pesos[canto ^ (1 << digit)];
			potencias.push_back(potencia);
		}
		
		int maxPoten = 0;
		for (int canto = 0; canto < 1 << N; ++canto)
		{
			for (int digito = 0; digito < N; ++digito)
				maxPoten = max(maxPoten, potencias[canto] + potencias[canto ^ (1 << digito)]);
		}
		cout << maxPoten << endl;
	}
	return 0;
}