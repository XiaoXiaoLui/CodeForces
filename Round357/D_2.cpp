#include <cstdio>
#include <vector>
#include <queue>

using namespace std;


const int N = 1e5 + 5;

int n;
int p[N];
int r[N];
int w[N];
int inDegree[N];
vector<int> son[N];
bool inAns[N];
vector<int> ans;
vector<int> srt;

void dfs(int u, int res)
{
	if (r[u])
	{
		return;
	}
	r[u] = res;
	int i, v;
	for (i = 0; i < son[u].size(); i++)
	{
		v = son[u][i];
		dfs(v, res);
	}
}

void topoSort()
{
	queue<int> Q;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			Q.push(i);
		}
	}
	
	int cur;
	int parent;
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();
		srt.push_back(cur);
		parent = p[cur];
		inDegree[parent]--;
		if (!inDegree[parent])
		{
			Q.push(parent);
		}
	}
	
}

int main()
{
	int m, i, u, v;
	bool ok = true;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		inDegree[u]++;
		p[v] = u;
		son[u].push_back(v);
	}
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
		inAns[w[i]] = true;
	}
	
	topoSort();
	
	for (i = 0; i < srt.size(); i++)
	{
		if (inAns[srt[i]])
		{
			ans.push_back(srt[i]);
		}
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		dfs(ans[i], ans[i]);
	}
	
	for (i = 1; i <= n; i++)
	{
		if (r[i] != w[i])
		{
			ok = false;
			break;
		}
	}
	
	if (ok)
	{
		printf("%d\n", ans.size());
		for (i = 0; i < ans.size(); i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	else
	{
		printf("-1\n");
	}
	
	return 0;
}