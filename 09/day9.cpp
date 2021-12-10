// ULTRA SPAGHETTI CODE
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> input;
vector<pair<int, int>> lowPointCoord;
void loadInput();

int main()
{
	loadInput();
	int p1ans = 0;
	int p2ans = 0;
	// Get low points
	for (int y = 0; y < input.size(); y++)
	{
		for (int i = 0; i < input[y].size(); i++)
		{
			int curr = (int)input[y][i]-48;
			vector<int> checkAgainst;
			if (y != 0)
				checkAgainst.push_back((int)input[y-1][i]-48);
			if (y != input.size()-1)
				checkAgainst.push_back((int)input[y+1][i]-48);
			if (i != input[y].size()-1)
				checkAgainst.push_back((int)input[y][i+1]-48);
			if (i != 0)
				checkAgainst.push_back((int)input[y][i-1]-48);

			int counter = 0;
			for (int j = 0; j < checkAgainst.size(); j++)
			{
				if (curr < checkAgainst[j])
					counter++;
			}
			if (counter == checkAgainst.size() && counter != 0)
			{
				p1ans += curr + 1;
				lowPointCoord.push_back(make_pair(y, i));
			}
		}
	}
	cout << "Part 1 answer: " << p1ans << endl;

	// Part 2
	vector<int> basinSizes;
	for (int j = 0; j < lowPointCoord.size(); j++)
	{
		int len = 0;
		vector<pair<int, int>> posQueue;
		posQueue.push_back({lowPointCoord[j].first, lowPointCoord[j].second});

		for (int i = 0; i < posQueue.size(); i++)
		{
			len++;
			int y = posQueue[i].first;
			int x = posQueue[i].second;
			pair<int, int> foo;

			foo = make_pair(y-1, x);
			if (y != 0 && input[y-1][x] != '9' && 
				count(posQueue.begin(), posQueue.end(), foo) == 0)
			{
				posQueue.push_back(foo);
			}

			foo = make_pair(y+1, x);
			if (y != input.size()-1 && input[y+1][x] != '9' && 
				count(posQueue.begin(), posQueue.end(), foo) == 0)
			{
				posQueue.push_back(foo);
			}

			foo = make_pair(y, x+1);
			if (x != input[y].size()-1 && input[y][x+1] != '9' && 
				count(posQueue.begin(), posQueue.end(), foo) == 0)
			{
				posQueue.push_back(foo);
			}

			foo = make_pair(y, x-1);
			if (x != 0 && input[y][x-1] != '9' && 
				count(posQueue.begin(), posQueue.end(), foo) == 0)

			{
				posQueue.push_back(foo);
			}

		}
		basinSizes.push_back(len);
	}

	sort(basinSizes.begin(), basinSizes.end(), greater<int>());
	p2ans = basinSizes[0] * basinSizes[1] * basinSizes[2];
	cout << "Part 2 answer: " << p2ans << endl;

	return 0;
}

void loadInput()
{
	ifstream file("day9.input");
	string n;
	while (getline(file, n))
	{
		input.push_back(n);
	}
}
