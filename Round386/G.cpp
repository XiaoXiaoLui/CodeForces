#include<bits/stdc++.h>

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

const int N = 2e5 + 100;
pii dp[N];
int parent[N];
int a[N];
int cnt[N];

int main()
{
	USE_IOSTREAM;
	int n, t, k, i, j;
	cin >> n >> t >> k;
	
	cnt[0] = 1;
	for (i = 1; i <= t; i++)
	{
		cin >> a[i];
		cnt[i] = cnt[i - 1] + a[i];
	}
	a[0] = 1;
	
	dp[t] = {a[t], a[t]};
	int minEnd, maxEnd;
	for (i = t - 1; i >= 0; i--)
	{
		minEnd = max(0, a[i] - a[i + 1]);
		maxEnd = a[i] - 1;
		
		dp[i] = {dp[i + 1].first + minEnd, dp[i + 1].second + maxEnd};
	}
	
	if (k < dp[0].first || k > dp[0].second)
	{
		cout << -1 << endl;
		return 0;
	}
	
	int u = 2, p = 0, pNum;
	int restEnd = k, curEnd, startIdx, endIdx;
	for (i = 0; i < t; i++)
	{
		minEnd = max(0, a[i] - a[i + 1]);
		maxEnd = a[i] - 1;
		
		// try 4 case
		if (restEnd - minEnd >= dp[i + 1].first && restEnd - minEnd <= dp[i + 1].second)
		{
			curEnd = minEnd;
		}
		else if (restEnd - maxEnd >= dp[i + 1].first && restEnd - maxEnd <= dp[i + 1].second)
		{
			curEnd = maxEnd;
		}
		else if (restEnd - dp[i + 1].first >= minEnd && restEnd - dp[i + 1].first <= maxEnd)
		{
			curEnd = restEnd - dp[i + 1].first;
		}
		else if (restEnd - dp[i + 1].second >= minEnd && restEnd - dp[i + 1].second <= maxEnd)
		{
			curEnd = restEnd - dp[i + 1].second;
		}
		restEnd -= curEnd;
		startIdx = cnt[i] - a[i] + 1;
		pNum = a[i] - curEnd;
		endIdx = startIdx + pNum - 1;
		for (j = startIdx; j < endIdx; j++)
		{
			parent[u++] = j;
		}
		for (; u <= cnt[i + 1]; u++)
		{
			parent[u] = j;
		}
	}
	
	cout << n << endl;
	for (i = 2; i <= n; i++)
	{
		cout << i << " " << parent[i] << endl;
	}
	
	return 0;
}