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
	DinicAlgo() : edgeNum(1)
	{
	}
	
	void init(int s, int t, int n)
	{
		this->s = s;
		this->t = t;
		this->n = n;
		
		fill(head, head + n, 0);
	}
	
	void addEdge(int u, int v, ll w)
	{
		edge[++edgeNum] = Edge(u, v, w);
		next[edgeNum] = head[u];
		head[u] = edgeNum;
		
		edge[++edgeNum] = Edge(v, u, 0);
		next[edgeNum] = head[v];
		head[v] = edgeNum;
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

		front = rear = 0;
		
		q[rear++] = s;
		
		int u, v, i;
		Edge e;
		while (front != rear && dist[t] == -1)
		{
			u = q[front];
			front = (front + 1) % n;
			
			for (i = head[u]; i; i = next[i])
			{
				e = edge[i];
				if (dist[e.v] == -1 && e.cap > 0)
				{
					dist[e.v] = dist[u] + 1;
					q[rear] = e.v;
					rear = (rear + 1) % n;
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
		for (i = head[u]; i; i = next[i])
		{
			Edge &e1 = edge[i];
			Edge &e2 = edge[i ^ 1];
			
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
	
	
	Edge edge[N*N];
	int next[N*N];
	int head[N];
	int edgeNum;
	int dist[N];
	int s, t, n;
	
	// for queue
	int q[N];
	int front, rear;

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