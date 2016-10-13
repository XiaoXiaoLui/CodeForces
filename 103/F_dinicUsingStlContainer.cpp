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

const ll INF = 1e9;
const ll LINF = 1e13;
const int N = 650;

struct  Edge
{
	Edge(){}
	Edge(int uu, int vv, ll c) : u(uu), v(vv), cap(c)
	{
	}
	int u;
	int v;
	ll cap;
};

class DinicAlgo
{
public:
	DinicAlgo() : edgeNum(0)
	{
	}
	
	void init(int s, int t, int n)
	{
		this->s = s;
		this->t = t;
		this->n = n;
	}
	
	void addEdge(int u, int v, ll w)
	{
		graph[u].push_back(edgeNum);
		edge[edgeNum++] = Edge(u, v, w);
		
		graph[v].push_back(edgeNum);
		edge[edgeNum++] = Edge(v, u, 0);
	}
	
	ll dinic()
	{
		ll sum = 0;
		int i;
		
		while (bfs())
		{
			sum += find(s, LINF);
		}
		
		return sum;
	}
	
private:
	bool bfs()
	{
		fill(dist, dist + n, -1);
		dist[s] = 0;
		queue<int> Q;
		Q.push(s);
		
		int u, v, i;
		Edge e;
		while (!Q.empty() && dist[t] == -1)
		{
			u = Q.front();
			Q.pop();
			for (i = 0; i < graph[u].size(); i++)
			{
				e = edge[graph[u][i]];
				if (dist[e.v] == -1 && e.cap > 0)
				{
					dist[e.v] = dist[u] + 1;
					Q.push(e.v);
				}
			}
		}
		
		return dist[t] != -1;
	}
	
	ll find(int u, ll maxFlow)
	{
		if (u == t || maxFlow == 0)
		{
			return maxFlow;
		}
		
		ll res, tmp;
		int v, i;
		//Edge e;
		
		res = 0LL;
		for (i = 0; i < graph[u].size(); i++)
		{
			Edge &e1 = edge[graph[u][i]];
			Edge &e2 = edge[graph[u][i] ^ 1];
			
			if (e1.cap > 0 && dist[e1.v] == dist[u] + 1)
			{
				tmp = find(e1.v, min(maxFlow - res, e1.cap));
				e1.cap -= tmp;
				e2.cap += tmp;
				res += tmp;
			}
		}
		
		if (res == 0LL)
		{
			dist[u] = INF;
		}
		
		return res;
	}
	
	
	vector<int> graph[N];
	Edge edge[N*N];
	int edgeNum;
	int dist[N];
	int s, t, n;

} maxFlow;

int main()
{
	int s, t, n, i, num, j, k;
	ll ans;
	scanf("%d", &n);
	maxFlow.init(0, 2*n + 1, 2*n + 2);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		while (num--)
		{
			scanf("%d", &j);
			maxFlow.addEdge(i, n + j, LINF);
		}
	}
	
	ans = 0LL;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		ans += INF - k;
		maxFlow.addEdge(0, i, INF - k);
	}
	
	for (i = 1; i <= n; i++)
	{
		maxFlow.addEdge(n + i, 2*n + 1, INF);
	}
	
	ans -= maxFlow.dinic();
	
	printf("%lld\n", -ans);
	return 0;
}