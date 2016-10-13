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

const int N = 2e5 + 100;

int n, m, s, t, ds, dt;
vector<int> graph[N];
int com[N];
int mask[N];
int end[N][2];
vector<pii> ans;
bool connect[N];

void dfs(int u, int c)
{
	int v, i;
	com[u] = c;
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v != s && v != t && !com[v])
		{
			ans.push_back(mp(u, v));
			dfs(v, c);
		}
	}
}


int main()
{
	int i, u, v;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	scanf("%d%d%d%d", &s, &t, &ds, &dt);
	
	int c = 0;
	int idx;
	for (u = 1; u <= n; u++)
	{
		if (u != s && u != t && !com[u])
		{
			++c;
			dfs(u, c);
		}
	}
	
	for (i = 0; i < graph[s].size(); i++)
	{
		u = graph[s][i];
		if (u != t)
		{
			mask[com[u]] |= 1;
			if (!end[com[u]][0])
			{
				end[com[u]][0] = u;
			}
		}
	}
	
	idx = 0;
	for (i = 0; i < graph[t].size(); i++)
	{
		u = graph[t][i];
		if (u != s)
		{
			mask[com[u]] |= 2;
			if (!end[com[u]][1])
			{
				end[com[u]][1] = u;
			}
			if (mask[com[u]] == 3 && !idx)
			{
				idx = com[u];
			}
		}
	}
	
	int cs, ct, cst;
	cs = ct = cst = 0;
	for (i = 1; i <= c; i++)
	{
		if (mask[i] == 1)
		{
			cs++;
		}
		else if (mask[i] == 2)
		{
			ct++;
		}
		else
		{
			cst++;
		}
	}
	
	int add = (cst == 0) ? 2 : 1;
	if (cs >= ds || ct >= dt || c + add > ds + dt)
	{
		printf("No\n");
		return 0;
	}
	
	if (cst == 0)
	{
		ans.push_back(mp(s, t));
		dt--;
		ds--;
	}
	else
	{
		ans.push_back(mp(s, end[idx][0]));
		ans.push_back(mp(t, end[idx][1]));
		connect[idx] = true;
		ds--;
		dt--;
	}
	
	
	for (i = 0; i < graph[s].size(); i++)
	{
		u = graph[s][i];
		if (u == t)
		{
			continue;
		}
		idx = com[u];
		if (!connect[idx] && mask[idx] == 1)
		{
			ans.push_back(mp(s, u));
			connect[idx] = true;
			ds--;
		}
	}
	
	for (i = 0; i < graph[s].size() && ds; i++)
	{
		u = graph[s][i];
		if (u == t)
		{
			continue;
		}
		
		idx = com[u];
		if (!connect[idx])
		{
			ans.push_back(mp(s, u));
			connect[idx] = true;
			ds--;
		}
	}
	
	for (i = 0; i < graph[t].size(); i++)
	{
		u = graph[t][i];
		if (u == s)
		{
			continue;
		}
		
		idx = com[u];
		if (!connect[idx] && mask[idx] == 2)
		{
			ans.push_back(mp(t, u));
			connect[idx] = true;
			dt--;
		}
	}
	
	for (i = 0; i < graph[t].size() && dt; i++)
	{
		u = graph[t][i];
		if (u == s)
		{
			continue;
		}
		idx = com[u];
		if (!connect[idx])
		{
			ans.push_back(mp(t, u));
			connect[idx] = true;
			dt--;
		}
	}
	
	
	
	printf("Yes\n");
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	
	return 0;
}