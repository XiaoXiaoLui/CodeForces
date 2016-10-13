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

const int N = 220;

vector<pii> graph[N];
int c[N];
bool erased[N*N];
bool check[N*N/2];
int diff[N];
int offset[N];

vector<pii> ansEdge[N];
int ansCount[N];

void go(int u, int dir)
{
	int v, i, idx;
	for (; offset[u] < graph[u].size() && check[graph[u][offset[u]].second / 2]; offset[u]++);
	if (offset[u] >= graph[u].size())
	{
		return;
	}
	
	idx = graph[u][offset[u]].second;
	v = graph[u][offset[u]].first;
	
	diff[u] += dir;
	diff[v] -= dir;
	check[idx / 2] = true;
	offset[u]++;
	if (dir == 1)
	{
		erased[idx ^ 1] = true;
	}
	else
	{
		erased[idx] = true;
	}
	
	if (!c[v])
	{
		go(v, dir);
	}
}

int main()
{
	int n, m, t, i, j, k, u, v, idx;
	scanf("%d", &t);
	for (k = 1; k <= t; k++)
	{
		scanf("%d%d", &n, &m);
		memset(c, 0, sizeof(c));
		memset(erased, 0, sizeof(erased));
		memset(check, 0, sizeof(check));
		memset(diff, 0, sizeof(diff));
		memset(offset, 0, sizeof(offset));
		
		for (i = 0; i < N; i++)
		{
			graph[i].clear();
		}
		
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &u, &v);
			graph[u].push_back(mp(v, 2*i));
			graph[v].push_back(mp(u, 2*i + 1));
			
			c[u] ^= 1;
			c[v] ^= 1;
		}
		
		for (u = 1; u <= n; u++)
		{
			while (!c[u] && offset[u] < graph[u].size())
			{		
				if (diff[u] <= 0)
				{
					go(u, 1);
				}
				else 
				{
					go(u, -1);
				}
				
			}
		}
		
		for (u = 1; u <= n; u++)
		{
			if (!c[u])
			{
				ansCount[k]++;
			}
			for (i = 0; i < graph[u].size(); i++)
			{
				v = graph[u][i].first;
				idx = graph[u][i].second;
				if (!check[idx / 2])
				{
					check[idx / 2] = true;
					erased[idx ^ 1] = true;
					ansEdge[k].push_back(mp(u, v));
				}
				else if (!erased[idx])
				{
					ansEdge[k].push_back(mp(u, v));
				}
			}
		}
	}
	
	
	for (k = 1; k <= t; k++)
	{
		printf("%d\n", ansCount[k]);
		for (i = 0; i < ansEdge[k].size(); i++)
		{
			printf("%d %d\n", ansEdge[k][i].first, ansEdge[k][i].second);
		}
	}
	
	return 0;
}