#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1010;
char a[N][N];

inline void nextLine()
{
	while (getchar() != '\n');
}

bool fillPos(int row, int col, bool bVertical)
{
	char ch;
	int i, j;
	bool ok;
	if (bVertical)
	{
		for (ch = 'a'; ch <= 'd'; ch++)
		{
			ok = true;
			if (a[row - 1][col] == ch || a[row + 3][col] == ch)
			{
				ok = false;
			}
			for (i = row; i <= row + 2; i++)
			{
				if (a[i][col - 1] == ch || a[i][col + 1] == ch)
				{
					ok = false;
				}
			}
			if (ok)
			{
				break;
			}
		}
		
		if (!ok)
		{
			return false;
		}
		
		for (i = row; i <= row + 2; i++)
		{
			a[i][col] = ch;
		}
	}
	else
	{
		for (ch = 'a'; ch <= 'd'; ch++)
		{
			ok = true;
			if (a[row][col - 1] == ch || a[row][col + 3] == ch)
			{
				ok = false;
			}
			for (j = col; j <= col + 2; j++)
			{
				if (a[row - 1][j] == ch || a[row + 1][j] == ch)
				{
					ok = false;
				}
			}
			if (ok)
			{
				break;
			}
		}
		
		if (!ok)
		{
			return false;
		}
		
		for (j = col; j <= col + 2; j++)
		{
			a[row][j] = ch;
		}
	}
	
	return true;
}

int main()
{
	int n, m, i, j, k;
	char ch;
	bool ok = true;
	scanf("%d%d", &n, &m);
	nextLine();
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &ch);
			if (ch == 'b')
			{
				a[i][j] = '1';
			}
			else if (ch == 'w')
			{
				a[i][j] = '0';
			}
			else
			{
				a[i][j] = ch;
			}
		}
		nextLine();
	}
	
	for (i = 1; i <= n && ok; i++)
	{
		for (j = 1; j <= m && ok; j++)
		{
			if (a[i][j] != '0' && a[i][j] != '1')
			{
				continue;
			}
			
			if (a[i][j] == '1')
			{
				ok = false;
				break;
			}
			
			if (a[i][j + 1] == '1' && a[i][j + 2] == '0')
			{
				if (!fillPos(i, j, false))
				{
					ok = false;
				}
			}
			else if (a[i + 1][j] == '1' && a[i + 2][j] == '0')
			{
				if (!fillPos(i, j, true))
				{
					ok = false;
				}
			}
			else
			{
				ok = false;
			}
		}
	}
	
	if (!ok)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}
	
	printf("\n");
	return 0;
}