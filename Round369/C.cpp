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

const int N = 110;
const ll LINF = 1e18;

ll w[N][N];
int c[N];
ll dp[N][N][N];
ll mn[N][N][N];

int main()
{
	int n, m, num, i, j, k;
	scanf("%d%d%d", &n, &m, &num);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%lld", &w[i][j]);
		}
	}
	
	fill((ll*)dp, (ll*)dp + N*N*N, LINF);
	fill((ll*)dp[0][0], (ll*)dp[0][0] + N, 0);
	
	fill((ll*)mn, (ll*)mn + N*N*N, LINF);
	fill((ll*)mn[0][0], (ll*)mn[0][0] + N, 0);
	
	for (i = 1; i <= n; i++)
	{
		if (c[i] != 0)
		{
			k = c[i];
			for (j = 1; j <= num; j++)
			{
				//fill((ll*)dp[i][j], (ll*)dp[i][j] + N, LINF);
				dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
				dp[i][j][k] = min(dp[i][j][k], mn[i - 1][j - 1][k]);
			}
		}
		else
		{
			for (j = 1; j <= num; j++)
			{
				for (k = 1; k <= m; k++)
				{
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + w[i][k]);
					dp[i][j][k] = min(dp[i][j][k], mn[i - 1][j - 1][k] + w[i][k]);
				}
			}
		}	
		
		// updae mn
		int minIndex1, minIndex2;
		for (j = 1; j <= num; j++)
		{
			minIndex1 = 0;
			minIndex2 = 0;
			for (k = 1; k <= m; k++)
			{
				if (dp[i][j][k] < dp[i][j][minIndex1])
				{
					minIndex2 = minIndex1;
					minIndex1 = k;
				}
				else if (dp[i][j][k] < dp[i][j][minIndex2])
				{
					minIndex2 = k;
				}
			}
			
			for (k = 1; k <= m; k++)
			{
				if (k == minIndex1)
				{
					mn[i][j][k] = dp[i][j][minIndex2];
				}
				else
				{
					mn[i][j][k] = dp[i][j][minIndex1];
				}
			}
		}
	}
	
	ll ans = LINF;
	for (k = 1; k <= m; k++)
	{
		ans = min(ans, dp[n][num][k]);
	}
	
	if (ans < LINF)
	{
		printf("%lld\n", ans);
	}
	else
	{
		printf("-1\n");
	}
	

	return 0;
}


/*
dp[i][j][k]
dp[i - 1][j][k]
dp[i - 1][j - 1][!k]
*/