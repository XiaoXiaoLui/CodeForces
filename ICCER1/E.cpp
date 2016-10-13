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

const ll MOD = 1e9 + 7;
const int N = 2e5 + 100;
const int M = 2e4 + 10;
const ll MOD2 = MOD * MOD;

int row[M];
int col[M];
ll ft[N];
ll inv[N];
int srt[M];
ll dp[M][24];
int p[M];

bool cmp(int i, int j)
{
	return (row[i] + col[i] < row[j] + col[j]);
}

ll mypow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	
	return res;
}

ll combine(int a, int b)
{
	return ft[a] * inv[b] % MOD * inv[a - b] % MOD;
}

ll path(int i, int j)
{
	int idx1, idx2;
	idx1 = srt[i];
	idx2 = srt[j];
	
	if (row[idx1] <= row[idx2] && col[idx1] <= col[idx2])
	{
		return combine(row[idx2] - row[idx1] + col[idx2] - col[idx1], row[idx2] - row[idx1]);
	}
	
	return 0;
}

int main()
{
	int n, m, s, kNum, i, j, k, maxNum;
	ll sum;
	scanf("%d%d%d%d", &n, &m, &kNum, &s);
	
	bool hasStart = false;
	for (i = 1; i <= kNum; i++)
	{
		scanf("%d%d", &row[i], &col[i]);
		if (row[i] == 1 && col[i] == 1)
		{
			hasStart = true;
		}
		srt[i] = i;
	}
	
	if (!hasStart)
	{
		kNum++;
		srt[kNum] = kNum;
		row[kNum] = 1;
		col[kNum] = 1;
	}
	
	sort(srt + 1, srt + 1 + kNum, cmp);
	
	fill(p, p + M, 1);
	for (i = 0; s > 1; i++)
	{
		p[i] = s;
		s = (s + 1) / 2;
	}
	maxNum = i;
	
	// convinient for path
	srt[kNum + 1] = kNum + 1;
	row[kNum + 1] = n;
	col[kNum + 1] = m;
	
	ft[0] = inv[0] = 1;
	for (i = 1; i <= n + m; i++)
	{
		ft[i] = ft[i - 1] * i % MOD;
		inv[i] = mypow(ft[i], MOD - 2);
	}
	
	for (i = kNum; i >= 1; i--)
	{
		dp[i][0] = path(i, kNum + 1);
		for (j = i + 1; j <= kNum; j++)
		{
			dp[i][0] = (dp[i][0] - path(i, j) * dp[j][0]) % MOD;
		}
		dp[i][0] = (dp[i][0] + MOD) % MOD;
	}
	

	for (i = kNum; i >= 1; i--)
	{
		sum = dp[i][0];
		for (k = 1; k <= maxNum; k++)
		{
			dp[i][k] = path(i, kNum + 1);
			for (j = i + 1; j <= kNum; j++)
			{
				dp[i][k] = (dp[i][k] - path(i, j) * dp[j][k]);
				if (dp[i][k] < 0)
				{
					dp[i][k] += MOD2;
				}
			}
			dp[i][k] = ((dp[i][k] - sum) % MOD + MOD) % MOD;
			sum += dp[i][k];
		}
		
		dp[i][maxNum + 1] = (path(i, kNum + 1) - sum) % MOD;
	}
	
	sum = 0;
	int add = hasStart ? 1 : 0;
	for (k = 0; k <= maxNum + 1; k++)
	{
		sum = (sum + dp[1][k] * p[k + add]) % MOD;
	}
	
	sum = (sum * mypow(path(1, kNum + 1), MOD - 2) % MOD + MOD) % MOD;
	
	printf("%lld\n", sum);
	return 0;
}