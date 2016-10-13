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

const int N = 1050;
int dp[N][N];
int a[10][10];

int calOnes(int x)
{
	int res = 0;
	while (x)
	{
		x = (x - 1) & x;
		res++;
	}
	return res;
}

int main()
{
	int n, u, v, i, j, k, m, leafNum;
	scanf("%d%d%d", &n, &m, &leafNum);
	
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		u--;
		v--;
		a[u][v] = a[v][u] = 1;
		dp[1 << u | 1 << v][1 << u | 1 << v] = 1;
	}
	
	for (i = 1; i < 1 << n; i++)
	{
		for (j = 1; j < 1 << n; j++)
		{
			if ((j & i) != j)
			{
				continue;
			}
			
			for (u = 0; !(j >> u & 1); u++);
			
			for (v = 0; v < n; v++)
			{
				if (a[u][v] && (i >> v & 1) && !(j >> v & 1))
				{
					dp[i][j] += dp[i & ~(1 << u)][j & ~(1 << u)] + dp[i & ~(1 << u)][(j & ~(1 << u)) | (1 << v)];
				}
			}
		}
	}
	
	ll ans = 0;;
	for (j = 1; j < 1 << n; j++)
	{
		if (calOnes(j) == leafNum)
		{
			ans += dp[(1 << n) - 1][j];
		}
	}
	
	
	printf(LLD"\n", ans);
	return 0;
}