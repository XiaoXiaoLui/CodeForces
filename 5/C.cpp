#include <iostream>


#define N 1000003

using namespace std;


char seq[N];


int main()
{
	cin >> seq;
	int i = 0;
	int sum = 0;
	int curLen = 0;
	int maxLen = 0;
	int maxLenNum = 1;
	
	int seqLen = 0;
	int start = 0;
	
	for (i = 0; seq[i] != '\0'; i++)
	{
		if (seq[i] == '(')
		{
			sum++;
		}
		else
		{
			sum--;
		}
		curLen++;
		
		if (sum == 0)
		{
			// find a regular one
			if (curLen > maxLen)
			{
				maxLen = curLen;
				maxLenNum = 1;
			}
			else if (curLen == maxLen)
			{
				maxLenNum++;
			}
		}
		else if (sum < 0)
		{
			curLen = 0;
			sum = 0;
			start = i + 1;
		}
		
		seqLen++;
	}
	
	// may
	if (sum > 0)
	{
		sum = 0;
		curLen = 0;
		
		for (i = seqLen - 1; i >= start; i--)
		{
			if (seq[i] == '(')
			{
				sum--;
			}
			else
			{
				sum++;
			}
			curLen++;
			
			if (sum == 0)
			{
				// find a regular one
				if (curLen > maxLen)
				{
					maxLen = curLen;
					maxLenNum = 1;
				}
				else if (curLen == maxLen)
				{
					maxLenNum++;
				}
			}
			else if (sum < 0)
			{
				curLen = 0;
				sum = 0;
			}
		}
	}
	
	cout << maxLen << " " << maxLenNum << endl;
	
	return 0;
}