#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstdio>
#include <math.h>

using namespace std;

typedef struct redCoords
{
	int x;
	int y;
};

int isWithingBounds(redCoords* redPosition, redCoords* otherCorners)   // compare with the other corners with the red boxes and check if theyre inside(smaller than them)
{

}

void part1()
{
	ifstream input("input.txt");

	char line[100];
	redCoords redPositions[500];
	int indexPos = 0;     // no of elements from input

	while (input >> line)
	{
		sscanf(line, "%d,%d", &redPositions[indexPos].y, &redPositions[indexPos].x);
		indexPos++;
	}

	for (int i = 0; i < indexPos; i++)
		cout << redPositions[i].y << " " << redPositions[i].x << endl;

	long long int maxSurfArea = -1;

	for (int i = 0; i < indexPos - 1; i++)
		for (int j = i + 1; j < indexPos; j++)
		{
			long long int xDif = abs(redPositions[i].x - redPositions[j].x) + 1;
			long long int yDif = abs(redPositions[i].y - redPositions[j].y) +  1;

			long long int surfArea = xDif * yDif;

			if (surfArea > maxSurfArea)
				maxSurfArea = surfArea;
		}

	cout << maxSurfArea;
}

void part2()
{
	ifstream input("input.txt");

	char line[100];
	redCoords redPositions[500];
	int indexPos = 0;     // no of elements from input

	while (input >> line)
	{
		sscanf(line, "%d,%d", &redPositions[indexPos].y, &redPositions[indexPos].x);
		indexPos++;
	}

	for (int i = 0; i < indexPos; i++)
		cout << redPositions[i].y << " " << redPositions[i].x << endl;

	long long int maxSurfArea = -1;

	for (int i = 0; i < indexPos - 1; i++)
		for (int j = i + 1; j < indexPos; j++)
		{
			long long int xDif = abs(redPositions[i].x - redPositions[j].x) + 1;
			long long int yDif = abs(redPositions[i].y - redPositions[j].y) + 1;

			long long int surfArea = xDif * yDif;

			if (surfArea > maxSurfArea)
				maxSurfArea = surfArea;
		}

	cout << maxSurfArea;
}

void part2idea()
{
	ifstream input("input.txt");

	char line[100];
	redCoords redPositions[500];
	int indexPos = 0;     // no of elements from input

	while (input >> line)
	{
		sscanf(line, "%d,%d", &redPositions[indexPos].y, &redPositions[indexPos].x);
		indexPos++;
	}

	for (int i = 0; i < indexPos; i++)
		cout << redPositions[i].y << " " << redPositions[i].x << endl;

	long long int maxSurfArea = -1;

	for (int i = 0; i < indexPos - 1; i++)
		for (int j = i + 1; j < indexPos; j++)
		{

			redCoords otherCorners[2];
			otherCorners[0].x = redPositions[i].x; otherCorners[0].y = redPositions[j].y;
			otherCorners[1].x = redPositions[j].x; otherCorners[1].y = redPositions[i].x;

			if ()   // if the other 2 corners are within the bounds
			{
				long long int xDif = abs(redPositions[i].x - redPositions[j].x) + 1;
				long long int yDif = abs(redPositions[i].y - redPositions[j].y) + 1;

				long long int surfArea = xDif * yDif;

				if (surfArea > maxSurfArea)
					maxSurfArea = surfArea;
			}
		}

	cout << maxSurfArea;
}

int main()
{
	part1();
}