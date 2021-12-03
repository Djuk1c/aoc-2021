#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

void partOne();
void partTwo();
void pVec(vector<string> &vec);
int doDaThing(vector<string> &vec, bool oxygen);

int main()
{
	partTwo();

	return 0;
}

void partTwo()
{
	vector<string> oxygen;
	vector<string> co2;
	ifstream file("day3.input");
	string n;
	while (file >> n)
	{
		oxygen.push_back(n);
		co2.push_back(n);
	}

	// Oxygen
	cout << doDaThing(oxygen, true) * doDaThing(co2, false) << endl;
}

int doDaThing(vector<string> &vec, bool oxygen)
{
	int i = 0;
	while (vec.size() != 1)
	{
		int cnt[2] = {0,0};
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j][i] == '1')
				cnt[0]++;
			else
				cnt[1]++;
		}
		char r;
		if (oxygen)
			r = cnt[0] >= cnt[1] ? '1' : '0';
		else
			r = cnt[0] >= cnt[1] ? '0' : '1';
		erase_if(vec, [&i, &r](string x){return x[i] == r;});
		i++;
	}
	int vecVal = 0;
	reverse(vec[0].begin(), vec[0].end());
	for (int i = 0; i < vec[0].size(); i++)
	{
		if (vec[0][i] == '1')
			vecVal += pow(2, i);
	}
	return vecVal;
}

void pVec(vector<string> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ", ";
	}
	cout << endl << endl;
}

void partOne()
{
	vector<string> nums;
	ifstream file("day3.input");
	string n;
	while (file >> n)
	{
		reverse(n.begin(), n.end()); // So i can properly do binary conversion
		nums.push_back(n);
	}

	int gamma = 0;
	int eps = 0;
	for (int i = 0; i < nums[0].size(); i++)
	{
		int counter = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j][i] == '1')
				counter++;
		}

		if (counter > nums.size()/2)
		{
			cout << '1';
			gamma += pow(2, i);
		}
		else
		{
			cout << '0';
			eps += pow(2, i);
		}

		cout << counter << endl;
	}

	cout << "gamma: " << gamma << endl;
	cout << "eps: " << eps << endl;
	cout << "ans: " << gamma*eps << endl;
}
