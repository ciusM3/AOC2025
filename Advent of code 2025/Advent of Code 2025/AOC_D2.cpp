#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <vector>

// !! for this code to run succesfully in the input file there must be an additional "," added at the end 

using namespace std;

int getSize(long long int id)
{
	int size = 0;

	if (id == 0)
		return 1;

	while (id)
	{
		id /= 10;
		size++;
	}
	return size;
}

int allEqual(vector<long long int> pairs)
{
	if (pairs.size() < 2)
		return 0;

	for (int i = 0; i < pairs.size(); i++)
	{
		if (pairs[0] != pairs[i])
			return 0;
	}
	return 1;
}

void part1()
{
	ifstream input("input.txt");
	long long int firstId, SecondId;
	char auxChar;
	long long int answer = 0;

	while (input >> firstId >> auxChar >> SecondId >> auxChar)
	{
		for (long long int i = firstId; i <= SecondId; i++)
		{
			int iSize = getSize(i);
			int pairGet = pow(10, iSize / 2);

			if (i % pairGet == i / pairGet)
				answer += i;	
		}
	}
	cout << "answer: " << answer;
}

void part2()
{
	ifstream input("input.txt");
	long long int firstId, SecondId;
	char auxChar;
	long long int answer = 0;

	while (input >> firstId >> auxChar >> SecondId >> auxChar)
	{
		for (long long int i = firstId; i <= SecondId; i++)
		{
			int iSize = getSize(i);
			for (int pairSize = 1; pairSize <= iSize / 2; pairSize++)
			{
				vector<long long int> pairs;
				int pairGet = pow(10, pairSize);

				if (iSize % pairSize != 0)
					continue;

				long long int iCopy = i;

				while (iCopy > 0)
				{
					pairs.push_back(iCopy % pairGet);
					iCopy /= pairGet;
				}

				if (allEqual(pairs))
				{
					answer += i;
					break;
				}
			}
		}
	}

	cout << "answer: " << answer;
}

int main()
{
	part2();
}