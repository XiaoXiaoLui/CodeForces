#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct Edge
{
	Edge(){}
	Edge(int i, int j)
	{
		v = i;
		w = j;
	}
	int v;
	ll w;
};

vector<Edge> graph[N];
int a[N];
int n;
int ans;



int countNum(int u, int pre)
{
	int i, v, res;
	res = 1;
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].v;
		if (v == pre)
		{
			continue;
		}
		res += countNum(v, u);
	}
	return res;
	
}

void dfs(int u, ll curMax, int pre)
{
	int i, v;
	ll w;
	if (curMax > a[u])
	{
		ans += countNum(u, pre);
	}
	else
	{
		for (i = 0; i < graph[u].size(); i++)
		{
			v = graph[u][i].v;
			w = graph[u][i].w;
			if (v == pre)
			{
				continue;
			}
			
			if (curMax > 0)
			{
				dfs(v, curMax + w, u);
			}
			else
			{
				dfs(v, w, u);
			}
		}
	}
}

int main()
{
	int i, j, u, v, w;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (u = 2; u <= n; u++)
	{
		scanf("%d%d", &v, &w);
		graph[u].push_back(Edge(v, w));
		graph[v].push_back(Edge(u, w));
	}
	
	dfs(1, 0, 0);
	
	
	printf("%d\n", ans);
	return 0;
}