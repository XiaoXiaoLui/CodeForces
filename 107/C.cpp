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

const int N = 20;
const int M = 1 << 16;

int ans[N];
ll dp[M];
int pre[N];
int used;
int n;

ll calNum()
{
	memset(dp, 0, sizeof(dp));
	
	int j, k;
	
	// dp[i][j] number of valid permutation of i digit with position mask j, note that mask j is complete(no unplaced pre position p for any bit in j).
	dp[0] = 1;
	for (j = 0; j < 1 << n; j++)
	{
		if (dp[j] == 0)
		{
			continue;
		}
		
		int c = __builtin_popcount(j);
		for (k = 0; k < n; k++)
		{
			if (j >> k & 1)
			{
				continue;
			}
			
			if (used >> c & 1 && ans[k] != c)
			{
				continue;
			}
			
			if ((j & pre[k]) == pre[k])
			{
				dp[j | 1 << k] += dp[j];
			}
		}
	}
	
	return dp[(1 << n) - 1];
}


int main()
{
	USE_IOSTREAM;
	int m, i, j, a, b;
	ll y;
	cin >> n >> y >> m;
	for (i = 1; i <= m; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		pre[b] |= 1 << a;
	}
	
	fill_n(ans, N, -1);
	
	y -= 2000;
	if (calNum() < y)
	{
		cout << "The times have changed" << endl;
		return 0;
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (used >> j & 1)
			{
				continue;
			}
			used |= 1 << j;
			ans[i] = j;
			
			ll tot = calNum();
			if (y <= tot)
			{
				break;
			}
			
			y -= tot;
			used ^= 1 << j;
		}
	}
	
	for (i = 0; i < n; i++)
	{
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
	
	return 0;
}