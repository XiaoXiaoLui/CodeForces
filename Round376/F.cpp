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

int sum[N];
int a[N];
bool visit[N];

int main()
{
	// USE_IOSTREAM;
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sum[0] = 0;
	for (i = 1; i <= n; i++)
	{
		sum[a[i]]++;
	}
	for (i = 1; i < N; i++)
	{
		sum[i] += sum[i - 1];
	}
	
	
	ll ans = 0, cur;
	int r;
	for (i = 1; i <= n; i++)
	{
		if (visit[a[i]])
		{
			continue;
		}
		visit[a[i]] = true;
		
		cur = 0;
		for (j = a[i]; j < N; j += a[i])
		{
			r = min(j + a[i] - 1, N - 1);
			cur += (ll)j * (sum[r] - sum[j - 1]);
		}
		ans = max(ans, cur);
	}
	
	printf("%lld\n", ans);
	return 0;
}