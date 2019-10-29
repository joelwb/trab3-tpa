/**
 * Working on:
 * 24122150	10920	Spiral Tap	Accepted	C++11	0.420	2019-10-29 15:44:28
 **/

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
		middleLine = middleColumn = ceil(boardSize / 2.0);

		stepSize = stepsDone = 1;
		incrementStep = false;
		currentPos = 0;

		while (stepsDone < desiredPosition) {
			currentSide = sides[currentPos];
			if (++currentPos == 4) currentPos = 0;

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

			stepsDone += stepSize;

			if (incrementStep) {
				stepSize = stepSize + 1;
				incrementStep = false;
			}
		}

		if (stepsDone > desiredPosition) {
			int stepBack = stepsDone - desiredPosition;

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

		cout << "Line = " << middleLine << ", column = " << middleColumn << ".\n";
		cin >> boardSize >> desiredPosition;
	}
}