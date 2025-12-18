#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int getBiggestFromRange(int* arr, int l, int r)  // gets the biggest number within the given range of an array
{
	int index, max = -1;
	for (int i = l; i <= r; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}

	return index;
}

void part1()
{
	ifstream input("input.txt");
	char bank[101];
	int sizeOfBank;
	int sum = 0;

	while (input >> bank)
	{
		int joltage = 0;
		sizeOfBank = strlen(bank);
		int firstBiggest = -1, secondBiggest = -1;
		int indexFirst, indexSecond;
		int arr[100];

		for (int i = 0; i < sizeOfBank; i++)
			arr[i] = bank[i] - '0';

		indexFirst = getBiggestFromRange(arr, 0, sizeOfBank - 2);
		indexSecond = getBiggestFromRange(arr, indexFirst + 1, sizeOfBank - 1);

		firstBiggest = arr[indexFirst];
		secondBiggest = arr[indexSecond];

		joltage = firstBiggest * 10 + secondBiggest;
		cout << joltage << endl;
		sum += joltage;
	}
	cout << "answer: " << sum;
}

void part2()
{
	ifstream input("input.txt");
	char bank[101];
	int sizeOfBank;
	long long int sum = 0;

	while (input >> bank)
	{
		long long int  joltage = 0;
		sizeOfBank = strlen(bank);
		long long int batteryValue = 0;
		long long int  batteryIndex = -1;
		long long int  prevBatteryIndex;
		int arr[100];

		for (int i = 0; i < sizeOfBank; i++)
			arr[i] = bank[i] - '0';

		for (int i = 0; i < 12; i++)
		{
			batteryIndex = getBiggestFromRange(arr, batteryIndex + 1, sizeOfBank - (12 - i));
			batteryValue = arr[batteryIndex];
			joltage = joltage * 10 + batteryValue;
		}

		cout << joltage << endl;
		sum += joltage;
	}
	cout << "answer: " << sum;
}

int main()
{
	part1();
}
/* Write up
* Part 1
* This part of the problem asks us to make a combination of the two biggest numbers in order of appearance.
* Example: from the number 1215 the combination of the two biggest numbers will be 25. We can't swap them around.
* 
* To solve this, create func getBiggestFromRange that gets the biggest number in an array within the given range.
* Break the input into an array and create two variables that store the index of the two highest numbers within the array using previous func.
* Construct the joltage using the values in the array at the given indexes and then count it.
* 
* Part 2
* For this part, the previous idea used on part 1 must be extended to make the combination consisting of the twelve biggest numbers in order of appearance.
* The following recurrence formula can be used to solve this part.
* 
* batteryIndex = getBiggestFromRange(arr,  batteryIndex + 1, sizeOfBank - 1 - k);  
* k is bigger the smaller the index is, it must be done like this so the k-th largest number leaves space for the remaining numbers to come.
* Like in part 1, construct the joltage with the largest numbers and count.
*/