#include <cstdio>
#include <vector>

using namespace std;

const int N = 5e4 + 5;

vector<int> graph[N];
int parent[N];

int n, r1, r2;

void dfs(int u, int pre)
{
	parent[u] = pre;
	
	int i, v;
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v == pre)
		{
			continue;
		}
		dfs(v, u);
	}
}

int main()
{
	int i, p;
	scanf("%d%d%d", &n, &r1, &r2);
	for (i = 1; i <= n; i++)
	{
		if (i == r1)
		{
			continue;
		}
		scanf("%d", &p);
		graph[i].push_back(p);
		graph[p].push_back(i);
	}
	
	dfs(r2, 0);
	
	for (i = 1; i <= n; i++)
	{
		if (i == r2)
		{
			continue;
		}
		printf("%d ", parent[i]);
	}
	printf("\n");
	return 0;
}