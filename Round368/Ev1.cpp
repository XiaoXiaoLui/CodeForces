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

const int N = 2005;
const int MAX_QNUM = 1e6 + 5;

struct Lamp
{
	Lamp() : row(-1), col(-1), w(0)
	{
	}
	Lamp(int ii, int jj, int ww) : row(ii), col(jj), w(ww)
	{
		
	}
	
	int row;
	int col;
	int w;
};

struct Garland
{
	Garland() : on(true)
	{
	}
	
	bool on;
	
	int len;
	Lamp lamp[N];
	ll sum[N];
};

Garland g[N];
pii a[N][N];

vector<ll> ans;
int main()
{
	int n, m, k, len, i, j, row, col, w, qNum, x1, y1, x2, y2;
	ll sum;
	char type[20];
	scanf("%d%d%d", &n, &m, &k);
	
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &len);
		g[i].len = len;
		for (j = 1; j <= len; j++)
		{
			scanf("%d%d%d", &row, &col, &w);
			g[i].lamp[j] = Lamp(row, col, w);
			a[row][col] = mp(i, j);
			g[i].sum[j] = g[i].sum[j - 1] + w;
			
		}
	}
	
	scanf("%d", &qNum);
	while (qNum--)
	{
		scanf("%s", type);
		if (type[0] == 'S')
		{
			scanf("%d", &i);
			g[i].on = !g[i].on;
		}
		else
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			sum = 0LL;
			
			// up
			for (col = y1; col <= y2; col++)
			{
				i = a[x1][col].first;
				j = a[x1][col].second;
				if (i == 0 || !g[i].on)
				{
					continue;
				}
				
				if (g[i].lamp[j].row == g[i].lamp[j - 1].row + 1)
				{
					sum -= g[i].sum[j - 1];
				}
				else if (g[i].lamp[j].row == g[i].lamp[j + 1].row + 1)
				{
					sum += g[i].sum[j];
				}
			}
			
			// down
			for (col = y1; col <= y2; col++)
			{
				i = a[x2][col].first;
				j = a[x2][col].second;
				if (i == 0 || !g[i].on)
				{
					continue;
				}
				
				if (g[i].lamp[j].row + 1 == g[i].lamp[j - 1].row)
				{
					sum -= g[i].sum[j - 1];
				}
				else if (g[i].lamp[j].row + 1 == g[i].lamp[j + 1].row)
				{
					sum += g[i].sum[j];
				}
			}
			
			// left
			for (row = x1; row <= x2; row++)
			{
				i = a[row][y1].first;
				j = a[row][y1].second;
				if (i == 0 || !g[i].on)
				{
					continue;
				}
				
				if (g[i].lamp[j].col == g[i].lamp[j - 1].col + 1)
				{
					sum -= g[i].sum[j - 1];
				}
				else if (g[i].lamp[j].col == g[i].lamp[j + 1].col + 1)
				{
					sum += g[i].sum[j];
				}
			}
			
			// right
			for (row = x1; row <= x2; row++)
			{
				i = a[row][y2].first;
				j = a[row][y2].second;
				if (i == 0 || !g[i].on)
				{
					continue;
				}
				
				if (g[i].lamp[j].col + 1 == g[i].lamp[j - 1].col)
				{
					sum -= g[i].sum[j - 1];
				}
				else if (g[i].lamp[j].col + 1 == g[i].lamp[j + 1].col)
				{
					sum += g[i].sum[j];
				}
			}
			
			for (i = 1; i <= k; i++)
			{
				Lamp lamp = g[i].lamp[g[i].len];
				if (g[i].on && lamp.row >= x1 && lamp.row <= x2 && lamp.col >= y1 && lamp.col <= y2)
				{
					sum += g[i].sum[g[i].len];
				}
			}
			
			ans.push_back(sum);
		}
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%lld\n", ans[i]);
	}
	return 0;
}