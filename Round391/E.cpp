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

// 2^n - n^r

const ll MOD = 1e9 + 7;

const int N = 1e6 + 100;

ll dp[N][23];
bool isPrime[N];
vector<int> factor[N];


inline ll solve(int n, int r)
{
	ll res = 1;
    int cnt;
    const vector<int> &lst = factor[n];
	for (int i = 0; n != 1; i++)
	{
        cnt = 0;
        while (n % lst[i] == 0)
        {
            cnt++;
            n /= lst[i];
        }
        res *= dp[r][cnt];
        if (res >= MOD)
        {
            res %= MOD;
        }
		
	}
	
	return res;
}

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif
	int i, j, k;
	
	// precal
    dp[0][0] = 1;
	for (i = 1; i <= 20; i++)
	{
		dp[0][i] = 2;
	}
	
	for (i = 1; i < N; i++)
	{
        dp[i][0] = dp[i - 1][0];
		for (j = 1; j <= 20; j++)
		{
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            if (dp[i][j] >= MOD)
            {
                dp[i][j] -= MOD;
            }
        }
	}
    
    fill_n(isPrime, N, true);
    for (i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            factor[i].push_back(i);
            for (j = i + i; j < N; j += i)
            {
                isPrime[j] = false;
                factor[j].push_back(i);
            }
        }
    }
	
	int n, r, qNum;
	scanf("%d", &qNum);
	for (i = 1; i <= qNum; i++)
	{
		scanf("%d%d", &r, &n);
		int ret = solve(n, r);
		printf("%d\n", ret);
	}
	
	return 0;
}