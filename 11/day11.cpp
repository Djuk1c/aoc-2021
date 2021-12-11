#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int flashes = 0;
// Just for convinence
int input[10][10] = {{6,2,2,7,6,1,8,5,3,6},
					 {2,3,6,8,1,5,8,3,8,4},
					 {5,3,8,5,4,1,4,1,1,3},
					 {4,5,5,6,7,5,7,5,2,3},
					 {6,7,4,6,4,8,6,7,2,4},
					 {4,8,8,1,3,2,3,8,8,4},
					 {4,6,4,8,2,6,3,7,4,4},
					 {4,8,7,1,3,3,2,8,7,2},
					 {4,7,2,4,1,2,8,2,2,8},
					 {4,3,1,6,5,1,2,1,6,7}};
bool flashed[10][10] = {false};

void printArray();
void increaseAdjecent(int y, int x);
void processStep();
bool p2check(int &iteration);

int main()
{
	printArray();

	int i = 0;
	while (!p2check(i))
	{
		// Step 1, inc energy level of each by 1
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				input[y][x]++;
			}
		}

		// Step 2, flash and stuff
		processStep();

		// Reset flashes
		for (int y = 0; y < 10; y++)
			for (int x = 0; x < 10; x++)
				flashed[y][x] = false;

		// Part 1 answer
		if (i == 100)
			cout << "Flashes: " << flashes << endl;
		
		// Part 2, check if all flashed at once
		if (p2check(i))
			return 0;
		i++;
	}
	return 0;
}

bool p2check(int &iteration)
{
	int a = input[0][0];
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (input[y][x] != a)
				return false;
		}
	}
	cout << "Iteration when all flashed at once: " << iteration + 1 << endl;
	return true;
}

void processStep()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (input[y][x] > 9 && flashed[y][x] == false)
			{
				input[y][x] = 0;
				flashed[y][x] = true;
				flashes++;
				increaseAdjecent(y, x);
				// Recursion kinda slow, doing a lot of wasteful checks
				// but it's easy and does the job
				processStep();
			}
		}
	}
}

void increaseAdjecent(int y, int x)
{
	// Yandare dev be like:
	if (y != 0)
	{
		if (x > 0 && !flashed[y-1][x-1])	input[y-1][x-1]++;
		if (!flashed[y-1][x])				input[y-1][x]++;
		if (x < 9 && !flashed[y-1][x+1])	input[y-1][x+1]++;
	}

	if (x > 0 && !flashed[y][x-1]) 			input[y][x-1]++; 
	if (x < 9 && !flashed[y][x+1]) 			input[y][x+1]++;

	if (y < 9)
	{
		if (x > 0 && !flashed[y+1][x-1]) 	input[y+1][x-1]++;
		if (!flashed[y+1][x]) 				input[y+1][x]++;
		if (x < 9 && !flashed[y+1][x+1])	input[y+1][x+1]++;
	}
}

void printArray()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << input[y][x];
		}
		cout << endl;
	}
	cout << endl;
}
