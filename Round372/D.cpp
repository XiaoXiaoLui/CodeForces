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
#include <list>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1005;
const int M = 10005;
const ll LINF = 1e18;
const ll INF = 1e10;

struct Edge
{
	Edge(){}
	Edge(int vv, int index) : v(vv), idx(index)
	{
		
	}
	int v;
	int idx;
};


vector<Edge> graph[N];
int s, t;
ll dist[N];

ll we[M];
bool erased[M];
vector<int> nonAssignedEdges;

void dijkstra()
{
	fill(dist, dist + N, LINF);
	set<pair<ll, int> > S;
	set<pair<ll, int> >::iterator iter;
	S.insert(make_pair<ll, int>(0, s));
	dist[s] = 0;
	
	int u, v, idx, i;
	ll w;
	while (!S.empty())
	{
		u = S.begin()->second;
		S.erase(S.begin());
		
		for (i = 0; i < graph[u].size(); i++)
		{
			v = graph[u][i].v;
			idx = graph[u][i].idx;
			w = we[idx];
			if (dist[u] + w < dist[v])
			{
				iter = S.find(make_pair<ll, int>(dist[v], v));
				if (iter != S.end())
				{
					S.erase(iter);
				}
				dist[v] = dist[u] + w;
				S.insert(make_pair<ll, int>(dist[v], v));
			}
		}
	}
}

int main()
{
	int n, m, i, j, u, v, w, idx, num, p;
	ll minDist, maxDist, L;
	scanf("%d%d%lld%d%d", &n, &m, &L, &s, &t);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		if (w == 0)
		{
			erased[i] = true;
		}
		graph[u].push_back(Edge(v, i));
		graph[v].push_back(Edge(u, i));
		we[i] = w;
	}
	
	// max
	for (i = 0; i < m; i++)
	{
		if (erased[i])
		{
			we[i] = INF;
		}
	}
	dijkstra();
	maxDist = dist[t];
	
	// min
	for (i = 0; i < m; i++)
	{
		if (erased[i])
		{
			we[i] = 1;
		}
	}
	dijkstra();
	minDist = dist[t];
	
	
	
	if (L < minDist || L > maxDist)
	{
		printf("NO\n");
		return 0;
	}
	
	//list<int> nonAssignedEdges;
	for (i = 0; i < m; i++)
	{
		if (erased[i])
		{
			nonAssignedEdges.push_back(i);
		}
	}
	num = nonAssignedEdges.size();
	if (num == 0)
	{
		goto END;
	}
	
	
	// use binary search to find minimal p such that nonAssignedEdges[0-p]=1, p+1~num-1=INF and dist[t] <= L
	int d;
	p = num - 1;
	for (d = 1; p - d >= 0; d *= 2);
	
	for (; d; d /= 2)
	{
		if (p - d >= 0)
		{
			for (i = 0; i <= p - d; i++)
			{
				we[nonAssignedEdges[i]] = 1;
			}
			for (; i < num; i++)
			{
				we[nonAssignedEdges[i]] = INF;
			}
			dijkstra();
			
			if (dist[t] <= L)
			{
				p -= d;
			}
		}
	}
	
	
	for (i = 0; i <= p; i++)
	{
		we[nonAssignedEdges[i]] = 1;
	}
	for (; i < num; i++)
	{
		we[nonAssignedEdges[i]] = INF;
	}
	dijkstra();
	we[nonAssignedEdges[p]] += L - dist[t];
	
END:	
	printf("YES\n");
	for (u = 0; u < n; u++)
	{
		for (i = 0; i < graph[u].size(); i++)
		{
			v = graph[u][i].v;
			idx = graph[u][i].idx;
			if (u < v)
			{
				printf("%d %d %lld\n", u, v, we[idx]);
			}
		}
	}
	
	printf("\n");
	return 0;
}