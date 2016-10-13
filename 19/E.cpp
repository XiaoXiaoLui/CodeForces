#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10005;

struct Edge
{
	int v;
	int index;
};

vector<Edge> a[N];
vector<int> ans;
int f[N];
int g[N];
int e[N];
int visit[N];
int c[N];
int n, m, cnt, odd;

void dfs(int u, int p)
{
	visit[u] = 1;
	c[u] = 1 - c[p];
	int v;
	for (int i = 0; i < a[u].size(); i++)
	{
		v = a[u][i].v;
		if (v == p)
		{
			continue;
		}
		if (visit[v] == 0)
		{
			e[v] = a[u][i].index;
			dfs(v, u);
			f[u] += f[v];
			g[u] += g[v];
		}
		else if (visit[v] == 1)
		{
			if (c[u] == c[v])
			{
				cnt++;
				odd = a[u][i].index;
				f[u]++;
			}
			else
			{
				g[u]++;
			}
		}
		else
		{
			if (c[u] == c[v])
			{
				f[u]--;
			}
			else
			{
				g[u]--;
			}
		}
	}
	
	visit[u] = 2;
}

int main()
{
	int i, j, u, v;
	Edge edge;
	cin >> n >> m;
	
	for (i = 1; i <= m; i++)
	{
		cin >> u >> v;
		edge.index = i;
		edge.v = v;
		a[u].push_back(edge);
		edge.v = u;
		a[v].push_back(edge);
	}
	
	for (i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			dfs(i, 0);
		}
	}
	
	if (cnt == 0)
	{
		for (i = 1; i <= m; i++)
		{
			ans.push_back(i);
		}
	}
	else
	{
		if (cnt == 1)
		{
			ans.push_back(odd);
		}
		
		for (i = 1; i <= n; i++)
		{
			if (f[i] == cnt && g[i] == 0)
			{
				ans.push_back(e[i]);
			}
		}
		
		sort(ans.begin(), ans.end());
	}
	
	cout << ans.size() << endl;
	for (i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}