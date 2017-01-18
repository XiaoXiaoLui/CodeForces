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
int cnt[N];
int ans[N];
ll h[N];
int parent[N];
vector<pii> son[N];
vector<pair<ll, int> > path;

int dfs(int u)
{
	int v, w, sum;
	auto iter = lower_bound(path.begin(), path.end(), mp(h[u] - a[u], 0));
	if (iter != path.end())
	{
		cnt[parent[iter->second]]--;
		cnt[parent[u]]++;
	}
	
	path.push_back(mp(h[u], u));
	sum = 0;
	for (auto pp : son[u])
	{
		v = pp.first;
		w = pp.second;
		h[v] = h[u] + w;
		sum += dfs(v);
	}
	path.pop_back();
	
	sum += cnt[u];
	ans[u] = sum;
	
	return sum;
}


int main()
{
	// USE_IOSTREAM;
	int n, u, v, w, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 2; i <= n; i++)
	{
		scanf("%d%d", &u, &w);
		son[u].push_back(mp(i, w));
		parent[i] = u;
	}
	
	h[1] = 0;
	dfs(1);
	
	for (i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}