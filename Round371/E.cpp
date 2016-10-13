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

const int N = 3050;
int a[N];
int b[N];
ll dp[N][N];

int main()
{
	int n, m, i, j;
	ll ans = 0, minPre;
	
	scanf("%d", &n);
	
	set<int> S;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] -= i;
		S.insert(a[i]);
	}
	
	m = 0;
	for (set<int>::iterator iter = S.begin(); iter != S.end(); iter++)
	{
		b[++m] = *iter;
	}
	
	for (j = 1; j <= m; j++)
	{
		dp[1][j] = abs(a[1] - b[j]);
	}
	
	for (i = 2; i <= n; i++)
	{
		minPre = dp[i - 1][1];
		for (j = 1; j <= m; j++)
		{
			minPre = min(minPre, dp[i - 1][j]);
			dp[i][j] = minPre + abs(a[i] - b[j]);
		}
	}
	
	ans = 1e18;
	for (j = 1; j <= m; j++)
	{
		ans = min(ans, dp[n][j]);
	}
	
	printf("%lld\n", ans);
	return 0;
}