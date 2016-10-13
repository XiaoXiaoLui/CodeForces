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
#define mpp make_pair<pii, pii>

typedef long long ll;

const int N = 60;
const int M = 2600;

struct Distance
{
	Distance() 
	{
		
	}
	Distance(int cc1, int cc2, int ddi) : c1(cc1), c2(cc2), di(ddi)
	{
		
	}
	int c1;
	int c2;
	int di;
	
	bool operator < (const Distance &other) const
	{
		if (di != other.di)
		{
			return di < other.di;
		}
		
		return c1*M + c2 < other.c1*M + other.c2;
	}
};

int n, m;
char a[N][N];
char ans[N][N];
int com[N][N];
int comCount[M];
bool erased[M];


const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


inline bool valid(int i, int j)
{
	if (i < 0 || i > n + 1 || j < 0 || j > m + 1)
	{
		return false;
	}
	return true;
}


void dfs(int i, int j, int c)
{
	com[i][j] = c;
	comCount[c]++;
	
	int ii, jj, k;
	for (k = 0; k < 4; k++)
	{
		ii = i + DIR[k][0];
		jj = j + DIR[k][1];
		if (valid(ii, jj) && a[ii][jj] == '.' && !com[ii][jj])
		{
			dfs(ii, jj, c);
		}
	}
}

void nextLine()
{
	while (getchar() != '\n');
}

int main()
{
	int kNum, i1, j1, i2, j2, i, j, c, c1, c2, c3, c4, tmp, curK, ii, jj;
	scanf("%d%d%d", &n, &m, &kNum);
	
	nextLine();
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &a[i][j]);
			ans[i][j] = a[i][j];
		}
		nextLine();
	}
	for (i = 0; i <= n + 1; i++)
	{
		a[i][0] = '.';
		a[i][m + 1] = '.';
	}
	for (j = 0; j <= m + 1; j++)
	{
		a[0][j] = '.';
		a[n + 1][j] = '.';
	}
	
	dfs(0, 0, M);
	
	c = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == '.' && !com[i][j])
			{
				++c;
				dfs(i, j, c);
			}
		}	
	}
	curK = c;
	
	set<pii> S;
	set<pii>::iterator iter;
	for (i = 1; i <= curK; i++)
	{
		S.insert(mp(comCount[i], i));
	}
	
	for (iter = S.begin(); iter != S.end() && curK > kNum; iter++)
	{
		erased[iter->second] = true;
		curK--;
	}

	int count = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			c = com[i][j];
			if (ans[i][j] == '.' && erased[c])
			{
				count++;
				ans[i][j] = '*';
			}
			
		}
		
	}
	
	printf("%d\n", count);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}