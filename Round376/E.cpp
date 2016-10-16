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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 2e5 + 100;
int a[N];
int sum[N];

int main()
{
	// USE_IOSTREAM;
	int n, i, cur, best;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	
	best = sum[n];
	for (i = n - 1; i >= 1; i--)
	{
		cur = best;
		best = max(best, sum[i] - cur);
	}
	
	printf("%d\n", cur);
	return 0;
}