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

const int N = 5050;
const int INF = 1e9 + 50;

int n;
vector<pii> in[N];
vector<pii> out[N];
bool a[N][N];
int inDegree[N];

int dp[N][N];
int pre[N][N];
int srt[N];
vector<int> ans;

void topoSort()
{
	queue<int> Q;
	int u, v, i;
	for (u = 1; u <= n; u++)
	{
		if (inDegree[u] == 0)
		{
			Q.push(u);
		}
	}
	
	int idx = 0;
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		srt[idx++] = u;
		for (v = 1; v <= n; v++)
		{
			if (v == u)
			{
				continue;
			}
			if (a[u][v])
			{
				inDegree[v]--;
				if (inDegree[v] == 0)
				{
					Q.push(v);
				}
			}
			
		}
	}
}

int main()
{
	int m, i, j, k, u, v, w, t, T, len;
	scanf("%d%d%d", &n, &m, &T);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		out[u].push_back(mp(v, w));
		in[v].push_back(mp(u, w));
		a[u][v] = true;
		inDegree[v]++;
	}
	
	topoSort();
	
	fill((int*)dp, (int*)dp + N*N, INF);
	for (i = 0; srt[i] != 1; i++);
	
	// now srt[i] = 1
	dp[1][1] = 0;
	pre[1][1] = 0;
	for (i++; i <= n; i++)
	{
		v = srt[i];
		for (j = 0; j < in[v].size(); j++)
		{
			u = in[v][j].first;
			w = in[v][j].second;
			
			for (k = 1; k <= n; k++)
			{
				t = dp[u][k] + w;
				len = k + 1;
				if (t <= T && t <= dp[v][len])
				{
					dp[v][len] = t;
					pre[v][len] = u;
				}
			}	
		}
		
		if (srt[i] == n)
		{
			break;
		}
	}
	
	for (k = n; k >= 1; k--)
	{
		if (dp[n][k] <= T)
		{
			break;
		}
	}
	
	//ans.push_back(u);
	for (u = n; u; u = pre[u][k], k--)
	{
		ans.push_back(u);
	}
	
	printf("%d\n", ans.size());
	for (i = ans.size() - 1; i >= 0; i--)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}