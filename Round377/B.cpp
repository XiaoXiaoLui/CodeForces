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

const int N = 600;
int a[N];

int main()
{
	// USE_IOSTREAM;
	int n, k, i, ans, add;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	ans =  0;
	for (i = 2; i <= n; i++)
	{
		add = max(k - a[i - 1] - a[i], 0);
		a[i] += add;
		ans += add;
	}
	
	printf("%d\n", ans);
	for (i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}