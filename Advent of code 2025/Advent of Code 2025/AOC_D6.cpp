#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

void part1()
{
	ifstream input("input.txt");
	int operationMembers[10][1000];

	char line[10000];
	int indexRow = 0;
	int indexCol;
	while (input.getline(line, sizeof(line)))
	{
		indexCol = 0;
		char* pointer = strtok(line, " ");

		while (pointer != NULL)
		{
			if (*pointer == '*' || *pointer == '+')
			{
				operationMembers[indexRow][indexCol] = *pointer;
			}
			else
			{
				int value = atoll(pointer);
				operationMembers[indexRow][indexCol] = value;
			}

			pointer = strtok(NULL, " ");
			indexCol++;
		}
		indexRow++;
	}

	long long int answer = 0;

	for(int iCol = 0; iCol<indexCol; iCol++)
	{ 
		long long int tempAnswer;
		if (operationMembers[indexRow - 1][iCol] == 42)
			tempAnswer = 1;
		else
			tempAnswer = 0;

		for (int iRow = 0; iRow < indexRow-1; iRow++)
		{
			if (operationMembers[indexRow - 1][iCol] == 42)
				tempAnswer = tempAnswer * operationMembers[iRow][iCol];
			else
				tempAnswer = tempAnswer + operationMembers[iRow][iCol];
		}

		answer += tempAnswer;
	}

	cout << "answer: " << answer;
}

int isAllSpace(char** inputText, int col, int noOfRows)
{
	int ok = 1;
	for (int i = 0; i < noOfRows; i++)
	{
		if (inputText[i][col] != ' ')
			return 0;
	}
	return ok;
}

void part2()
{
	// I store the input 
	ifstream input("input.txt");

	char** inputText = new char* [10];
	for (int i = 0; i < 10; i++)
		inputText[i] = new char[10000];

	char line[10000];
	int inputRowSize = 0;
	while (input.getline(line, sizeof(line)))
	{
		strcpy(inputText[inputRowSize], line);
		inputRowSize++;
	}

	for (int i = 0; i < inputRowSize; i++)
		cout << inputText[i] << endl;

	// I put operators in an array
	int noOps = 0;
	int operatorArr[1000];
	for (int i = 0; i < strlen(inputText[inputRowSize-1]); i++)
	{
		if (inputText[inputRowSize - 1][i] != ' ')
		{
			operatorArr[noOps] = inputText[inputRowSize - 1][i];
			noOps++;
		}
	}
	
	for (int i = 0; i < noOps; i++)
		cout << operatorArr[i] << " ";

	// Apply the operations
	unsigned long long int answer = 0;
	int currentOp = 0;
	unsigned long long tempAnswer = 0;
	long long int number;

	if (operatorArr[currentOp] == 42)
		tempAnswer = 1;
	else
		tempAnswer = 0;

	for (int j = 0; j < strlen(inputText[0]); j++)
	{
		int ok = 0;
		number = 0;
		if (isAllSpace(inputText, j, inputRowSize - 1) == 0)
		{
			ok = 1; // it is okay to use the number
		}
		else
		{
			currentOp++;
			answer += tempAnswer;
			if (operatorArr[currentOp] == 42)
				tempAnswer = 1;
			else
				tempAnswer = 0;
		}

		for (int i = 0; i < inputRowSize - 1; i++)
		{
			if (inputText[i][j] != ' ')
			{
				number = number*10 + (inputText[i][j] - '0');
			}
		}
		
		if (ok)
		{
			if (operatorArr[currentOp] == 42)
				tempAnswer *= number;
			else
				tempAnswer += number;
		}
	}

	answer += tempAnswer;

	cout <<endl << "answer: " << answer;
}

int main()
{
	part2();
}