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

const int N = 1005;
const int M = 12;

ll MOD;
ll dp[N][M][N];
ll curCom[M];
ll inv2[M];

inline ll mypow(ll a, ll b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = ((ll)res * a) % MOD;
		}
		a = ((ll)a * a) % MOD;
		b >>= 1;
	}
	
	return res;
}

inline ll cmb(ll a, ll b)
{
	ll d1, d2;
	
	if (a < b)
	{
		return 0;
	}
	
	d1 = 1;
	d2 = inv2[b];
	while (b)
	{
		d1 = (ll)d1 * a % MOD;
		b--;
		a--;
	}
	
	return (ll)d1 * d2 % MOD;
}

// cal cmb(n + l - 1, l),  l = 1 ~ m
bool calCurCom(ll n, int m)
{
	if (n == 0)
	{
		return false;
	}
	
	int i;
	ll mul = 1;
	ll tmp = n;
	for (i = 1; i <= m; i++, tmp++)
	{
		mul = mul * tmp % MOD;
		curCom[i] = mul * inv2[i] % MOD;
	}
	return true;
}

int main()
{
	int n, d, i, j,k, l, m;
	scanf("%d%d%lld", &n, &d, &MOD);
	
	if (n <= 2)
	{
		printf("1\n");
		return 0;
	}
	
	ll tmp = 1;
	inv2[1] = 1;
	for (i = 2; i <= d; i++)
	{
		tmp = tmp * i;
		inv2[i] = mypow(tmp, MOD - 2);
	}
	

	for (k = 0; k <= n; k++)
	{
		dp[1][0][k] = 1;
	}
	
	
	for (i = 2; i <= d + 1; i++)
	{
		for (k = 1; k <= n; k++)
		{
			dp[i][i - 1][k] = 1;
		}	
	}
	
	
	for (i = 3; i <= n; i++)
	{
		for (j = 1; j <= d && j < i - 1; j++)
		{
			for (k = 2; k <= n - 1; k++)
			{
				dp[i][j][k] = dp[i][j][k - 1];
				if (calCurCom(dp[k][d - 1][k - 1], j))
				{
					for (l = 1; l <= j && l*k < i; l++)
					{
						//tmp = (ll)dp[i - k*l][j - l][k - 1] * cmb(dp[k][d - 1][k - 1] + l - 1, l) % MOD;
						tmp = (ll)dp[i - k*l][j - l][k - 1] * curCom[l] % MOD;
						dp[i][j][k] = ((ll)dp[i][j][k] + tmp) % MOD;
					}
				}
			}
		}
	}
	
	ll ans = 0;
	ans = dp[n][d][(n + 1) / 2 - 1];
	//ans = dp[n][d][n / 2];
	if ((n & 1) == 0)
	{
		ans = ((ll)ans + cmb(dp[n / 2][d - 1][n / 2 - 1] + 1, 2)) % MOD;
	}
	
	printf("%lld\n", ans);
	return 0;
}