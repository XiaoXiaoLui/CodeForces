// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e6 + 100;

ll fact[N];
ll cnk[2005];
ll c[2005][2005];
ll dp[1005][1005];
ll inv[N];

ll mypow(ll a, ll b)
{
	if (!b)
	{
		return 1;
	}
	return (b & 1) ? a * mypow(a * a % MOD, b >> 1) % MOD : mypow(a * a % MOD, b >> 1);
}



int main()
{
	// USE_IOSTREAM;
	int n, m, i, j, colorNum;
	cin >> n >> m >> colorNum;
		
	fact[0] = inv[0] = 1; 
	for (i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = mypow(fact[i], MOD - 2);
	}
	
	for (i = 0; i <= 2*n; i++)
	{
		c[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
	
	cnk[0] = 1;
	for (i = 1; i <= 2*n && i < colorNum; i++)
	{
		cnk[i] = fact[colorNum] * inv[i] % MOD * inv[colorNum - i] % MOD;
	}
	
	if (i == colorNum)
	{
		cnk[colorNum] = 1;
	}
	
	if (m == 1)
	{
		cout << mypow(colorNum, n) << endl;
		return 0;
	}
	
	dp[0][0] = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			dp[i][j] = (j * dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1;j <= n; j++)
		{
			dp[i][j] = dp[i][j] * fact[j] % MOD;
		}
	}
	
	ll ans = 0;
	for (i = 1; i <= n && i <= colorNum; i++)
	{
		int start = m == 2 ? 0 : 1;
		for (j = start; j <= i; j++)
		{
			if (2*i - j > colorNum)
			{
				continue;
			}
			ll cur = cnk[2*i - j] * c[2*i - j][i] % MOD * c[i][j] % MOD;
			cur = cur * mypow(j, n * (m - 2)) % MOD;
			cur = cur * dp[n][i] % MOD * dp[n][i] % MOD;
			
			ans = (ans + cur) % MOD;
		}
	}
	
	cout << ans << endl;
	return 0;
}