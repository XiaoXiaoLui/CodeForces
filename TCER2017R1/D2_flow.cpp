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
const int M = 60;

const string STR_SIZE[] = {"", "S", "M", "L", "XL", "XXL", "XXXL"};
int num[10];
int w[N];
//vector<int> lst[80];
//vector<int> w[N];
int ans[N];
int cnt[80];

inline int str2Num(const string &a)
{
	int i = 1;
	for (i = 1; i <= 6; i++)
	{
		if (a == STR_SIZE[i])
		{
			return i;
		}
	}
	
	return 0;
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
	
	bool dinic(int pNum)
	{
		int sum = 0;
		int i;
		
		while (bfs())
		{
			sum += find(s, INF);
		}
		
		if (sum != pNum)
		{
			return false;
		}
		
		int u, e;
		for (i = 1; i <= pNum; i++)
		{
			u = w[i];
			for (e = head[u]; e; e = next[e])
			{
				if (edge[e].v != 0 && edge[e + 1].cap)
				{
					ans[i] = edge[e].v - M;
					edge[e + 1].cap--;
					break;
				}
			}
			
		}
		
		return true;
		//return sum;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool ok = true;
	int n, i, pos, idx1, idx2, m;
	
	m = 70;
	
	for (i = 1; i <= 6; i++)
	{
		cin >> num[i];
	}
	
	string cur;
	cin >> n;
	
	maxFlowObj.init(0, m, m + 1);
	
	for (i = 1; i <= n; i++)
	{
		cin >> cur;
		pos = cur.find(',');
		if (pos != string::npos)
		{
			idx1 = str2Num(cur.substr(0, pos));
			idx2 = str2Num(cur.substr(pos + 1, string::npos));
		}
		else
		{
			idx1 = str2Num(cur);
			idx2 = 0;
		}
		
		w[i] = 10*idx1 + idx2;
		
		cnt[w[i]]++;
	}
	
	for (i = 10; i <= M; i++)
	{
		if (cnt[i] == 0)
		{
			continue;
		}
		idx1 = i / 10;
		idx2 = i % 10;
		
		maxFlowObj.addEdge(0, i, cnt[i]);
		maxFlowObj.addEdge(i, M + idx1, cnt[i]);
		if (idx2)
		{
			maxFlowObj.addEdge(i, M + idx2, cnt[i]);
		}	
	}
	
	for (i = 1; i <= 6; i++)
	{
		if (num[i])
		{
			maxFlowObj.addEdge(M + i, m, num[i]);
		}
	}
	
	ok = maxFlowObj.dinic(n);
	
	
	if (ok)
	{
		cout << "YES" << endl;
		for (i = 1; i <= n; i++)
		{
			cout << STR_SIZE[ans[i]] << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
		
	}
	

	return 0;
}