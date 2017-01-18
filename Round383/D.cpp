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

const int N = 5e5 + 100;

int dp[(1 << 22) + 100];
vector<pii> vec[N];
int tot[N];
int mIdx[N];
int maxChildIdx[N];

vector<pii> son[N];
int parent[N];
int h[N];

int ans[N];

inline void update(int &cur, int value)
{
	cur = max(cur, value);
}

void dfsSize(int u)
{
	tot[u] = 1;
	int mxIdx = -1;
	int curMax = 0;
	for (int i = 0; i < son[u].size(); i++)
	{
		int v = son[u][i].first;
		dfsSize(v);
		tot[u] += tot[v];
		if (tot[v] > curMax)
		{
			curMax = tot[v];
			mxIdx = i;
		}
	}
	
	maxChildIdx[u] = mxIdx;
}

inline void merge(int i, int j, int u)
{
	for (auto &tmp : vec[j])
	{
		vec[i].push_back(tmp);
		int mask = tmp.first;
		int len = tmp.second;
		
		if (dp[mask] >= 0)
		{
			update(ans[u], len + dp[mask] - 2*h[u]);
		}
		for (int k = 0; k < 22; k++)
		{
			int coMask = mask ^ (1 << k);
			if (dp[coMask] >= 0)
			{
				update(ans[u], len + dp[coMask] - 2*h[u]);
			}
		}
	}
	
	for (auto &tmp : vec[j])
	{
		update(dp[tmp.first], tmp.second);
	}
	
	vector<pii>().swap(vec[j]); // must use this to free memory
}

void dfs(int u, int preMask, bool keep)
{
	h[u] = h[parent[u]] + 1;

	vec[u].push_back({preMask, h[u]});
	
	for (int i = 0; i < son[u].size(); i++)
	{
		if (i == maxChildIdx[u])
		{
			continue;
		}
		
		int v = son[u][i].first;
		int c = son[u][i].second;
		
		dfs(v, preMask ^ (1 << c), false);
		update(ans[u], ans[v]);
	}
	
	int &curVecIdx = mIdx[u] = u;
	if (maxChildIdx[u] != -1)
	{
		int v = son[u][maxChildIdx[u]].first;
		int c = son[u][maxChildIdx[u]].second;
		dfs(v, preMask ^ (1 << c), true);
		update(ans[u], ans[v]);
		curVecIdx = mIdx[v];
		merge(curVecIdx, u, u);
	}
	else
	{
		update(dp[preMask], h[u]);
	}
	
	for (int i = 0; i < son[u].size(); i++)
	{
		if (i == maxChildIdx[u])
		{
			continue;
		}
		int v = son[u][i].first;
		
		merge(curVecIdx, mIdx[v], u);
	}
	
	if (!keep)
	{
		for (auto &tmp : vec[curVecIdx])
		{
			dp[tmp.first] = -1;
		}
	}
}

int main()
{
	// USE_IOSTREAM;
	int n, i, u, v, w;
	char ch;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		scanf("%d %c", &v, &ch);
		parent[i] = v;
		son[v].push_back({i, (int)ch - 'a'});
	}
	
	fill_n(dp, 1 << 22, -1);
	h[0] = -1;
	dfsSize(1);
	dfs(1, 0, true);
	
	for (i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}