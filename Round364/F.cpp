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

struct AdjEdge
{
	AdjEdge(){}
	AdjEdge(int a, int b, int c) : v(a), w(b), index(c)
	{
	}
	
	bool operator < (const AdjEdge &other) const
	{
		return index < other.index;
	}
	
	int index;
	int v;
	int w;
};

struct Edge
{
	Edge(){}
	Edge(int a, int b, int c) : u(a), v(b), w(c)
	{
	}
	int u;
	int v;
	int w;
};

const int N = 1005;
const int M = 30005;

Edge e[M];
vector<AdjEdge> graph[N];
bool del[M];
bool isBridge[M];
int dfn[N];
int low[N];
int m, n, s, t;
int ti;

bool visit[N];
vector<int> path;
AdjEdge pre[N];

void dfs(int u, const AdjEdge &preEdge)
{
	visit[u] = true;
	pre[u] = preEdge;
	AdjEdge edge;
	int i, v;
	for (i = 0; i < graph[u].size(); i++)
	{
		edge = graph[u][i];
		v = edge.v;
		if (del[edge.index] || edge.index == preEdge.index || visit[v])
		{
			continue;
		}
		
		
		dfs(v, AdjEdge(u, edge.w, edge.index));
	}
}

bool findPath()
{
	fill(visit, visit + N, false);
	path.clear();
	dfs(s, AdjEdge(0, 0, 0));
	if (!visit[t])
	{
		return false;
	}
	else
	{
		int u;
		for (u = t; u != s; u = pre[u].v)
		{
			path.push_back(pre[u].index);
		}
		return true;
	}
}

void brDfs(int u, int preEdge)
{
	++ti;
	dfn[u] = low[u] = ti;
	
	AdjEdge edge;
	int i, v;
	for (i = 0; i < graph[u].size(); i++)
	{
		edge = graph[u][i];
		v = edge.v;
		if (del[edge.index] || edge.index == preEdge)
		{
			continue;
		}
		
		if (!dfn[v])
		{
			brDfs(v, edge.index);
			low[u] = min(low[u], low[v]);
		}
		else
		{
			low[u] = min(low[u], low[v]);
		}
	}
}

void findBridge()
{
	fill(isBridge, isBridge + M, false);
	fill(dfn, dfn + N, 0);
	fill(low, low + N, 0);
	ti = 0;
	int u, v, i;
	for (u = 1; u  <= n; u++)
	{
		if (!dfn[u])
		{
			brDfs(u, 0);
		}
	}
	
	for (i = 1; i <= m; i++)
	{
		u = e[i].u;
		v = e[i].v;
		if (dfn[u] > dfn[v])
		{
			swap(u, v);
		}
		
		if (low[v] > dfn[u])
		{
			isBridge[i] = true;
		}
	}
}

int main()
{
	int u, v, w, i, j, idx;
	int minCost = 2e9 + 5;
	vector<int> ans;
	vector<int> orgPath;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		if (u != v)
		{
			graph[u].push_back(AdjEdge(v, w, i));
			graph[v].push_back(AdjEdge(u, w, i));
			e[i] = Edge(u, v, w);
		}
	}
	
	if (!findPath())
	{
		printf("0\n");
		printf("0\n");
		return 0;
	}
	
	findBridge();
	for (i = 0; i < path.size(); i++)
	{
		idx = path[i];
		if (isBridge[idx] && e[idx].w < minCost)
		{
			minCost = e[idx].w;
			ans.clear();
			ans.push_back(idx);
		}
	}
	
	orgPath = path;
	for (i = 0; i < orgPath.size(); i++)
	{
		idx = orgPath[i];
		del[idx] = true;
		findBridge();
		if (findPath())
		{
			for (j = 0; j < path.size(); j++)
			{
				if (isBridge[path[j]] && e[path[j]].w + e[idx].w < minCost)
				{
					minCost = e[path[j]].w + e[idx].w;
					ans.clear();
					ans.push_back(path[j]);
					ans.push_back(idx);
				}
			}
		}
		
		del[idx] = false;
	}
	
	if (ans.size() == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", minCost);
		printf("%d\n", ans.size());
		for (i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i]);
		}
		
		printf("\n");
	}

	return 0;
}