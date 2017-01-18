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

const int N = 1e5 + 20;

const string STR_SIZE[7] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int num[10];
//vector<int> w[N];
int ans[N];

inline int str2Num(const string &a)
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		if (a == STR_SIZE[i])
		{
			break;
		}
	}
	
	return i + 1;
}

struct  Edge
{
	Edge(){}
	Edge(int uu, int vv, int c) : u(uu), v(vv), cap(c)
	{
	}
	int u;
	int v;
	int cap;
};

const int INF = 1e9;

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
	
	void addEdge(int u, int v, int w)
	{
		edge[++edgeNum] = Edge(u, v, w);
		next[edgeNum] = head[u];
		head[u] = edgeNum;
		
		edge[++edgeNum] = Edge(v, u, 0);
		next[edgeNum] = head[v];
		head[v] = edgeNum;
	}
	
	int dinic(int vNum)
	{
		int sum = 0;
		int i;
		
		while (bfs())
		{
			sum += find(s, INF);
		}
		
		for (i = 2; i < edgeNum; i += 2)
		{
			if (edge[i].u > 0 && edge[i].u <= vNum && edge[i].v != 0 && !edge[i].cap)
			{
				ans[edge[i].u] = edge[i].v - vNum;
			}
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
			u = q[front++];
			
			for (i = head[u]; i; i = next[i])
			{
				e = edge[i];
				if (dist[e.v] == -1 && e.cap > 0)
				{
					dist[e.v] = dist[u] + 1;
					q[rear++] = e.v;
				}
			}
		}
		
		return dist[t] != -1;
	}
	
	int find(int u, int maxFlow)
	{
		if (u == t || maxFlow == 0)
		{
			return maxFlow;
		}
		
		int res, tmp;
		int v, i;
		//Edge e;
		
		res = 0;
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
		
		if (res == 0)
		{
			dist[u] = INF;
		}
		
		return res;
	}
	
	
	Edge edge[2*N];
	int next[2*N];
	int head[N];
	int edgeNum;
	int dist[N];
	int s, t, n;
	
	// for queue
	int q[N];
	int front, rear;

} maxFlowObj;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool ok = true;
	int n, i, pos, idx, m, c;
	
	for (i = 1; i <= 6; i++)
	{
		cin >> num[i];
	}
	
	string tmp, cur;
	cin >> n;
	m = n + 7;
	maxFlowObj.init(0, m, m + 1);
	
	c = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> cur;
		pos = cur.find(',');
		if (pos != string::npos)
		{
			idx = str2Num(cur.substr(0, pos));
			maxFlowObj.addEdge(i, n + idx, 1);
			
			idx = str2Num(cur.substr(pos + 1, cur.size() - pos - 1));
			maxFlowObj.addEdge(i, n + idx, 1);
			
			maxFlowObj.addEdge(0, i, 1);
		}
		else
		{
			c++;
			idx = str2Num(cur);
			num[idx]--;
			if (num[idx] < 0)
			{
				ok = false;
				break;
			}
			ans[i] = idx;
		}
	}
	
	
	if (ok)
	{
		for (i = 1; i <= 6; i++)
		{
			if (num[i])
			{
				maxFlowObj.addEdge(n + i, m, num[i]);
			}
			
		}
		ok = (maxFlowObj.dinic(n) == n - c);
	}
	
	if (ok)
	{
		cout << "YES" << endl;
		for (i = 1; i <= n; i++)
		{
			cout << STR_SIZE[ans[i] - 1] << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
		
	}
	

	return 0;
}