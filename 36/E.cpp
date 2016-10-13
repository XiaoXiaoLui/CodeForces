#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10005;

struct Edge
{
	Edge(){}
	Edge(int i, int id) : v(i), index(id)
	{
	}
	int v;
	int index;
};


vector<Edge> graph[N];
vector<int> odds[3];
vector<int> path;
int com[N];
bool used[N];
bool hasIndex[N];
int next[N];


void dfs(int u, int c)
{
	com[u] = c;
	int i, v;
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].v;
		if (!com[v])
		{
			dfs(v, c);
		}
	}
}

void eular(int u)
{
	int index, v;
	while (next[u] < graph[u].size())
	{
		if (used[graph[u][next[u]].index])
		{
			next[u]++;
			continue;
		}
		v = graph[u][next[u]].v;
		index = graph[u][next[u]].index;
		next[u]++;
		used[index] = true;
		eular(v);
		
		path.push_back(index);
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int m, i, j, k, u, v, n;
	bool ok = true;
	vector<int> ans[3];
	scanf("%d", &m);
	n = 0;
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		n = max(n, max(u, v));
		hasIndex[u] = hasIndex[v] = true;

		graph[u].push_back(Edge(v, i));
		graph[v].push_back(Edge(u, i));
	}
	
	int c = 0;
	for (i = 1; i <= n; i++)
	{
		if (!hasIndex[i])
		{
			continue;
		}
		if (!com[i])
		{
			++c;
			dfs(i, c);
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		if (!hasIndex[i])
		{
			continue;
		}
		if (graph[i].size() & 1)
		{
			if (com[i] == 1)
			{
				odds[1].push_back(i);
			}
			else if (com[i] == 2)
			{
				odds[2].push_back(i);
			}
		}
	}
	
	if (c > 2)
	{
		ok = false;
	}
	else if (c == 2)
	{
		for (k = 1; k <= 2; k++)
		{
			if (odds[k].size() == 0)
			{
				for (i = 1; i <= n && com[i] != k; i++);
				eular(i);
				ans[k] = path;
				path.clear();
			}
			else if (odds[k].size() == 2)
			{
				eular(odds[k][0]);
				ans[k] = path;
				path.clear();
			}
			else
			{
				ok = false;
				break;
			}
		}
	}
	else
	{
		if (odds[1].size() == 0 || odds[1].size() == 2)
		{
			int start;
			for (start = 1; start <= n && com[start] != 1; start++);
		
			if (odds[1].size() == 2)
			{
				start = odds[1][0];
			}
			eular(start);
			if (path.size() < 2)
			{
				ok = false;
			}
			else
			{
				ans[1] = path;
				ans[1].pop_back();
				ans[2].push_back(path[path.size() - 1]);
			}
		}
		else if (odds[1].size() == 4)
		{
			u = odds[1][0];
			v = odds[1][1];
			graph[u].push_back(Edge(v, 0));
			graph[v].push_back(Edge(u, 0));
			eular(odds[1][2]);
			for (i = 0; path[i] != 0; i++)
			{
				ans[1].push_back(path[i]);
			}
			
			for (i++; i < path.size(); i++)
			{
				ans[2].push_back(path[i]);
			}
		}
		else
		{
			ok = false;
		}
	}
	
	if (!ok)
	{
		printf("-1\n");
	}
	else
	{
		for (k = 1; k <= 2; k++)
		{
			printf("%d\n", ans[k].size());
			for (i = 0; i < ans[k].size(); i++)
			{
				printf("%d ", ans[k][i]);
			}
			printf("\n");
		}
	}
}