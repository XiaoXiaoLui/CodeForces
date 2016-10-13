#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>


using namespace std;


#define BUFSIZE 5

struct Coord
{
	int x;
	int y;
};

int main()
{
	char strStart[BUFSIZE];
	char strEnd[BUFSIZE];
	Coord startPos;
	Coord endPos;
	
	cin >> strStart >> strEnd;
	
	startPos.x = strStart[0] - 'a';
	startPos.y = strStart[1] - '0';
	
	endPos.x = strEnd[0] - 'a';
	endPos.y = strEnd[1] - '0';
	
	int offsetX = endPos.x - startPos.x;
	int offsetY = endPos.y - startPos.y;
	
	int i = 0;
	
	char firstDir[BUFSIZE];
	char secondDir[BUFSIZE];
	int firstSteps = 0;
	int secondSteps = 0;
	
	if (offsetX <= 0 && offsetY <= 0)
	{
		if (abs(offsetX) >= abs(offsetY))
		{
			strcpy(firstDir, "LD");
			strcpy(secondDir, "L");
			
			firstSteps = abs(offsetY);
			secondSteps = abs(offsetX) - abs(offsetY);
		}
		else
		{
			strcpy(firstDir, "LD");
			strcpy(secondDir, "D");
			
			firstSteps = abs(offsetX);
			secondSteps = abs(offsetY) - abs(offsetX);
		}
	}
	else if (offsetX <= 0 && offsetY > 0)
	{
		if (abs(offsetX) >= abs(offsetY))
		{
			strcpy(firstDir, "LU");
			strcpy(secondDir, "L");
			
			firstSteps = abs(offsetY);
			secondSteps = abs(offsetX) - abs(offsetY);
		}
		else
		{
			strcpy(firstDir, "LU");
			strcpy(secondDir, "U");
			
			firstSteps = abs(offsetX);
			secondSteps = abs(offsetY) - abs(offsetX);
		}
	}
	else if (offsetX > 0 && offsetY <= 0)
	{
		if (abs(offsetX) >= abs(offsetY))
		{
			strcpy(firstDir, "RD");
			strcpy(secondDir, "R");
			
			firstSteps = abs(offsetY);
			secondSteps = abs(offsetX) - abs(offsetY);
		}
		else
		{
			strcpy(firstDir, "RD");
			strcpy(secondDir, "D");
			
			firstSteps = abs(offsetX);
			secondSteps = abs(offsetY) - abs(offsetX);
		}
	}
	else
	{
		if (abs(offsetX) >= abs(offsetY))
		{
			strcpy(firstDir, "RU");
			strcpy(secondDir, "R");
			
			firstSteps = abs(offsetY);
			secondSteps = abs(offsetX) - abs(offsetY);
		}
		else
		{
			strcpy(firstDir, "RU");
			strcpy(secondDir, "U");
			
			firstSteps = abs(offsetX);
			secondSteps = abs(offsetY) - abs(offsetX);
		}
	}
	
	
	cout << firstSteps + secondSteps << endl;
	for (i = 0; i < firstSteps; i++)
	{
		cout << firstDir << endl;
	}
	for (i = 0; i < secondSteps; i++)
	{
		cout << secondDir << endl;
	}
	
	return 0;
}