#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 220;

vector<pii> graph[N];
int c[N];
bool check[N*N/2];
bool visit[N];


vector<pii> ansEdge[N];
int ansCount[N];
vector<int> ans;


void eulerPath(int start, int k)
{
	int u, v, i, idx;
	stack<int> S;
	S.push(start);
	
	while (!S.empty())
	{
		u = -1;
		while (!S.empty())
		{
			if (c[S.top()] > 0)
			{
				u = S.top();
				break;
			}
			else
			{
				ans.push_back(S.top());
				visit[S.top()] = true;
				S.pop();
			}
		}
		
		if (u == -1)
		{
			break;
		}
			
		do 
		{
			for (i = 0; check[graph[u][i].second]; i++);
			v = graph[u][i].first;
			idx = graph[u][i].second;
			
			check[idx] = true;
			c[u]--;
			c[v]--;
			S.push(v);
			
			// for this problem
			if (u && v)
			{
				ansEdge[k].push_back(mp(u, v));
			}
			u = v;
		} while (c[u]);
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
		memset(check, 0, sizeof(check));
		memset(visit, 0, sizeof(visit));
		
		for (i = 0; i < N; i++)
		{
			graph[i].clear();
		}
		
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &u, &v);
			graph[u].push_back(mp(v, i));
			graph[v].push_back(mp(u, i));
			
			c[u]++;
			c[v]++;
		}
		
		for (i = 1; i <= n; i++)
		{
			if (c[i] & 1)
			{
				c[i]++;
				c[0]++;
				++m;
				graph[0].push_back(mp(i, m));
				graph[i].push_back(mp(0, m));
			}
			else
			{
				ansCount[k]++;
			}
		}
		
		for (i = 0; i <= n; i++)
		{
			if (!visit[i] && c[i] > 0)
			{
				eulerPath(i, k);
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
	
	/*
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
		if (i == ans.size() - 1)
		{
			printf("\n");
		}
	}*/
	
	return 0;
}