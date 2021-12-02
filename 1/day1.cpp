#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
ifstream file("day1.input");
int num, prevNum, counter;

//int main()
//{
//	ifstream file("day1.input");
//	int num, prevNum, counter;
//	counter = -1;
//	while (file >> num)
//	{
//		if (num > prevNum)
//			counter++;
//		prevNum = num;
//	}
//	cout << counter << endl;
//
//	return 0;
//}
//
int main()
{
	vector<int> nums;
	while (file >> num)
	{
		nums.push_back(num);
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i]+nums[i+1]+nums[i+2] < nums[i+1]+nums[i+2]+nums[i+3])
			counter++;
	}

	cout << counter << endl;
	return 0;
}
