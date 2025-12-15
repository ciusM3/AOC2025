#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <vector>

using namespace std;

void part1()
{
	ifstream input("input.txt");
	long long int firstId, secondId, ingredient;
	char dash;
	char line[1000];
	char ranges[1000][1000];

	int index = 0;
	while (input >> line)
	{
		if (strchr(line, '-'))
		{
			strcpy(ranges[index], line);
			index++;
		}
		else
			break;
	}

	int answer = 0;
	sscanf(line, "%lld", &ingredient);

	for (int i = 0; i < index; i++)
	{
		sscanf(ranges[i], "%lld%c%lld", &firstId, &dash, &secondId);
		if (ingredient >= firstId && ingredient <= secondId)
		{
			answer++;
			break;
		}
	}

	while (input >> ingredient)
	{
		for (int i = 0; i < index; i++)
		{
			sscanf(ranges[i], "%lld%c%lld", &firstId, &dash, &secondId);
			if (ingredient >= firstId && ingredient <= secondId)
			{
				answer++;
				break;
			}
		}
	}

	cout << "answer: " << answer;

}

// part 2 

typedef struct rangeIds
{
	long long int firstId, secondId;
};

void mergeOverlaps(vector<rangeIds>& ranges)
{
	for (int i = 1; i < ranges.size(); i++) // the element that needs to be inserted in a range if overlapping(extends the range)
	{
		if (ranges[i].firstId >= ranges[i - 1].firstId && ranges[i].secondId <= ranges[i - 1].secondId)
		{
			ranges.erase(ranges.begin() + i);
			i--;
		}
		else
			if (ranges[i].firstId >= ranges[i - 1].firstId && ranges[i].firstId <= ranges[i - 1].secondId)
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
	char dash;
	char line[1000];

	while (input >> line)
	{
		if (strchr(line, '-'))
		{
			rangeIds range;

			sscanf(line, "%lld%c%lld", &range.firstId, &dash, &range.secondId);

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
	part2();
}