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

typedef struct edges
{
	int edge[1000] = { 0 };
	int size;
};

void getEdges(edges* edgeH, edges* edgeV, redCoords* redPositions, int indexPos)
{
	int indexH, indexV;
	indexH = indexV = 0;

	for (int i = 1; i < indexPos; i++)
	{
		redCoords corner1 = redPositions[i];
		redCoords corner2 = redPositions[i-1];

		if (corner1.x == corner2.x)
		{
			edgeH->edge[indexV] = corner1.x;
			indexV++;
		}

		if (corner1.y == corner2.y)
		{
			edgeV->edge[indexH] = corner1.y;
			indexH++;
		}
	}

	edgeH->size = indexH;
	edgeV->size = indexV;
}

//int isWithingBounds(redCoords A, redCoords B, redCoords C, redCoords D, redCoords* redPositions)   // compare with the other corners with the red boxes and check if theyre inside(smaller than them)
//{
//
//
//	return 0;
//}

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
			redCoords A = redPositions[i];
			redCoords C = redPositions[j];

			long long int xDif = abs(A.x - C.x) + 1;
			long long int yDif = abs(A.y - C.y) + 1;

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

	edges edgeH;    // find the parameter of polygon
	edges edgeV;

	getEdges(&edgeH, &edgeV, redPositions, indexPos);

	cout << "horizontal edges" << endl;
	for (int i = 0; i < edgeH.size; i++)
		cout << edgeH.edge[i] << endl;

	//for (int i = 0; i < indexPos - 1; i++)
	//	for (int j = i + 1; j < indexPos; j++)
	//	{
	//		redCoords A = redPositions[i];
	//		redCoords C = redPositions[j];
	//		redCoords B = { C.x, A.y };
	//		redCoords D = { A.x, C.y };

	//		//if()

	//		//  has to be done after confirming the rectangle is in polygon
	//		long long int xDif = abs(A.x - C.x) + 1;
	//		long long int yDif = abs(A.y - C.y) + 1;

	//		long long int surfArea = xDif * yDif;

	//		if (surfArea > maxSurfArea)
	//			maxSurfArea = surfArea;
	//	}

	//cout << maxSurfArea;
}

int main()
{
	part2();
}