#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;

const int N = 105;
const int M = 5005;

ll dp[N][M];
int x[N];
int y[N];

ll c[M][N];
int sum[N];
int rSum[N];
int h[N];

int main()
{
	int n, i, j, k, l;
	ll ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}		
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &y[i]);
	}
	
	for (i = 0; i < M; i++)
	{
		c[i][0] = 1;
		if (i <= 100)
		{
			c[i][i] = 1;
		}
		for (j = 1; j < min(i, N); j++)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + x[i];
	}
	for (i = n; i >= 1; i--)
	{
		rSum[i] = rSum[i + 1] + y[i] - x[i];
	}
	for (i = 1; i <= n; i++)
	{
		h[i] = x[i] + min(sum[i - 1], rSum[i]);
	}
	
	
	for (j = x[n]; j <= y[n]; j++)
	{
		dp[n][j] = 1;
	}
	for (i = n - 1;  i >= 1; i--)
	{
		for (j = x[i]; j <= h[i]; j++)
		{
			for (k = 0; k <= min(y[i], j); k++)
			{
				dp[i][j] = (dp[i][j] + c[j][k] * dp[i + 1][x[i + 1] + j - k]) % MOD;
			}
		}
	}
	ans = dp[1][x[1]];
	
	int num = sum[n];
	for (i = 1; i <= n; i++)
	{
		ans = (ans * c[num][x[i]]) % MOD;
		num -= x[i];
	}
	printf("%d\n", (int)ans);
	
}