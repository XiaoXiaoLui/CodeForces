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

const int N = 2e5 + 50;
const ll MOD = 1e9 + 7;

vector<pii> graph[N];

int com[N];
int d[N];
int cs[N];
int comSize[N];
bool visit[N];

void dfs(int u, pii preEdge, int c)
{
	int i, v;
	visit[u] = true;
	com[u] = c;
	d[u] = d[preEdge.first] + 1;
	comSize[c]++;
	
	for (i = 0; i < graph[u].size(); i++)
	{
		if (graph[u][i].second == preEdge.second)
		{
			continue;
		}
		
		v = graph[u][i].first;
		if (visit[v])
		{
			if (!cs[c])
			{
				cs[c] = d[u] - d[v] + 1;
			}
			continue;
		}
		dfs(v, mp(u, graph[u][i].second), c);
	}
	
}

ll mypow(ll a, ll b)
{
	ll res = 1;
	
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % MOD;
		}
		
		a = (a * a) % MOD;
		b >>= 1;
	}
	
	return res;
}

int main()
{
	int n, i, u, v;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &u);
		graph[i].push_back(mp(u, i));
		graph[u].push_back(mp(i, i));
	}
	
	int c = 1;
	for (i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			dfs(i, mp(0, 0), c);
			++c;
		}
	}
	
	ll ans = 1;
	int s, t;
	for (i = 1; i < c; i++)
	{
		s = comSize[i] - cs[i];
		t = cs[i];
		ans = ans * mypow(2, s) % MOD;
		ans = ans * (mypow(2, t) - 2) % MOD;
	}
	
	printf("%lld\n", ans);
	return 0;
}