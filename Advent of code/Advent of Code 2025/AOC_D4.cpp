#include <iostream>
#include <fstream>

using namespace std;

char** createMap(int rowSize, int colSize, int size)
{
	char** map = (char**)malloc(rowSize * sizeof(char*));
	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			map[i] = (char*)malloc(colSize * sizeof(char));

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			map[i][j] = '.';

	ifstream input("input.txt");

	int i = 1, j = 1;

	char c;

	while (input >> c)
	{
		map[i][j] = c;
		j++;
		if (j == size + 1)
		{
			i++;
			j = 1;
		}
	}

	return map;
}

void printMap(char** map, int rowSize, int colSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

int eliminateRoll(char** map, int rowSize, int colSize)
{
	int count = 0, answer = 0;

	for (int i = 1; i < rowSize; i++)
		for (int j = 1; j < colSize; j++)
		{
			if (map[i][j] != '@')
				continue;

			count = 0;

			map[i][j] = '.';

			for (int iRange = -1; iRange <= 1; iRange++)
				for (int jRange = -1; jRange <= 1; jRange++)
				{
					if (map[i + iRange][j + jRange] == '@' || map[i + iRange][j + jRange] == 'x')
						count++;
				}

			if (count < 4)
			{
				answer++;
				map[i][j] = 'x';
			}
			else
			{
				map[i][j] = '@';
			}
		}


	for (int i = 1; i < rowSize; i++)
		for (int j = 1; j < colSize; j++)
		{
			if (map[i][j] != 'x')
				continue;

			map[i][j] = '.';
		}
	return answer;
}

void part1()
{
	ifstream input("input.txt");
	const int size = 137;
	const int rowSize = size + 2, colSize = size + 2;

	char** map = createMap(rowSize, colSize, size);

	printMap(map, rowSize, colSize);

	cout << endl;
	printMap(map, rowSize, colSize);


	cout << "answer: " << eliminateRoll(map, rowSize, colSize);
}

void part2()
{
	ifstream input("input.txt");
	const int size = 137;
	const int rowSize = size + 2, colSize = size + 2;

	char** map = createMap(rowSize, colSize, size);

	printMap(map, rowSize, colSize);

	int loop = eliminateRoll(map, rowSize, colSize);
	int finalAnswer = 0;

	while (loop != 0)
	{
		finalAnswer += loop;
		loop = eliminateRoll(map, rowSize, colSize);
	}

	cout << "answer: " << finalAnswer;

}


int main()
{
	part1();
}
/* Write up
* Part 1
* The problems asks us to remove the paper rolls that have fewer than four adjacent paper rolls in the 8 positions surrounding the current one.
* To solve this, create a map containing the information from input.
* Create func eliminateRoll that can count the number of rolls that can be accessed and change the map according to the following rules:
* - if on the current position we have a roll, as a placeholder put '.';
* - check the 3x3 space and see how many adjacent rolls there are, 'x' is taken in consideration as well;
* - if there are fewer than 3 then replace current position with 'x' meaning there was a roll there and count the roll using answer,
*   else put '@' back on current position, this means it cannot be removed;
* - after checking all the map, be sure to replace 'x' in map with '.'.
* Finally, return answer, the number of rolls removed;
*
* Part 2
* For this part we have to continuously remove rolls until no more eliminations can be made.
* Just loop the function until it returns 0.
*/