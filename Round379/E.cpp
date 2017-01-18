#include<bits/stdc++.h>

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

const int N = 2e5 + 100;

int color[N];
int com[N];
vector<int> g1[N];
vector<int> g2[N];
bool visit[N];
int ans;

void dfs1(int u, int c)
{
	com[u] = c;
	for (auto v : g1[u])
	{
		if (!com[v] && color[v] == color[u])
		{
			dfs1(v, c);
		}
	}
}

int dfs2(int u)
{
	visit[u] = true;
	int mx1, mx2, tmp;
	mx1 = mx2 = 0;
	
	for (auto v : g2[u])
	{
		if (!visit[v])
		{
			tmp = dfs2(v) + 1;
			if (tmp > mx1)
			{
				mx2 = mx1;
				mx1 = tmp;
			}
			else if (tmp > mx2)
			{
				mx2 = tmp;
			}
		}
	}
	
	ans = max(ans, mx1 + mx2);
	return mx1;
}

int main()
{
	// USE_IOSTREAM;
	int n, u, v, i, j, c;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &color[i]);
	}
	
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		g1[u].push_back(v);
		g1[v].push_back(u);
	}
	
	c = 0;
	for (u = 1; u <= n; u++)
	{
		if (!com[u])
		{
			dfs1(u, ++c);
		}
	}
	
	for (u = 1; u <= n; u++)
	{
		for (auto v : g1[u])
		{
			i = com[u];
			j = com[v];
			if (i > j)
			{
				g2[i].push_back(j);
				g2[j].push_back(i);
			}
		}
	}
	
	dfs2(1);
	ans = (ans + 1) / 2;
	printf("%d\n", ans);
	return 0;
}