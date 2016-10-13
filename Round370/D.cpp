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

const int N = 1e6 + 100;
const ll MOD = 1e9 + 7;


ll dp[2][N];
ll sum[N];

int main()
{
	int a, b, k, t, i, j, cur, last, n;
	scanf("%d%d%d%d", &a, &b, &k, &t);
	
	
	//fill((int*)dp, (int*)dp + 2 * (N + 11), 0);
	n = 4*t*k + 250;
	dp[0][(a - b) + n / 2] = 1;
	for (i = 1; i <= 2*t; i++)
	{
		cur = i & 1;
		last = 1 - cur;
		sum[0] = dp[last][0];
		for (j = 1; j <= n; j++)
		{
			//sum[j] = (sum[j - 1] + dp[last][j]) % MOD;
			sum[j] = (sum[j - 1] + dp[last][j]);
		}
		for (j = 0; j <= n; j++)
		{
			dp[cur][j] = ((sum[min(j + k, n)] - sum[max(j - k, 0)] + dp[last][max(j - k, 0)]) % MOD + MOD) % MOD;
		}
	}
	
	ll ans = 0;
	for (i = n / 2 + 1; i <= n; i++)
	{
		ans = (ans + dp[0][i]) % MOD;
	}
	
	printf("%lld\n", ans);
	return 0;
}