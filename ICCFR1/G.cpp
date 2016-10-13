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


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1e5 + 100;
const ll MOD = 1e9 + 7;

vector<pii> graph[N];
ll edge[2*N];
bool visit[N];
ll mask[N];
vector<ll> mat;
int c0[64];
int c1[64];
int verCount;
ll hasZero;
ll ans;

void dfs(int u, int preEdge)
{
	int i, v, idx;
	visit[u] = true;
	verCount++;
	for (i = 0; i <= 60; i++)
	{
		if ((mask[u] >> i) & 1)
		{
			c1[i]++;
		}
		else
		{
			c0[i]++;
		}
	}
	
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		idx = graph[u][i].second;
		if (!visit[v])
		{
			mask[v] = mask[u] ^ edge[idx];
			dfs(v, idx);
		}
		else if (idx != preEdge && u < v)
		{
			mat.push_back(mask[u] ^ mask[v] ^ edge[idx]);
		}
	}
}

void solve()
{
	int i, j, k, r, n;
	n = mat.size();
	for (j = 0, i = 0; j <= 60; j++)
	{
		for (k = i; k < n && ((mat[k] >> j) & 1) == 0; k++);
		if (k < n)
		{
			swap(mat[i], mat[k]);
			
			for (k = i + 1; k < n; k++)
			{
				if ((mat[k] >> j) & 1)
				{
					mat[k] ^= mat[i];
				}
			}
			i++;
		}
	}
	r = i;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j <= 60; j++)
		{
			if ((mat[i] >> j) & 1)
			{
				hasZero |= 1LL << j;
			}
		}
	}
	
	ll tmp = 0;
	for (i = 0; i <= 60; i++)
	{
		if ((hasZero >> i) & 1)
		{
			tmp = (1LL << i) % MOD;
			tmp = tmp * (((ll)verCount * (verCount - 1) / 2) % MOD) % MOD;
			tmp = tmp * ((1LL << (r - 1)) % MOD) % MOD;
		}
		else
		{
			tmp = (1LL << i) % MOD;
			tmp = tmp * c0[i] % MOD * c1[i] % MOD * ((1LL << r) % MOD) % MOD;
		}
		ans = (ans + tmp) % MOD;
	}
}

int main()
{
	int n, m, i, u, v;
	ll w;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%lld", &u, &v, &w);
		edge[i] = w;
		graph[u].push_back(mp(v, i));
		graph[v].push_back(mp(u, i));
	}
	
	for (u = 1; u <= n; u++)
	{
		if (visit[u])
		{
			continue;
		}
		hasZero = 0;
		verCount = 0;
		memset(c0, 0, sizeof(c0));
		memset(c1, 0, sizeof(c1));
		mat.clear();
		dfs(u, 0);
		
		solve();
	}
	
	printf("%lld\n", ans);
	return 0;
}