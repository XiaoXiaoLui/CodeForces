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

const int N = 1e5 + 50;
const ll LINF = 1e18;

struct Edge
{
	Edge(){}
	Edge(int a, ll b) : v(a), w(b)
	{
		
	}
	int v;
	ll w;
};

vector<Edge> graph[N];
ll d[N];

int main()
{
	int n, m, k, i, j, u, v, w;

	scanf("%d%d%d", &n, &m, &k);
	
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		graph[u].push_back(Edge(v, w));
		graph[v].push_back(Edge(u, w));
	}
	
	fill(d, d + N, LINF);
	for (i = 0; i < k; i++)
	{
		scanf("%d", &u);
		d[u] = 0;
		for (j = 0; j < graph[u].size(); j++)
		{
			Edge e = graph[u][j];
			d[e.v] = min(d[e.v], e.w);
		}
	}
	
	int minP = 0;
	for (i = 1; i <= n; i++)
	{
		if (d[i] != 0 && d[i] < d[minP])
		{
			minP = i;
		}
	}
	
	if (minP != 0)
	{
		printf("%lld\n", d[minP]);
	}
	else
	{
		printf("-1\n");
	}
	

	
	printf("\n");
	return 0;
}