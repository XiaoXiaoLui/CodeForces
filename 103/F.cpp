#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <list>
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

class PushToFront
{
public:
	PushToFront() : edgeNum(1)
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
	
	ll getMaxFlow()
	{
		int i, u, v;
		fill(h, h + n, 0);
		fill(ex, ex + n, 0);
		h[s] = n;
		
		for (i = head[s]; i; i = next[i])
		{
			Edge &e = edge[i];
			if (e.cap > 0)
			{
				ex[s] -= e.cap;
				ex[e.v] += e.cap;
				edge[i ^ 1].cap += e.cap;
				e.cap = 0;
			}
		}
		
		int lstLen = 1;
		front = 1;
		for (i = 0; i < n; i++)
		{
			if (i == s || i == t)
			{
				continue;
			}
			lst[lstLen].u = i;
			lst[lstLen].left = lstLen - 1;
			lst[lstLen].right = lstLen + 1;
			
			lstLen++;
			current[i] = head[i];
		}
		
		lst[lstLen - 1].right = 0;
		
		
		int oldHeight;
		for (i = 1; i != 0; i = lst[i].right)
		{
			u = lst[i].u;
			oldHeight = h[u];
			discharge(u);
			if (h[u] > oldHeight)
			{
				lst[lst[i].left].right = lst[i].right;
				lst[lst[i].right].left = lst[i].left;
				if (i == front)
				{
					front = lst[i].right;
				}
				lst[i].left = 0;
				lst[i].right = front;
				lst[front].left = i;
				front = i;
			}
			
		}
	
		return -ex[s];
	}
	
private:	
	void push(int idx)
	{
		int u, v, tmp;
		u = edge[idx].u;
		v = edge[idx].v;
		
		tmp = min(ex[u], edge[idx].cap);
		
		ex[u] -= tmp;
		ex[v] += tmp;
		edge[idx].cap -= tmp;
		edge[idx ^ 1].cap += tmp;
	}
	
	void relabel(int u)
	{
		int i;
		int newHeight = 2*n + 10;
		for (i = head[u]; i; i = next[i])
		{
			const Edge &e = edge[i];
			if (e.cap > 0)
			{
				newHeight = min(newHeight, h[e.v]);
			}
		}
		
		h[u] = newHeight + 1;
	}
	
	void discharge(int u)
	{
		int i;
		while (ex[u] > 0)
		{
			if (!current[u])
			{
				relabel(u);
				current[u] = head[u];
			}
			else 
			{
				Edge &e = edge[current[u]];
				if (e.cap > 0 && h[u] == h[e.v] + 1)
				{
					push(current[u]);
				}
				else
				{
					current[u] = next[current[u]];
				}
			}
		}
	}
	
	int head[N];
	int next[N*N];
	
	int h[N];
	ll ex[N];
	
	int current[N];
	Edge edge[N*N];
	int edgeNum;
	int s, t, n;
	
	// for list
	struct Node
	{
		int left;
		int right;
		int u;
	};
	
	Node lst[N];
	int front;

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
	
	ans -= maxFlow.getMaxFlow();
	
	printf("%lld\n", -ans);
	return 0;
}