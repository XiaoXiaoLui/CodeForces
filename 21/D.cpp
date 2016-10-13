#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define pi pair<int, int> 
#define mp make_pair<int, int>

const int N = 16;
const int M = 1 << 15;
const int MAX = 1 << 30;

struct Edge
{
	int u;
	int v;
	int w;
};

set<pi> Q;
vector<Edge> e;
int dist[M];
int graph[N][N];
int degree[N];
int visit[N];
int n, m;
int hasEdge[N];

void dfs(int u)
{
	visit[u] = 1;
	for (int v = 0; v < n; v++)
	{
		if (graph[u][v] != MAX && !visit[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	int u, v, w, i, initState, state1, state2;
	int ans = 0;
	cin >> n >> m;
	
	for (u = 0; u < n; u++)
	{
		for (v = 0; v < n; v++)
		{
			graph[u][v] = MAX;
		}
	}
	
	for (i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		ans += w;
		u--;
		v--;
		hasEdge[u] = hasEdge[v] = 1;
		if (u != v)
		{
			degree[u]++;
			degree[v]++;
			
			if (w < graph[u][v])
			{
				graph[u][v] = graph[v][u] = w;
			}
		}
	}
	
	dfs(0);
	
	for (i = 0; i < n; i++)
	{
		if (!visit[i] && hasEdge[i])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	
	
	Edge edge;
	for (u = 0; u < n; u++)
	{
		for (v = u + 1; v < n; v++)
		{
			if (graph[u][v] != MAX)
			{
				edge.u = u;
				edge.v = v;
				edge.w = graph[u][v];
				e.push_back(edge);
				
			}
		}
		
	}
	
	for (initState = 0, u = 0; u < n; u++)
	{
		initState ^= (degree[u] & 1) << u;
	}
	
	for (i = 0; i < M; i++)
	{
		dist[i] = MAX;
	}
	
	dist[initState] = 0;
	Q.insert(mp(dist[initState], initState));
	
	set<pi>::iterator iter;
	while (!Q.empty())
	{
		state1 = Q.begin()->second;
		Q.erase(Q.begin());
		
		if (state1 == 0)
		{
			break;
		}
		
		for (i = 0; i < e.size(); i++)
		{
			state2 = state1 ^ (1 << e[i].u) ^ (1 << e[i].v);
			
			if (dist[state1] + e[i].w < dist[state2])
			{
				iter = Q.find(mp(dist[state2], state2));
				if (iter != Q.end())
				{
					Q.erase(iter);
				}
				
				dist[state2] = dist[state1] + e[i].w;
				Q.insert(mp(dist[state2], state2));
			}
		}
	}
	
	cout << ans + dist[0] << endl;
	
	return 0;
}