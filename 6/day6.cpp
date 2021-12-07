#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums;
	ifstream file("day6.input");
	string n;
	while (getline(file, n, ','))
	{
		nums.push_back(stoi(n));
	}

	unsigned long long step[9] = {0};
	for (int i : nums)
		step[i]++;

	for (int i = 0; i < 256; i++)
	{
		rotate(&step[0], &step[0]+1, &step[9]);
		step[6] += step[8];
	}

	unsigned long long counter = 0;
	for (int i = 0; i < 9; i++)
	{
		counter += step[i];
	}

	cout << counter << endl;
	return 0;
}
