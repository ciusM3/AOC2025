#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;

void part1()
{
	ifstream input("input.txt");

	int countOf0 = 0;
	int posOfDial = 50;
	char rotation;
	int number;

	while (input >> rotation >> number)
	{
		if (rotation == 'R')
		{
			posOfDial = (posOfDial + number) % 100;
		}
		else
		{
			posOfDial = (posOfDial - number) % 100;
			if (posOfDial < 0)
				posOfDial = posOfDial + 100;
		}

		cout << posOfDial << endl;

		if (posOfDial == 0)
			countOf0++;
	}

	cout << "answer: " << countOf0;
}

void part2()
{
	ifstream input("input.txt");

	int countOf0 = 0;
	int posOfDial = 50;
	char rotation;
	int number;

	while (input >> rotation >> number)
	{
		cout << posOfDial << endl;

		if (rotation == 'R')
		{
			if (posOfDial + number > 99)
				countOf0 += (posOfDial + number) / 100;
			posOfDial = (posOfDial + number) % 100;
		}
		else
		{
			countOf0 += number / 100;     // takes in account if current position of the dial is 0
			int rest = number % 100;

			if (posOfDial > 0 && posOfDial - rest <= 0) // ignore rest of the rotation if current position is 0
				countOf0++;

			posOfDial = (posOfDial - number) % 100;
			if (posOfDial < 0)
				posOfDial = posOfDial + 100;
		}
	}

	cout << posOfDial << endl;

	cout << "answer: " << countOf0;
}

int main()
{
	part2();
}
/* Write up 
* Part 1
* The problem asks for the number of times the dial remains on 0 after a rotation.
* Based on the orientation of the rotation made, the changes are applied to posOfDial. 
* If the position of the dial is facing 0, then count.
* 
* Part 2
* For this part, additional logic needs to be added, check if the dial passed 0 during a rotation. 
* For 'R' rotations, to see how many loops have been done, the sum between position and rotation is done and then divided by 100.
* For 'L' rotations, the number of loops is broken down from number by dividing by 100. One last check must be done to see if the remaining rotation passes by 0, only if current position > 0.
*/