#include<bits/stdc++.h>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 1005;

int b[N];
int w[N];
vector<int> graph[N];
bool visit[N];
vector<int> com[N];
int dp[2*N][N];

void dfs(int u, int c)
{
	com[c].push_back(u);
	visit[u] = true;
	
	for (auto v : graph[u])
	{
		if (!visit[v])
		{
			dfs(v, c);
		}
	}
}

int main()
{
	USE_IOSTREAM;
	
	int n, m, u, v, i, j, maxW, comNum, sumB, sumW;
	
	cin >> n >> m >> maxW;
	for (i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	
	for (i = 1; i <= m; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	comNum = 0;
	for (u = 1; u <= n; u++)
	{
		if (!visit[u])
		{
			dfs(u, ++comNum);
		}
	}
	
	int idx = 0;
	for (i = 1; i <= comNum; i++)
	{
		sumB = sumW = 0;
		++idx;
		for (j = 0; j <= maxW; j++)
		{
			dp[idx][j] = dp[idx - 1][j];
		}
		for (auto u : com[i])
		{
			sumB += b[u];
			sumW += w[u];
			
			for (j = 0; j + w[u] <= maxW; j++)
			{
				dp[idx][j + w[u]] = max(dp[idx][j + w[u]], dp[idx - 1][j] + b[u]);
			}
		}
		
		for (j = 0; j + sumW <= maxW; j++)
		{
			dp[idx][j + sumW] = max(dp[idx][j + sumW], dp[idx - 1][j] + sumB);
		}
	}
	
	
	cout << dp[idx][maxW] << endl;
	return 0;
}