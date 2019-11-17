#include <iostream>

using namespace std;

bool isAllZero(int g[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g[i][j] > 0) return false;
		}
	}
	return true;
}

int  g[3][3], temp_matrix[3][3];
void f() {

	// Comparing corners 
	/*
		X0X
		000
		X0X
	*/
	temp_matrix[0][0] = (g[0][1] + g[1][0]) % 2;
	temp_matrix[0][2] = (g[0][1] + g[1][2]) % 2;
	temp_matrix[2][0] = (g[1][0] + g[2][1]) % 2;
	temp_matrix[2][2] = (g[1][2] + g[2][1]) % 2;

	// Comparing + positions
	/*
		0X0
		X0X
		0X0
	*/
	temp_matrix[0][1] = (g[0][0] + g[1][1] + g[0][2]) % 2;
	temp_matrix[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
	temp_matrix[1][2] = (g[0][2] + g[1][1] + g[2][2]) % 2;
	temp_matrix[2][1] = (g[1][1] + g[2][0] + g[2][2]) % 2;

	// Comparing middle
	/*
		000
		0X0
		000
	*/
	temp_matrix[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
}

void update_values(int g[3][3], int temp[3][3]) {
	// Update g values
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			g[i][j] = temp[i][j];
		}
	}
}

int main()
{
	int test_cases;
	cin >> test_cases;

	// equivalent to while(test_cases > 0){test_cases--;}
	while (test_cases--) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char verify_line = '\n';
				while (verify_line == '\n') cin >> verify_line;
				g[i][j] = verify_line - '0'; // remove end of string
			}
		}

		int actual_index = -1;
		while (!isAllZero(g)) {
			f();
			update_values(g, temp_matrix);
			actual_index++;
		}

		cout << actual_index << '\n';
	}
}