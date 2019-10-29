
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/***
Not Working Yet
***/
int main()
{
	int inputCards[5] = { 0,0,0,0,0 };
	vector<int> prince(2), princess(3);
	vector<bool> cartasValidas;

	// Read five integers
	bool hasZeroInput = false;
	int entryCard;
	for (int i = 0; i < 5; i++) {
		cin >> entryCard;
		inputCards[i] = entryCard;
		if (entryCard == 0) hasZeroInput = true;
		else {
			cartasValidas[entryCard] = false;
		}
	}

	do {
		cartasValidas.clear();
		cartasValidas.resize(53, true);

		princess = { inputCards[0], inputCards[1], inputCards[2] };
		prince = { inputCards[4], inputCards[3] };

		sort(prince.begin(), prince.end());
		sort(princess.begin(), princess.end());

		int lastPrinceCard = 53;

		/*for (int i = 0; i < 3; i++)
		{
			cout << princess[i] << "|";
			if (i < 2) cout << prince[i] << "\n";
		}*/

		// If the first card of the prince is bigger of the last card of the princess, all the other card is bigger too
		// This case guarantee that the prince already won 2 times
		if (prince[0] > princess[2]) {
			if (princess[2] != 52) {

				for (int i = 1; i <= 52 && i < lastPrinceCard; i++) {
					if (cartasValidas[i]) {
						lastPrinceCard = i;
					}
				}
			}
		}
		
		// In case of the first if isnt true, and this one is, the prince won only one game
		if (prince[1] > princess[2]) {
			for (int i = princess[2] + 1; i <= 52 && i < lastPrinceCard; i--) {
				if (cartasValidas[i]) {
					lastPrinceCard = i;
				}
			}
		}
		
		if (prince[0] > princess[1]) {
			for (int i = 52; i >= princess[1] && i < lastPrinceCard; i++) {
				if (cartasValidas[i]) {
					lastPrinceCard = i;
					break;
				}
			}
		}

		cout << lastPrinceCard << "\n";

		//out_data << lastPrinceCard << "\n";
		for (int i = 0; i < 5; i++) {
			cin >> entryCard;
			inputCards[i] = entryCard;
			if (entryCard == 0) hasZeroInput = true;
			else {
				cartasValidas[entryCard] = false;
			}
		}

	} while (!hasZeroInput);

	return 0;
}