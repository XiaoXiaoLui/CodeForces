#include <bits/stdc++.h>

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

const int N = 4e5 + 100;

vector<pii> graph[N];
pii e[N];
int comSize[N];
int com[N];
bool isBridge[N];
bool visit[N];
int ord;
int dfn[N];
int low[N];

void tarjan(int u, int pre)
{
	dfn[u] = low[u] = ++ord;
	visit[u] = true;
	
	int v;
	for (auto e : graph[u])
	{
		v = e.first;
		if (!visit[v])
		{
			tarjan(v, u);
			
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
			{
				isBridge[e.second] = true;
			}
		}
		else if (v != pre)
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void dfs1(int u, int c)
{
	com[u] = c;
	comSize[c]++;
	
	int v, idx;
	for (auto p : graph[u])
	{
		v = p.first;
		idx = p.second;
		if (isBridge[idx] || com[v])
		{
			continue;
		}
		dfs1(v, c);
	}
}

void dfs2(int u)
{
	int v, idx;
	for (auto p : graph[u])
	{
		v = p.first;
		idx = p.second;
		if (!e[idx].first)
		{
			if (isBridge[idx])
			{
				e[idx] = mp(v, u);
			}
			else
			{
				e[idx] = mp(u, v);
			}
			
			if (!visit[v])
			{
				dfs2(v);
			}
		}
	}
}


int main()
{
	// USE_IOSTREAM;
	int n, m, u, v, i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(mp(v, i));
		graph[v].push_back(mp(u, i));
	}
	
	tarjan(1, 0);
	//memset(visit, 0, sizeof(visit));
	int c = 0;
	for (u = 1; u <= n; u++)
	{
		if (!com[u])
		{
			++c;
			dfs1(u, c);
		}
	}
	
	int maxCom, maxComSize = 0;
	for (i = 1; i <= c; i++)
	{
		if (comSize[i] > maxComSize)
		{
			maxComSize = comSize[i];
			maxCom = i;
		}
	}
	
	memset(visit, 0, sizeof(visit));
	for (u = 1; u <= n; u++)
	{
		if (com[u] == maxCom)
		{
			dfs2(u);
		}
	}
	
	printf("%d\n", maxComSize);
	for (i = 1; i <= m; i++)
	{
		printf("%d %d\n", e[i].first, e[i].second);
	}
	
	return 0;
}