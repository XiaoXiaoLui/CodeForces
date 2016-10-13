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

const int N = 30;

int a[N][N];
bool wr[N][N];
int c[N];
vector<pii> pos;

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	int idx = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] != j)
			{
				wr[i][j] = true;
				c[i]++;
				if (c[i] > 4)
				{
					printf("NO\n");
					return 0;
				}
				if (c[i] > c[idx])
				{
					idx = i;
				}
			}
		}
	}
	
	if (c[idx] <= 2)
	{
		printf("YES\n");
	}
	else
	{
		
		if (c[idx] == 3)
		{
			int p[3];
			int len = 0;
			for (j = 1; j <= m; j++)
			{
				if (wr[idx][j])
				{
					p[len++] = j;
				}
			}
			pos.push_back(mp(p[0], p[1]));
			pos.push_back(mp(p[1], p[2]));
			pos.push_back(mp(p[0], p[2]));
		}
		else if (c[idx] == 4)
		{
			for (j = 1; j <= m; j++)
			{
				if (wr[idx][j])
				{
					pos.push_back(mp(j, a[idx][j]));
					wr[idx][a[idx][j]] = false;
				}
			}
		}
		
		bool ok;
		for (int k = 0; k < pos.size(); k++)
		{
			ok = true;
			fill(c, c + N, 0);
			for (i = 1; i <= n; i++)
			{
				swap(a[i][pos[k].first], a[i][pos[k].second]);
			}
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= m; j++)
				{
					if (a[i][j] != j)
					{
						c[i]++;
						if (c[i] >= 3)
						{
							ok = false;
						}
					}
				}
			}
			for (i = 1; i <= n; i++)
			{
				swap(a[i][pos[k].first], a[i][pos[k].second]);
			}
			
			if (ok)
			{
				printf("YES\n");
				return 0;
			}
		}
		printf("NO\n");
	}
	
	return 0;
}