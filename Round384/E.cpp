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

const int N = 1005;
const int M = 300;
const int INF = 1e9;

void update(int &cur, int value)
{
	cur = max(cur, value);
}


int dp[N][M];
vector<int> posVec[8];
int curIdx[8];
int a[N];
int n;

int cal(int minLen)
{
	int i, j, k;
	for (i = 0; i < 8; i++)
	{
		curIdx[i] = 0;
	}
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j < 1 << 8; j++)
		{
			dp[i][j] = -INF;
		}
	}
	
	dp[0][0] = 0;
	for (i = 0; i < n; i++)
	{
		if (i > 0)
		{
			curIdx[a[i]]++;
		}
		for (j = 0; j < 1 << 8; j++)
		{
			if (dp[i][j] == -INF)
			{
				continue;
			}
			
			for (k = 0; k < 8; k++)
			{
				if (j >> k & 1)
				{
					continue;
				}
				int idx = curIdx[k] + minLen - 1;
				if (idx >= posVec[k].size())
				{
					continue;
				}
				
				update(dp[posVec[k][idx]][j | 1 << k], dp[i][j]);
				
				idx++;
				if (idx < posVec[k].size())
				{
					update(dp[posVec[k][idx]][j | 1 << k], dp[i][j] + 1);
				}
			}
		}
	}
	
	int res = -INF;
	for (i = 8; i <= n; i++)
	{
		update(res, dp[i][255]);
	}
	
	if (res < 0)
	{
		return res;
	}
	else
	{
		return res * (minLen + 1) + (8 - res) * minLen;
	}
}

int main()
{
	USE_IOSTREAM;
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i]--;
		posVec[a[i]].push_back(i);
	}
	
	int ans = 0;
	if (cal(1) < 0)
	{
		for (i = 0; i < 8; i++)
		{
			if (!posVec[i].empty())
			{
				ans++;
			}
		}
	}
	else
	{
		int left, right, mid;
		left = 1;
		right = 200;
		while (right - left > 1)
		{
			mid = (right + left) / 2;
			int ret = cal(mid);
			if (ret < 0)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}
		ans = cal(left);
	}
	
	cout << ans << endl;
	return 0;
}