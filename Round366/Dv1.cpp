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

const ll LINF = 1e18;
const int N = 5050;
ll dp[N][N];
ll x[N], a[N], b[N], c[N], d[N];

int main()
{
	int n, s, e, i, j;
	scanf("%d%d%d", &n, &s, &e);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &x[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &b[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &c[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &d[i]);
	}
	
	fill((ll*)dp, (ll*)dp + N*N, LINF);
	
	int hasStart = 0, hasEnd = 0;
	if (s == 1)
	{
		hasStart = 1;
	}
	if (e == 1)
	{
		hasEnd = 1;
	}
	
	if (hasStart)
	{
		dp[1][1] = d[1];
	}
	else if (hasEnd)
	{
		dp[1][1] = b[1];
	}
	else
	{
		dp[1][2] = b[1] + d[1];
	}
	
	for (i = 2; i <= n; i++)
	{
		for (j = 2 - (hasStart ^ hasEnd); j <= n; j++)
		{
			if (dp[i - 1][j] == LINF)
			{
				continue;
			}
			dp[i - 1][j] += (x[i] - x[i - 1]) * j;
			if (i == s)
			{
				dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + d[i]);
				dp[i][j - 1] = min(dp[i][j - 1], dp[i - 1][j] + c[i]);
			}
			else if (i == e)
			{
				dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + b[i]);
				dp[i][j - 1] = min(dp[i][j - 1], dp[i - 1][j] + a[i]);
			}
			else
			{
				if (j >= 2)
				{
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + min(a[i] + d[i], b[i] + c[i]));
				}
				else if (hasStart)
				{
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i] + d[i]);
				}
				else
				{
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + b[i] + c[i]);
				}
				
				dp[i][j + 2] = min(dp[i][j + 2], dp[i - 1][j] + d[i] + b[i]);
				if (j >= 2)
				{
					dp[i][j - 2] = min(dp[i][j - 2], dp[i - 1][j] + c[i] + a[i]);
				}
			}
		}
		
		if (i == s)
		{
			hasStart = 1;
		}
		if (i == e)
		{
			hasEnd = 1;
		}
	}
	
	printf("%lld\n", dp[n][0]);
	return 0;
}