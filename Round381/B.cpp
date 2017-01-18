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

const int N = 150;

int sum[N];
int a[N];
int l[N];
int r[N];

int main()
{
	// USE_IOSTREAM;
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
	}
	
	for (i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	
	
	int ans = 0, tmp;
	for (i = 1; i <= m; i++)
	{
		tmp = sum[r[i]] - sum[l[i] - 1];
		if (tmp > 0)
		{
			ans += tmp;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}