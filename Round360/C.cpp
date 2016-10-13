#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1e5 + 10;

vector<int> graph[N];
int c[N];


bool ok = true;
vector<int> ans1;
vector<int> ans2;


void dfs(int u, int color)
{
	c[u] = color;
	if (color == 1)
	{
		ans1.push_back(u);
	}
	else
	{
		ans2.push_back(u);
	}
	
	int i, v, nextColor;
	nextColor = (color == 1 ? 2 : 1);
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (c[v])
		{
			if (c[v] != nextColor)
			{
				ok = false;
				return;
			}
			continue;
		}
		
		dfs(v, nextColor);
	}
}

int main()
{
	int n, m, i, u, v;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (u = 1; u <= n; u++)
	{
		if (!c[u])
		{
			dfs(u, 1);
		}
	}
	
	if (!ok)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", ans1.size());
		for (i = 0; i < ans1.size(); i++)
		{
			printf("%d ", ans1[i]);
		}
		printf("\n%d\n", ans2.size());
		for (i = 0; i < ans2.size(); i++)
		{
			printf("%d ", ans2[i]);
		}
		printf("\n");
	}
	
	printf("\n");
	return 0;
}