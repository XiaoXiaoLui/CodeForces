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

const int INF = 1e9;
const int N = 50;
const int M = 1 << 6;

int dp[N][M][M];

void update(int &cur, int value)
{
	cur = min(cur, value);
}

bool valid(int preMask, int curMask, int nextMask, int n)
{
	bool curOk = true;
	for (int i = 0; i < n && curOk; i++)
	{
		curOk = false;
		if (curMask >> i & 1)
		{
			curOk = true;
			continue;
		}
		if (i && curMask >> (i - 1) & 1)
		{
			curOk = true;
			continue;
		}
		if (i + 1 < n && curMask >> (i + 1) & 1)
		{
			curOk = true;
			continue;
		}
		if (preMask >> i & 1)
		{
			curOk = true;
			continue;
		}
		if (nextMask >> i & 1)
		{
			curOk = true;
			continue;
		}
	}

	return curOk;
}

int main()
{
	USE_IOSTREAM;
	int n, m, i, preMask, curMask, nextMask;
	cin >> n >> m;
	if (n > m)
	{
		swap(n, m);
	}
	
	fill_n((int*)dp, N*M*M, INF);
	for (nextMask = 0; nextMask < 1 << n; nextMask++)
	{
		dp[0][0][nextMask] = 0;
	}
	
	
	for (i = 1; i <= m; i++)
	{
		for (preMask = 0; preMask < 1 << n; preMask++)
		{
			for (curMask = 0; curMask < 1 << n; curMask++)
			{
				for (nextMask = 0; nextMask < 1 << n; nextMask++)
				{
					if (valid(preMask, curMask, nextMask, n))
					{
						update(dp[i][curMask][nextMask], dp[i - 1][preMask][curMask] + __builtin_popcount(curMask));
					}
				}
			}
		}
	}
	
	int ans = 1e9;
	for (curMask = 0; curMask < 1 << n; curMask++)
	{
		update(ans, dp[m][curMask][0]);
	}
	
	ans = n * m - ans;
	
	cout << ans << endl;
	
	return 0;
}