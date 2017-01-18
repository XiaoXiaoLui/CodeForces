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

const int N = 2e5 + 100;

int a[N];
int b[N];
int c[N];
int d[N];

int tr[N];
int totN;
int lowbit(int id)
{
	return id & (-id);
}

void update(int i, int value)
{
	while (i <= totN)
	{
		tr[i] = min(tr[i], value);
		i += lowbit(i);
	}
}

int query(int i)
{
	int res = tr[0];
	while (i)
	{
		res = min(res, tr[i]);
		i -= lowbit(i);
	}
	
	return res;
}

map<int, int> mm;
map<int, int> ha;

int main()
{
	// USE_IOSTREAM;
	int n, m, k, x, s, i;
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d", &x, &s);
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
	}
	
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
	}
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &d[i]);
	}
	
	fill(tr, tr + N, x);
	for (i = 1; i <= m; i++)
	{
		if (b[i] <= s && (mm.count(b[i]) == 0 || a[i] < mm[b[i]]))
		{
			mm[b[i]] = a[i];
		}
	}
	
	totN = mm.size();
	i = 1;
	for (auto iter = mm.begin(); iter != mm.end(); iter++, i++)
	{
		ha[iter->first] = i;
		update(i, iter->second);
	}
	ha[-1] = 0;
	
	int left = s;
	auto iter = ha.upper_bound(left);
	iter--;
	ll ans = (ll)n * query(iter->second);
	for (i = 1; i <= k; i++)
	{
		if (d[i] <= s)
		{
			left = s - d[i];
			iter = ha.upper_bound(left);
			iter--;
			ll tmp = (ll)(n - c[i]) * query(iter->second); 
			ans = min(ans, tmp);
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}