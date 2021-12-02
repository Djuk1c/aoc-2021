#include <fstream>
#include <iostream>
#include <string>

using namespace std;
ifstream file("day2.input");
int pos[3] = {0, 0, 0};

int main()
{
	string a;
	int b;

	while (file >> a >> b)
	{
		if (a == "forward")
		{
			pos[0]+= b;
			pos[1]+= pos[2]*b;
		}
		else if (a == "down")
			pos[2]+= b;
		else if (a == "up")
			pos[2]-= b;
	}

	cout << pos[0]*pos[1] << endl;

	return 0;
}
