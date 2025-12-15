#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct tree
{
	int rows;
	int cols;
	vector<int> noPresents;
};

// easy input that doesn't require arranging the boxes shapes

int main()
{
	vector<tree> trees;
	char line[100];

	ifstream input("input.txt");
	while (input.getline(line, 100))
	{
		if (strchr(line, 'x') == NULL)
			continue;

		tree currentTree;
		char number[2];
		char* p = strtok(line, ":");

		strncpy(number, line, 2);
		currentTree.cols = atoi(number);

		strncpy(number, line + 3, 2);
		currentTree.rows = atoi(number);

		p = strtok(NULL, " ");
		while (p)
		{
			currentTree.noPresents.push_back(atoi(p));
			p = strtok(NULL, " ");
		}

		trees.push_back(currentTree);
	}

	for (tree i : trees)
	{
		cout << "Col: " << i.cols << " Rows: " << i.rows << " Presents: ";
		for (int j = 0; j < i.noPresents.size(); j++)
			cout << i.noPresents[j] << " ";
		cout << endl;
	}

	int count = 0;

	for (tree i : trees)
	{
		int treeSpace = i.cols * i.rows;
		int presentSpace = 0;
		for (int j = 0; j < i.noPresents.size(); j++)
			presentSpace += i.noPresents[j] * 9;

		if (presentSpace <= treeSpace)
			count++;
	}

	cout << "answer: " << count;
}