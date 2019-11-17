/***
Author: André Martins
UVa Online Judge Problem: 12247 Jollo

This code verify how many times it's necessary to change all the inputed matrix to Zero, its calculating the related cells by the module of 2.
***/


#include <iostream>

using namespace std;

// This function verify if the matrix has only 0's
bool isAllZero(int g[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g[i][j] > 0) return false;
		}
	}
	return true;
}


// This function calculates the related cells, according to the following comments
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

// Update the matrix values to the calculated values
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
		
		// Input matrix
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char verify_line = '\n';
				while (verify_line == '\n') cin >> verify_line;
				g[i][j] = verify_line - '0'; // remove end of string
			}
		}

		// Calculate the matrix cells while it's not only 0's
		int actual_index = -1;
		while (!isAllZero(g)) {
			f();
			update_values(g, temp_matrix);
			actual_index++;
		}

		// Result
		cout << actual_index << '\n';
	}
}