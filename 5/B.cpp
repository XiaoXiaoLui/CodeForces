#include <iostream>
#include <string>

using namespace std;


#define N 1003

string lines[N];

void printX(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << '*';
	}
}

void printSpaces(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ' ';
	}
}

int main()
{
	string line;
	int maxLineLen = 0;
	int num = 0;
	int numX = 0;
	bool bLeft = true;
	
	while (getline(cin, line) && !cin.eof())
	{
		lines[num++] = line;
		
		if (line.length() > maxLineLen)
		{
			maxLineLen = line.length();
		}
	}
	maxLineLen += 2;
	
	printX(maxLineLen);
	cout << endl;
	
	for (int i = 0; i < num; i++)
	{
		numX = maxLineLen - lines[i].length() - 2;
		printX(1);
		if (lines[i].length() == 0)
		{
			printSpaces(numX);
		}
		else if ((numX & 1) == 0) // can divide into 2 equal part
		{
			printSpaces(numX >> 1);
			cout << lines[i];
			printSpaces(numX >> 1);
		}
		else if (bLeft)
		{
			printSpaces(numX >> 1);
			cout << lines[i];
			printSpaces((numX >> 1) + 1);		
			
			bLeft = !bLeft;
		}
		else
		{
			printSpaces((numX >> 1) + 1);
			cout << lines[i];
			printSpaces(numX >> 1);
			bLeft = !bLeft;
		}
		printX(1);
		cout << endl;
	}

	printX(maxLineLen);
	cout << endl;
	
	return 0;
}