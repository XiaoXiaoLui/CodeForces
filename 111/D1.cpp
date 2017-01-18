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
ll inv[N];
ll dp[1005][1005];

ll mypow(ll a, ll b)
{
	if (!b)
	{
		return 1;
	}
	return (b & 1) ? a * mypow(a * a % MOD, b >> 1) % MOD : mypow(a * a % MOD, b >> 1);
}

ll comb(int a, int b)
{
	if (b < 0 || b > a || a < 0)
	{
		return 0;
	}
	
	if (!b)
	{
		return 1;
	}
	ll res = fact[a] * inv[b] % MOD * inv[a - b] % MOD;
	return res;
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
			ll cur = comb(colorNum, 2*i - j) * comb(2*i - j, i) % MOD * comb(i, j) % MOD;
			cur = cur * mypow(j, n * (m - 2)) % MOD;
			cur = cur * dp[n][i] % MOD * dp[n][i] % MOD;
			
			ans = (ans + cur) % MOD;
		}
	}
	
	cout << ans << endl;
	return 0;
}