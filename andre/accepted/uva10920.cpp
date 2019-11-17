/***
	Author: André Martins

	This code checks at which row and column is position P in a spiral matrix M
***/

#include <iostream>
#include <math.h> 

using namespace std;

enum Side
{
	Up = 1,
	Left = 2,
	Down = 3,
	Right = 4
};

int main()
{
	unsigned int boardSize, middleLine, middleColumn;
	unsigned long long int  desiredPosition, stepSize, stepsDone;
	bool incrementStep;
	int currentSide, currentPos;
	int sides[4] = { Side::Up, Side::Left, Side::Down, Side::Right };

	cin >> boardSize >> desiredPosition;

	while (boardSize > 0 && desiredPosition > 0) {
		
		// Get the the middle of the spiral
		middleLine = middleColumn = ceil(boardSize / 2.0);

		stepSize = stepsDone = 1;
		incrementStep = false;
		currentPos = 0;

		// Run while don't pass the desiredPosition
		while (stepsDone < desiredPosition) {
			// Set the side to walk
			currentSide = sides[currentPos];
			if (++currentPos == 4) currentPos = 0;

			// Verify which side to walk and update the actual position
			switch (currentSide)
			{
			case Side::Up:
				middleLine = middleLine + stepSize;
				break;

			case Side::Left:
				middleColumn = middleColumn - stepSize;
				incrementStep = true;
				break;

			case Side::Down:
				middleLine = middleLine - stepSize;
				break;

			case Side::Right:
				middleColumn = middleColumn + stepSize;
				incrementStep = true;
				break;
			}

			// Increse the steps done
			stepsDone += stepSize;

			// Everytime it walks to left or right the number of steps to do in a row is increased
			if (incrementStep) {
				stepSize = stepSize + 1;
				incrementStep = false;
			}
		}

		// Verify if the last while passed the desired position
		if (stepsDone > desiredPosition) {
			
			// Get how many steps we passed from the desired possition
			int stepBack = stepsDone - desiredPosition;


			// Verify which side to walked and walks back the number of stepBack
			switch (currentSide)
			{
			case Side::Up:
				middleLine = middleLine - stepBack;
				break;

			case Side::Left:
				middleColumn = middleColumn + stepBack;
				break;

			case Side::Down:
				middleLine = middleLine + stepBack;
				break;

			case Side::Right:
				middleColumn = middleColumn - stepBack;
				break;
			}
		}

		// Print the result
		cout << "Line = " << middleLine << ", column = " << middleColumn << ".\n";
		cin >> boardSize >> desiredPosition;
	}
}