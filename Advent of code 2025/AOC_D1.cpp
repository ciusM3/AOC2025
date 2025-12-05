#include <iostream>
#include <fstream>
#include <string.h>

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

// brute forced, maybe I will come back to make a more elegant version
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
			for (int i = 0; i < number; i++)
			{
				if (posOfDial == 99)
					posOfDial = -1;
				posOfDial += 1;

				if (posOfDial == 0)
					countOf0++;
			}
		}
		else
		{
			for (int i = 0; i < number; i++)
			{
				if (posOfDial == 0)
					posOfDial = 100;
				posOfDial -= 1;

				if (posOfDial == 0)
					countOf0++;
			}
		}
	}
	cout << posOfDial << endl;

	cout << "answer: " << countOf0;
}

int main()
{
	part2();
}