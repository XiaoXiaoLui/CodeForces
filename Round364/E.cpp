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

const int N = 2e5 + 5;
vector<int> graph[N];

bool has[N];
int myCount[N];
int h[N];
//bool visit[N];
int n, k, root;
ll ans = 0;

void dfs1(int u, int pre)
{
	//visit[u] = true;
	int i, v;
	if (has[u])
	{
		myCount[u] = 1;
	}
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v != pre)
		{
			dfs1(v, u);
			myCount[u] += myCount[v];
		}
	}
}

bool dfs2(int u, int pre)
{
	int i, v;
	
	bool ok = true;
	if (myCount[u] < k)
	{
		ok = false;
	}
	for (i = 0; ok && i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v == pre)
		{
			continue;
		}
		else if (myCount[v] > k)
		{
			ok = false;
			break;
		}
	}
	
	if (ok)
	{
		root = u;
		return true;
	}
	
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v == pre)
		{
			continue;
		}
		
		if (dfs2(v, u))
		{
			return true;
		}
	}
	
	return false;
}

ll dfs3(int u, int pre)
{
	int v, i;
	h[u] = h[pre] + 1;
	
	ll res = 0;
	if (has[u])
	{
		res = h[u];
	}
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v != pre)
		{
			res += dfs3(v, u);
		}
	}
	
	return res;
}

int main()
{
	int u, v, i;
	scanf("%d%d", &n, &k);
	for (i = 0; i < 2*k; i++)
	{
		scanf("%d", &u);
		has[u] = true;
	}
	
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	h[0] = -1;
	if (root != 0)
	{
		ans = dfs3(root, 0);
	}
	
	printf("%lld\n", ans);
	return 0;
}