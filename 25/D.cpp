#include <cstdio>
#include <vector>

using namespace std;

const int N = 1003;

struct Road
{
	Road(){}
	Road(int i, int j)
	{
		u = i;
		v = j;
	}
	int u;
	int v;
};

vector<int> graph[N];
vector<Road> rm;
vector<int> root;
bool visit[N];

void dfs(int u, int pre)
{
	visit[u] = true;
	int v;
	for (int i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v == pre)
		{
			continue;
		}
		
		if (visit[v])
		{
			if (u < v)
			{
				rm.push_back(Road(u, v));
			}
		}
		else
		{
			dfs(v, u);
		}
	}
}


int main()
{
	int n, i, u, v;
	
	scanf("%d", &n);
	
	for (i = 1; i <= n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (u = 1; u <= n; u++)
	{
		if (!visit[u])
		{
			root.push_back(u);
			dfs(u, 0);
		}
	}
	
	printf("%d\n", rm.size());
	
	for (i = 0; i < rm.size(); i++)
	{
		printf("%d %d %d %d\n", rm[i].u, rm[i].v, root[i], root[i + 1]);
	}
	
	return 0;
}