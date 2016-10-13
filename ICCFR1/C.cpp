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

const int N = 1e5 + 100;

vector<int> diag1[N*2];
vector<int> diag2[N*2];
int X[N], Y[N];
ll ans[N];

int main()
{
	int n, m, kNum, i, x, y, d1, d2, turn, idx, oldX, loop;
	ll t;
	
	
	fill((ll*)ans, (ll*)ans + N, -1);
	scanf("%d%d%d", &n, &m, &kNum);
	for (i = 1; i <= kNum; i++)
	{
		scanf("%d%d", &x, &y);
		X[i] = x;
		Y[i] = y;
		diag1[x + y].push_back(i);
		diag2[x - y + m].push_back(i);
	}
	
	x = 0, y = 0;
	d1 = 0;
	d2 = m;
	t = 0;
	turn = 0;
	
	loop = (n + m + 10) * 2;
	while (loop--)
	{
		if (turn)
		{
			for (i = 0; i < diag1[d1].size(); i++)
			{
				idx = diag1[d1][i];
				if (ans[idx] != -1)
				{
					continue;
				}
				ans[idx] = abs(X[idx] - x) + t;
			}
			
			oldX = x;
			if (x == 0)
			{
				x = min(d1, n);
				y = d1 - x;
			}
			else if (x == n)
			{
				x = max(0, d1 - m);
				y = d1 - x;
			}
			else if (y == 0)
			{
				y = min(d1, m);
				x = d1 - y;
			}
			else if (y == m)
			{
				y = max(d1 - n, 0);
				x = d1 - y;
			}
			t += abs(x - oldX);
			turn = !turn;
			d1 = x + y;
			d2 = x - y + m;
		}
		else
		{
			for (i = 0; i < diag2[d2].size(); i++)
			{
				idx = diag2[d2][i];
				if (ans[idx] != -1)
				{
					continue;
				}
				ans[idx] = abs(X[idx] - x) + t;
			}
			
			oldX = x;
			if (x == 0)
			{
				x = min(d2, n);
				y = x + m - d2;
			}
			else if (x == n)
			{
				x = max(0, d2 - m);
				y = x + m - d2;
			}
			else if (y == 0)
			{
				y = min(n + m - d2, m);
				x = y + d2 - m;
			}
			else if (y == m)
			{
				y = max(m - d2, 0);
				x = y + d2 - m;
			}
			t += abs(x - oldX);
			turn = !turn;
			d1 = x + y;
			d2 = x - y + m;
		}	
		
		if (x == 0 && y == 0 || x == n && y == 0 || x == 0 && y == m || x == n && y == m)
		{
			break;
		}
	}
	
	for (i = 1; i <= kNum; i++)
	{
		printf("%lld\n", ans[i]);
	}
	
	return 0;
}