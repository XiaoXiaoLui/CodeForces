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

const int N = 80;
const ll MOD = 1e9 + 7;

int num[N][N];
int digit[N];
int dp[N][1 << 20];

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	string s;
	int n;
	
	cin >> n;
	cin >> s;
	
	int i, j;
	for (i = 0; i < n; i++)
	{
		digit[i + 1] = s[i] - '0';
	}
	
	for (i = 0; i <= n; i++)
	{
		for (j = i + 1; j <= n + 1; j++)
		{
			if (num[i][j - 1] > 100)
			{
				num[i][j] = 100;
			}
			else
			{
				num[i][j] = num[i][j - 1] * 2 + digit[j];
			}
		}
	}
	
	dp[n][0] = 1;
	for (i = n - 1; i >= 0; i--)
	{
		dp[i][0] = 1;
		for (j = i + 1; j <= n && num[i][j] == 0; j++);
		if (j > n)
		{
			
			continue;
		}
		
		for (; j <= n && num[i][j] <= 20; j++)
		{
			int bit = num[i][j] - 1;
			for (int mask = 0; mask < 1 << 20; mask++)
			{
				int nextMask = ((1 << bit) | mask);
				dp[i][nextMask] = ((ll)dp[i][nextMask] + dp[j][mask]) % MOD;
			}
		}
	}
	
	ll ans = 0;
	
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= 20; j++)
		{
			ans = (ans + dp[i][(1 << j) - 1]) % MOD;
		}
	}
	/*
	for (j = 1; j <= 20; j++)
	{
		ans = (ans + dp[0][(1 << j) - 1]) % MOD;
	}*/
	
	cout << ans << endl;
	
	return 0;
}