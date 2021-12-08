#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void part1();
void part2();

int main()
{
	part2();
	return 0;
}

void part2()
{
	ifstream file("day8.input");
	string n;
	int result = 0;
	while (getline(file, n))
	{
		string numberCodes[10];
		istringstream iss(n.substr(0, n.find("|")));
		string temp;

		// Get numbers we know by their unique sizes
		while (iss >> temp)
		{
			if (temp.size() == 2)	// number 1
				numberCodes[1] = temp;
			else if (temp.size() == 3)	// number 7
				numberCodes[7] = temp;
			else if (temp.size() == 4)	// number 4
				numberCodes[4] = temp;
			else if (temp.size() == 7)	// number 8
				numberCodes[8] = temp;
		}

		// Get other numbers by comparing
		iss.clear();
		iss.str(n.substr(0, n.find("|")));
		while (iss >> temp)
		{
			if (temp.size() == 2 || temp.size() == 3 || temp.size() == 4 || temp.size() == 7)
				continue;

			int counter = 0;
			int diff = 0;
			for (char &c : temp)
			{
				if (numberCodes[1].find(c) != string::npos)
					diff++;
				if (numberCodes[4].find(c) != string::npos)
					diff++;
			}
			counter += temp.size()*2 - diff;

			switch(counter)
			{
				case 7:
					if (temp.size() == 5)
						numberCodes[2] = temp;
					else if (temp.size() == 6)
						numberCodes[0] = temp;
					break;

				case 5:
					numberCodes[3] = temp;
					break;

				case 6:
					if (temp.size() == 5)
						numberCodes[5] = temp;
					else if (temp.size() == 6)
						numberCodes[9] = temp;
					break;

				case 8:
					numberCodes[6] = temp;
					break;
			}
		}
		
		// Read the value
		iss.clear();
		iss.str(n.substr(n.find("|"), n.size()-1));
		string ans = "";
		while (iss >> temp)
		{
			for (int i = 0; i < 10; i++)
			{
				int counter = 0;
				for (char &c : temp)
				{
					if(numberCodes[i].contains(c))
						counter++;
				}
				if (counter == temp.size() && temp.size() == numberCodes[i].size())
				{
					ans += to_string(i);
					break;
				}
			}
		}
		result += stoi(ans);
	}
	cout << result << endl;
}

void part1()
{
	ifstream file("day8.input");
	string n;
	int ans = 0;
	while (getline(file, n))
	{
		n.erase(0, n.find("|")+1);
		istringstream iss(n);
		string word;
		while (iss >> word)
		{
			cout << word << endl;
			if (word.size() == 2 || word.size() == 4 || word.size() == 3 || word.size() == 7)
				ans++;
		}
	}

	cout << ans << endl;
}
