#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const string openChars = "([{<";
const string closedChars = ")]}>";
vector<string> input;
vector<string> incomplete;

void loadInput();
void part1();
void part2();

int main()
{
	loadInput();
	part1();
	part2();

	return 0;
}

void part2()
{
	vector<long long> answers;
	for (string &n : incomplete)
	{
		long long ans = 0;
		vector<char> seen;

		for (char &c : n)
		{
			if (openChars.contains(c))
				seen.push_back(c);
			else if (closedChars.contains(c))
			{
				seen.pop_back();
			}
		}

		reverse(seen.begin(), seen.end());
		for (int i = 0; i < seen.size(); i++)
		{
			int index = openChars.find(seen[i]);
			char symbol = closedChars[index];

			ans *= 5;
			switch (symbol)
			{
				case ')':
					ans += 1;
					break;
				case ']':
					ans += 2;
					break;
				case '}':
					ans += 3;
					break;
				case '>':
					ans += 4;
					break;
			}
		}
		answers.push_back(ans);
	}
	sort(answers.begin(), answers.end());

	cout << "Part 2 answer: " << answers[answers.size()/2] << endl;
}

void part1()
{
	long long ans = 0;
	for (string &n : input)
	{
		vector<char> seen;
		bool incpl = true;

		for (char &c : n)
		{
			if (openChars.contains(c))
				seen.push_back(c);
			else if (closedChars.contains(c))
			{
				int index = closedChars.find(c);
				char reqChar = openChars[index];
				if (seen.back() == reqChar)
					seen.pop_back();
				else
				{
					incpl = false;
					char found = closedChars[index];
					switch (found)
					{
						case ')':
							ans += 3;
							break;
						case ']':
							ans += 57;
							break;
						case '}':
							ans += 1197;
							break;
						case '>':
							ans += 25137;
							break;
					}
					break;
				}
			}
		}
		if (incpl)
			incomplete.push_back(n);
	}

	cout << "Part 1 answer: " << ans << endl;
}

void loadInput()
{
	ifstream file("day10.input");
	string n;
	while (getline(file, n))
	{
		input.push_back(n);
	}
}
