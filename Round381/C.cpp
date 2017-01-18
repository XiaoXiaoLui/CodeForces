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


const int N = 1e5 + 100;

int a[N];
int l[N];
int r[N];

int main()
{
	// USE_IOSTREAM;
	int n, m, i, ans;
	scanf("%d%d", &n, &m);
	
	ans = N;
	set<int> S;
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		ans = min(ans, r[i] - l[i] + 1);
	}
	
	for (i = 1; i <= ans; i++)
	{
		a[i] = i - 1; 
	}
	for (; i <= n; i++)
	{
		a[i] = a[i - ans];
	}

	printf("%d\n", ans);
	for (i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}