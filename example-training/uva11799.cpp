
#include "pch.h"
#include <iostream>

int main()
{
	int totalCases;
	std::cin >> totalCases;
	for (int actualCase = 1; actualCase <= totalCases; actualCase++) {
		int totalStudents, maxSpeed = 1;
		std::cin >> totalStudents;

		for (int student = 0; student < totalStudents; student++) {
			int speedStudent;
			std::cin >> speedStudent;
			if (speedStudent > maxSpeed) maxSpeed = speedStudent;
		}

		std::cout << "Case " << actualCase << ": " << maxSpeed << "\n";
	}
}