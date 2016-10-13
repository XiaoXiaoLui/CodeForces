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
int d[M][M];
pair< pii , pii > au[M][M];

const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


inline bool valid(int i, int j)
{
	if (i < 1 || i > n || j < 1 || j > m)
	{
		return false;
	}
	return true;
}

inline int dist(int i1, int j1, int i2, int j2)
{
	return abs(i1 - i2) + abs(j1 - j2) - 1;
}

void dfs(int i, int j, int c)
{
	com[i][j] = c;
	
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
	
	fill((int*)d, (int*)d + M*M, 1e9);
	for (i1 = 1; i1 <= n; i1++)
	{
		for (j1 = 1; j1 <= m; j1++)
		{
			c1 = com[i1][j1];
			for (i2 = 1; i2 <= n; i2++)
			{
				for (j2 = 1; j2 <= m; j2++)
				{
					c2 = com[i2][j2];
					if (c1 >= c2)
					{
						continue;
					}
					tmp = dist(i1, j1, i2, j2);
					if (tmp < d[c1][c2])
					{
						d[c1][c2] = tmp;
						au[c1][c2] = mpp(mp(i1, j1), mp(i2, j2));
					}
				}
			}
		}
	}
	
	set<Distance> S;
	for (c1 = 1; c1 <= curK; c1++)
	{
		for (c2 = c1 + 1; c2 <= curK; c2++)
		{
			S.insert(Distance(c1, c2, d[c1][c2]));
		}
	}
	
	int count = 0;
	set<Distance>::iterator iter;
	Distance tmpDist;
	while (curK > kNum)
	{
		c1 = S.begin()->c1;
		c2 = S.begin()->c2;
		S.erase(S.begin());
		i1 = au[c1][c2].first.first;
		j1 = au[c1][c2].first.second;
		i2 = au[c1][c2].second.first;
		j2 = au[c1][c2].second.second;
		
		for (iter = S.begin(); iter != S.end(); iter++)
		{
			c3 = iter->c1;
			c4 = iter->c2;
			tmp = iter->di;
			if (c3 == c2)
			{
				S.erase(iter);
				if (tmp < d[c1][c4])
				{
					S.erase(Distance(c1, c4, d[c1][c4]));
					S.insert(Distance(c1, c4, tmp));
					d[c1][c4] = tmp;
					au[c1][c4] = au[c2][c4];
				}
			}
			else if (c4 == c2)
			{
				S.erase(iter);
				if (c1 < c3)
				{
					if (tmp < d[c1][c3])
					{
						S.erase(Distance(c1, c3, d[c1][c3]));
						S.insert(Distance(c1, c3, tmp));
						d[c1][c3] = tmp;
						au[c1][c3] = au[c3][c2];
					}
				}
				else
				{
					if (tmp < d[c3][c1])
					{
						S.erase(Distance(c3, c1, d[c3][c1]));
						S.insert(Distance(c3, c1, tmp));
						d[c3][c1] = tmp;
						au[c3][c1] = au[c3][c2];
					}
				}
			}
		}
		
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (com[i][j] = c2)
				{
					com[i][j] = c1;
				}
			}
		}
		
		if (i1 > i2)
		{
			swap(i1, i2);
			swap(j1, j2);
		}
		for (i = i1 + 1; i <= i2; i++)
		{
			if (ans[i][j1] == '.')
			{
				continue;
			}
			
			count++;
			ans[i][j1] = '.';
			for (ii = 1; ii <= n; ii++)
			{
				for (jj = 1; jj <= m; jj++)
				{
					c3 = com[ii][jj];
					if (c3 == c1 || c3 == c2)
					{
						continue;
					}
					tmp = dist(i, j1, ii, jj);
					if (c1 < c3)
					{
						if (tmp < d[c1][c3])
						{
							iter = S.find(Distance(c1, c3, d[c1][c3]));
							S.erase(iter);
							S.insert(Distance(c1, c3, tmp));
							d[c1][c3] = tmp;
							au[c1][c3] = mpp(mp(i, j1), mp(ii, jj));
						}
					}
					else
					{
						if (tmp < d[c3][c1])
						{
							iter = S.find(Distance(c3, c1, d[c3][c1]));
							S.erase(iter);
							S.insert(Distance(c3, c1, tmp));
							d[c3][c1] = tmp;
							au[c3][c1] = mpp(mp(ii, jj), mp(i, j1));
						}
					}
				}
			}
		}
		
		int row = i2;
		if (j1 > j2)
		{
			swap(i1, i2);
			swap(j1, j2);
		}
		for (j = j1; j <= j2; j++)
		{
			if (ans[row][j] == '.')
			{
				continue;
			}
			
			count++;
			ans[row][j] = '.';
			for (ii = 1; ii <= n; ii++)
			{
				for (jj = 1; jj <= m; jj++)
				{
					c3 = com[ii][jj];
					if (c3 == c1 || c3 == c2)
					{
						continue;
					}
					tmp = dist(row, j, ii, jj);
					if (c1 < c3)
					{
						if (tmp < d[c1][c3])
						{
							iter = S.find(Distance(c1, c3, d[c1][c3]));
							S.erase(iter);
							S.insert(Distance(c1, c3, tmp));
							d[c1][c3] = tmp;
							au[c1][c3] = mpp(mp(row, j), mp(ii, jj));
						}
					}
					else
					{
						if (tmp < d[c3][c1])
						{
							iter = S.find(Distance(c3, c1, d[c3][c1]));
							S.erase(iter);
							S.insert(Distance(c3, c1, tmp));
							d[c3][c1] = tmp;
							au[c3][c1] = mpp(mp(ii, jj), mp(row, j));
						}
					}
				}
			}
		}
		curK--;
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