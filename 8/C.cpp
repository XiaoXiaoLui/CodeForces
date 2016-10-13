#include <iostream>

using namespace std;

#define N 16777218
#define LEN 25


struct Position
{
	int x;
	int y;
};

int D[N];
int BACK[N];
Position P[LEN];



int calLen(int index)
{
	return (P[index].x - P[0].x) * (P[index].x - P[0].x) + (P[index].y - P[0].y) * (P[index].y - P[0].y);
}

int calLen(int index1, int index2)
{
	int len = calLen(index1) + calLen(index2);
	len += (P[index1].x - P[index2].x) * (P[index1].x - P[index2].x) + (P[index1].y - P[index2].y) * (P[index1].y - P[index2].y);
	
	return len;
}

int dfs(int mask, int num, int level)
{
	if (level == 0)
	{
		return 0;
	}
	else if (D[mask] != 0)
	{
		return D[mask];
	}
	
	
	
	int minLen = 0;
	int len = 0;
	int back = 0;
	int maskNext = 0;
	
	int i = 0;
	int first = 0;
	for (i = 0; i < num; i++)
	{
		if (mask & (1 << i))
		{
			first = i;
			break;
		}
	}
	
	maskNext = mask & (~(1 << first));
	minLen = dfs(maskNext, num, level - 1) + 2 * calLen(first + 1);
	back = maskNext;

	
	for (i = first + 1; i < num; i++)
	{
		if (maskNext & (1 << i))
		{
			len = dfs(maskNext & (~(1 << i)), num, level - 2);
			len += calLen(i + 1, first + 1);
			
			if (len < minLen)
			{
				minLen = len;
				back = maskNext & (~(1 << i));
			}
		}
	}
	
	D[mask] = minLen;
	BACK[mask] = back;
	
	return minLen;	
}


int main()
{
	int num;
	int i, j;
	
	cin >> P[0].x >> P[0].y;
	cin >> num;
	for (i = 1; i <= num; i++)
	{
		cin >> P[i].x >> P[i].y;
	}

	int minLen = dfs((1 << num) - 1, num, num);
	
	cout << minLen << endl;
	cout << "0";
	for (i = (1 << num) - 1; i > 0; i = BACK[i])
	{
		for (j = 0; j < num; j++)
		{
			if ((i ^ BACK[i]) & (1 << j))
			{
				cout << " " << j + 1;
			}
		}
		cout << " 0";
	}

	return 0;
}