#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <vector>

// !! for this code to run succesfully in the input file there must be an additional "," added at the end 

using namespace std;

int getSize(long long int id)  // gets the number length
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

int allEqual(vector<long long int> pairs)  // checks if all the pairs created from an id are equal
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

				while (iCopy > 0)  // break the copy of id into pairs
				{
					pairs.push_back(iCopy % pairGet);
					iCopy /= pairGet;
				}

				if (allEqual(pairs))  // check if those pairs are all equal
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
/* Write up
* Part 1
* The problem asks to check if a number is composed from the same sequence twice.
* For this part, the solution is simple, get the length of the id and make 2 pairs of length/2.
* If those two halves are equal, count the id.
* 
* Part 2
* Now we have to check if a sequence is repeated at least twice.
* 
* To solve this, make an array/vector of the pairs starting from pairSize = 1 up to id length/2.
* There must be a check to see if we can make pairs with the current pair size, 
* example: you can't make pairs with pair size = 3 from an id with the length of 8.
* After that make a copy of the id and break it into pairs stored in the pairs array/vector.
* If all the pairs are equal, count the id.
*/