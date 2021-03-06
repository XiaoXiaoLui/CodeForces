#include <iostream>
#include <set>
#include <vector>


using namespace std;

typedef long long ll;

#define pi pair<ll, int>
#define mp make_pair<ll, int>

const int N = 100005;
const ll MAX = ((ll)1) << 62;

vector<pi> graph[N];
set<pi> Q;
ll dist[N];
int pre[N];
int output[N];

int n, m, outLen;

int main()
{
	int i, j, u, v;
	ll w;
	cin >> n >> m;
	
	for (i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(mp(w, v));
		graph[v].push_back(mp(w, u));
	}
	
	for (i = 1; i <= n; i++)
	{	
		dist[i] = MAX;
		
	}
	dist[1] = 0;
	Q.insert(mp(dist[1], 1));
	
	set<pi>::iterator iter;
	while (!Q.empty())
	{
		u = Q.begin()->second;
		w = Q.begin()->first;
		Q.erase(Q.begin());
		
		dist[u] = w;
		if (u == n)
		{
			break;
		}
		
		for (i = 0; i < graph[u].size(); i++)
		{
			v = graph[u][i].second;
			w = graph[u][i].first;
			
			if (dist[u] + w < dist[v])
			{
				iter = Q.find(mp(dist[v], v));				
				if (iter != Q.end())
				{
					Q.erase(iter);
				}

				dist[v] = dist[u] + w;
				pre[v] = u;
				Q.insert(mp(dist[v], v));
			}
		}
	}
	
	if (dist[n] == MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		u = n;
		while (u)
		{
			output[outLen++] = u;
			u = pre[u];
		}
		
		for (i = outLen - 1; i >= 0; i--)
		{
			cout << output[i] << " ";
		}
		cout << endl;
	}
}