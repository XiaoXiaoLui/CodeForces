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

const int N = 2e5 + 100;
const int INF = 1e9 + 10;
int d[N];
int c[N];
int sum[N];
int n;

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int i, left, right, mid;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &c[i], &d[i]);
		sum[i + 1] = sum[i] + c[i];
	}
	
	int minDiv1 = INF, maxDiv2 = -INF;
	for (i = 1; i <= n; i++)
	{
		if (d[i] == 1)
		{
			minDiv1 = min(minDiv1, sum[i]);
		}
		else
		{
			maxDiv2 = max(maxDiv2, sum[i]);
		}
	}
	
	if (minDiv1 <= maxDiv2)
	{
		printf("Impossible\n");
	}
	else if (maxDiv2 == -INF)
	{
		printf("Infinity\n");
	}
	else 
	{
		int offset = 1899 - maxDiv2;
		printf("%d\n", sum[n + 1] + offset);
	}
	
	return 0;
}