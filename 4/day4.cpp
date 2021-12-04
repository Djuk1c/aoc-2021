// Good luck trying to understand this
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

void pVec(vector<int> &vec);

int main()
{
	vector<int> numbers;
	vector<int> boards;
	string a;

	// Load Numbers;
	ifstream nms("nums.input");
	while(getline(nms, a, ','))
	{
		numbers.push_back(stoi(a));
	}
	nms.close();

	// Load Boards
	ifstream brds("boards.input");
	int n;
	while (brds >> n)
	{
		boards.push_back(n);
	}
	brds.close();

	//////
	
	map<int, int> wonBoards;
	vector<int> pickedNumbers;
	for (int i = 0; i < numbers.size(); i++)
	{
		pickedNumbers.push_back(numbers[i]);
		for (int board = 0; board < boards.size(); board+=25)
		{
			for (int y = 0; y < 5; y++)
			{
				int rCount = 0;
				int cCount = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int z = 0; z < pickedNumbers.size(); z++)
					{
						// Rows
						// i	 = index of number in current cell
						// y	 = which cell is being checked
						if (boards[board+i+(5*y)] == pickedNumbers[z])
						{
							rCount++;
						}

						// Columns
						// i	 = index of number in current row
						// y 	 = which row is being checked
						if (boards[board+(i*5)+y] == pickedNumbers[z])
						{
							cCount++;
						}
					}
				}
				if (rCount == 5 || cCount == 5)
				{
					// Unmarked numbers
					int sum = 0;
					for (int v = board; v < board+25; v++)
					{
						if (find(begin(pickedNumbers), end(pickedNumbers), boards[v]) == end(pickedNumbers))
							sum += boards[v];
					}
					sum *= pickedNumbers.back();
					//cout << sum << endl;
					if (!wonBoards.count(board/25+1))
					{
						cout << "inserted : " << sum << endl;
						wonBoards.insert({board/25+1, sum});
					}
					break;
					//return 0;
				}
			}
		}
	}

	return 0;
}

void pVec(vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
