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

const int N = 1e4 + 10;
const ll LINF = 1e18;
int p[N];
int s[N];
ll dp[N][2];

void check(ll &a)
{
	if (a > LINF || a < 0)
	{
		a = LINF;
	}
}

int main()
{
	int n, c, i, j;
	ll ans = 0;
	scanf("%d%d", &n, &c);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
	}
	
	
	//fill((ll*)dp, (ll*)dp + 2*N, 1e9);
	
	dp[0][0] = p[1];
	dp[1][0] = s[1];
	int t = 0;
	ans = 1e18;
	for (i = 2; i <= n; i++)
	{
		t = 1 - t;
		dp[0][t] = dp[0][1 - t] + p[i];
		//check(dp[0][t]);
		for (j = 1; j < i; j++)
		{
			dp[j][t] = min(dp[j - 1][1 - t] + s[i], dp[j][1 - t] + p[i] + (ll)j * c);
			//check(dp[j][t]);
		}
		dp[i][t] = dp[i - 1][1 - t] + s[i];
		//check(dp[i][t]);
	}
	for (j = 0; j <= n; j++)
	{
		ans = min(ans, dp[j][t]);
	}
	
	printf("%lld\n", ans);
	return 0;
}