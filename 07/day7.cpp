#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> nums;
void loadInput();
void part1();
void part2();

int main()
{
	loadInput();
	part2();

	return 0;
}

void part2()
{
	int average = 0;
	for (int &i : nums)
		average += i;
	average /= nums.size();

	int fuel = 0;
	for (int &i : nums)
	{
		int n = abs(i-average);
		fuel += (n*n+n)/2;		// nth triangle number
	}

	cout << fuel << endl;
}

void part1()
{
	sort(nums.begin(), nums.end());
	int median = nums[nums.size()/2-1];
	int fuel = 0;

	for (int &i : nums)
	{
		fuel += abs(i-median);
	}

	cout << fuel << endl;
}

void loadInput()
{
	ifstream file("day7.input");
	string n;
	while (getline(file, n, ','))
	{
		nums.push_back(stoi(n));
	}
}
