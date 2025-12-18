#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct rangeIds
{
	long long int firstId, secondId;
};

void part1()
{
	ifstream input("input.txt");
	vector<rangeIds> ranges;
	long long int ingredient;
	char line[1000];
	int answer = 0;

	while (input >> line)
	{
		while (strchr(line, '-'))
		{
			rangeIds range;
			sscanf(line, "%lld-%lld", &range.firstId, &range.secondId);
			ranges.push_back(range);
			input >> line;
		}
		
		ingredient = atoll(line);

		cout << line<<endl;
		for (rangeIds range : ranges)
		{
			if (range.firstId <= ingredient && ingredient <= range.secondId)
			{
				answer++;
				break;
			}
		}
	}

	cout << "answer: " << answer;
}

// part 2 
void mergeOverlaps(vector<rangeIds>& ranges)
{
	for (int i = 1; i < ranges.size(); i++) // the element that needs to be inserted in a range if overlapping
	{
		if (ranges[i].firstId >= ranges[i - 1].firstId && ranges[i].secondId <= ranges[i - 1].secondId)  // is within previous range
		{
			ranges.erase(ranges.begin() + i);
			i--;
		}
		else
			if (ranges[i].firstId >= ranges[i - 1].firstId && ranges[i].firstId <= ranges[i - 1].secondId) // extends range
			{
				ranges[i - 1].secondId = ranges[i].secondId;
				ranges.erase(ranges.begin() + i);
				i--;
			}
	}
}

void bubbleSort(vector<rangeIds>& ranges, int n)
{
	int ok;
	for (int i = 0; i < n - 1; i++)
	{
		ok = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ranges[j].firstId > ranges[j + 1].firstId)
			{
				ok = 1;
				rangeIds aux;
				aux = ranges[j];
				ranges[j] = ranges[j + 1];
				ranges[j + 1] = aux;
			}
		}
		if (ok == 0)
			break;
	}
}

void part2()
{
	ifstream input("input.txt");
	vector<rangeIds> ranges;
	char line[1000];

	while (input >> line)
	{
		if (strchr(line, '-'))
		{
			rangeIds range;

			sscanf(line, "%lld-%lld", &range.firstId, &range.secondId);

			ranges.push_back(range);
		}
		else
			break;
	}

	bubbleSort(ranges, ranges.size());
	mergeOverlaps(ranges);

	for (int i = 0; i < ranges.size(); i++)
		cout << ranges[i].firstId << "-" << ranges[i].secondId << endl;

	long long int answer = 0;

	for (int i = 0; i < ranges.size(); i++)
	{
		answer = answer + (ranges[i].secondId - ranges[i].firstId + 1);
	}

	cout << "answer: " << answer;
}

int main()
{
	part1();
}
/* Write up
* Part 1
* The problem asks to check if ingredients are in a range of non-spoiled ingredients.
* To solve, store the id ranges in an array/vector. When getting to reading ingredient ids, go through the ranges and check if it is found in a range.
* If yes, then count.
*
* Part 2
* During this part, we must get how many ids are considered fresh, but we face an overlapping ranges problem. 
* 
* To solve this issue, we order the ranges in order of the first id.
* In func mergeOverlaps we check if current range is within the previous one, if it is, then erase it,
* else if the current first id is within the previous range, merge the two ranges into a bigger one.
* 
* After all merges are done, calculate the sizes of the ranges to get answers.
*/