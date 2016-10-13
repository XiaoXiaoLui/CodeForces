#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1005;
const int M = 1e5 + 50;

char a[N][N];
int rowSum[N][N];
int colSum[N][N];
char dir[M];
int len[M];

inline void nextLine()
{
	while (getchar() != '\n');
}

int main()
{
	int n, m, kNum, i, j, k, row, col, oldI, oldJ;
	vector<pii> posVec;
	vector<char> ans;
	
	scanf("%d%d", &n, &m);
	nextLine();
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &a[i][j]);
			if (a[i][j] >= 'A' && a[i][j] <= 'Z')
			{
				posVec.push_back(mp(i, j));
			}
		}
		nextLine();
	}
	
	scanf("%d", &kNum);
	nextLine();
	for (k = 0; k < kNum; k++)
	{
		scanf("%c%d", &dir[k], &len[k]);
		nextLine();
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			rowSum[i][j] = rowSum[i][j - 1];
			colSum[i][j] = colSum[i - 1][j];
			if (a[i][j] == '#')
			{
				rowSum[i][j]++;
				colSum[i][j]++;
			}
		}
	}

	for (vector<pii>::iterator iter = posVec.begin(); iter != posVec.end(); iter++)
	{
		row = iter->first;
		col = iter->second;
		bool ok = true;
		
		oldI = row;
		oldJ = col;
		int c;
		for (k = 0; k < kNum && ok; k++, oldI = i, oldJ = j)
		{
			switch (dir[k])
			{
			case 'N':
				i = max(1, oldI - len[k]);
				j = oldJ;
				
				c = colSum[oldI][j] - colSum[i - 1][j];
				break;
			case 'S':
				i = min(n, oldI + len[k]);
				j = oldJ;
				c = colSum[i][j] - colSum[oldI - 1][j];
				break;
			case 'W':
				i = oldI;
				j = max(1, oldJ - len[k]);
				c = rowSum[i][oldJ] - rowSum[i][j - 1];
				break;
			case 'E':
				i = oldI;
				j = min(m, oldJ + len[k]);
				c = rowSum[i][j] - rowSum[i][oldJ - 1];
				break;
			}
			
			if (c != 0)
			{
				ok = false;
			}
		}
		
		if (ok)
		{
			ans.push_back(a[row][col]);
		}
	}
	
	if (ans.size() > 0)
	{
		sort(ans.begin(), ans.end());
		for (i = 0; i < ans.size(); i++)
		{
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	else
	{
		printf("no solution\n");
	}
	
	
	return 0;
}