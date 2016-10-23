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

const int N = 800;
const int M = 2e5 + 100;

ll a[N];
ll q[M];
ll dp[N][N];
int ans[M];
int n, m;


bool cmp(int i, int j)
{
	return q[i] > q[j];
}

// O(n^2 + mlogn)
int main()
{
	int i, j;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%lld", &q[i]);
	}
	
	fill_n((ll*) dp[n + 1], n + 1, 0);

	for (i = n; i >= 1; i--)
	{
		dp[i][0] = max(0LL, dp[i + 1][0] - a[i]);
		for (j = 1; j <= n; j++)
		{
			dp[i][j] = max(0LL, dp[i + 1][j] - a[i]);
			dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
		}
	}
	
	for (i = 1; i <= m; i++)
	{
		ll* pos = lower_bound((ll*)&dp[1][0], (ll*)&dp[1][n + 1], q[i], greater<ll>());
		ans[i] = pos - &dp[1][0];
	}
	
	for (i = 1; i <= m; i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}