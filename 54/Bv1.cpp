#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

inline void nextLine()
{
	while (getchar() != '\n');
}

const int N = 25;

int n, m;
char a[N][N];



pii tran1(int i, int j, int x, int y)
{
	return mp(i, j);
}

pii tran2(int i, int j, int x, int y)
{
	return mp(x - 1 - i, y - 1 - j);
}

pii tran3(int i, int j, int x, int y)
{
	if (x != y)
	{
		return mp(i, j);
	}
	
	return mp(j, x - 1 - i);
}

pii tran4(int i, int j, int x, int y)
{
	if (x != y)
	{
		return mp(i, j);
	}
	
	return mp(y - 1 - j, i);
}

typedef pii (*TranFun)(int i, int j, int x, int y);
TranFun TF[4] = {tran1, tran2, tran3, tran4};

inline bool isDiff(int row1, int col1, int row2, int col2, int x, int y)
{
	int i, j, k;
	bool bSame;
	pii tranPos;
	for (k = 0; k < 4; k++)
	{
		bSame = true;
		for (i = 0; i < x && bSame; i++)
		{
			for (j = 0; j < y; j++)
			{
				tranPos = (*TF[k])(i, j, x, y);
				if (a[row1 + i][col1 + j] != a[row2 + tranPos.first][col2 + tranPos.second])
				{
					bSame = false;
					break;
				}					
			}
		}
		
		if (bSame)
		{
			return false;
		}
	}
	
	return true;
}


inline bool isGood(int x, int y)
{
	if (n % x || m % y)
	{
		return false;
	}
	
	bool res = true;
	int i1, i2, j1, j2, k;
	for (i1 = 0; i1 < n && res; i1 += x)
	{
		for (j1 = 0; j1 < m && res; j1 += y)
		{
			for (i2 = 0; i2 < n && res; i2 += x)
			{
				for (j2 = 0; j2 < m; j2 += y)
				{
					if (i2 == i1 && j2 == j1)
					{
						continue;
					}
					
					if (!isDiff(i1, j1, i2, j2, x, y))
					{
						res = false;
						break;
					}
				}
			}
		}
	}
	
	return res;
}

int main()
{
	int x, y;
	int minArea = 1000;
	int ansNum = 0;
	pii ans;
	
	scanf("%d%d", &n, &m);
	nextLine();
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < m; y++)
		{
			scanf("%c", &a[x][y]);
		}
		nextLine();
	}
	
	for (x = 1; x <= n; x++)
	{
		for (y = 1; y <= m; y++)
		{
			if (isGood(x, y))
			{
				ansNum++;
				if (x * y < minArea || x * y == minArea && x < ans.first)
				{
					minArea = x * y;
					ans = mp(x, y);
				}
			}
		}
	}
	
	printf("%d\n", ansNum);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}