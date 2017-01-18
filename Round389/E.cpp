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

const int N = 1e7 + 10;
int a[N];
int dp[N];
int n, m, maxNumber;

bool ok(int minNum)
{
	int half, i;
	for (i = minNum; i <= maxNumber; i++)
	{
		half = i / 2;
		if (half >= minNum)
		{
			dp[i] = dp[half] + dp[i - half];
		}
		else
		{
			dp[i] = 1;
		}
	}
	
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= minNum)
		{
			sum += dp[a[i]];
		}
	}
	
	return sum >= m;
}

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int i, left, right, mid;
	scanf("%d%d", &n, &m);
	ll sum = 0;
	maxNumber = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		maxNumber = max(maxNumber, a[i]);
		sum += a[i];
	}
	
	if (sum < m)
	{
		printf("-1\n");
		return 0;
	}
	
	left = 1;
	right = 1e7 + 1;
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		if (ok(mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	
	printf("%d\n", left);
	return 0;
}