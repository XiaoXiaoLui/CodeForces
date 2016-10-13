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
int parent[N];
vector<int> son[N];
vector<int> roots;
bool visit[N];

bool dfs(int u, int pre, int &r)
{
	int i, v;
	visit[u] = true;
	bool res = true;
	for (i = 0; i < son[u].size(); i++)
	{
		v = son[u][i];
		if (v == pre)
		{
			continue;
		}
		if (visit[v])
		{
			res = false;
			r = u;
			continue;
		}
		if (!dfs(v, u, r))
		{
			res = false;
		}
	}
	return res;
}


int main()
{
	int n, i, u, v, root, r;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &parent[i]);
		if (parent[i] == i)
		{
			roots.push_back(i);
		}
		else
		{
			son[parent[i]].push_back(i);
			son[i].push_back(parent[i]);
		}
	}
	
	int ans = 0;
	root = 0;
	if (roots.size() == 0)
	{
		
		for (u = 1; u <= n; u++)
		{
			if (visit[u])
			{
				continue;
			}
			if (!dfs(u, 0, r))
			{
				if (!root)
				{
					root = r;
				}
				ans++;
				parent[r] = root;
			}
		}
	}
	else if (roots.size() >= 1)
	{
		ans = roots.size() - 1;
		root = roots[0];
		for (i = 1; i < roots.size(); i++)
		{
			v = roots[i];
			parent[v] = root;
			son[root].push_back(v);
			son[v].push_back(root);
		}
		
		dfs(root, 0, r);
		
		for (u = 1; u <= n; u++)
		{
			if (!visit[u])
			{
				if (!dfs(u, 0, r))
				{
					ans++;
					parent[r] = root;
				}
			}
		}
	}
	
	
	
	
	printf("%d\n", ans);
	for (i = 1; i <= n; i++)
	{
		printf("%d ", parent[i]);
	}
	printf("\n");
	return 0;
}

/*
2
2 3 7 8 1 6 6 7
*/