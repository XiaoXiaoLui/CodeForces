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

const ll LINF = 1e18;
const int N = 1e5 + 100;

string s[N];
string rev[N];
ll c[N];
ll dp[N][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int n, i;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	
	for (i = 1; i <= n; i++)
	{
		cin >> s[i];
		rev[i] = s[i];
		reverse(rev[i].begin(), rev[i].end());
	}
	
	bool ok = true;
	fill((ll*)dp, (ll*)dp + 2*N, LINF);
	dp[1][0] = 0;
	dp[1][1] = c[1];
	for (i = 2; i <= n; i++)
	{
		if (s[i - 1] <= s[i] && dp[i - 1][0] != LINF)
		{
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		}
		if (rev[i - 1] <= s[i] && dp[i - 1][1] != LINF)
		{
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		}
		
		if (s[i - 1] <= rev[i] && dp[i - 1][0] != LINF)
		{
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
		}
		if (rev[i - 1] <= rev[i] && dp[i - 1][1] != LINF)
		{
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
		}
		
		if (dp[i][0] == LINF && dp[i][1] == LINF)
		{
			ok = false;
			break;
		}
	}
	
	ll ans = 1e18;
	if (ok)
	{
		if (dp[n][0] != LINF)
		{
			ans = min(ans, dp[n][0]);
		}
		if (dp[n][1] != LINF)
		{
			ans = min(ans, dp[n][1]);
		}
		cout << ans << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	
	return 0;
}