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

const ll MOD = 1e9 + 7;
const int N = 110;
const int M = 25;

ll dp[N][M][M];
ll curDp[M][M];

int n, k;
vector<int> graph[N];
int parent[N];
int Q[N];

pii cal(int w1, int b1, int w2, int b2)
{
	if (w1 + b2 <= k)
	{
		w1 = 0;
	}
	
	if (w2 + b1 <= k)
	{
		w2 = 0;
	}
	else if (w2)
	{
		w2++;
	}
	
	b2++;
	
	return mp(max(w1, w2), min(b1, b2));
}

int main()
{
	// USE_IOSTREAM;
	int i, u,v, left, right, w1, w2, b1, b2, w, b;
	scanf("%d%d", &n, &k);
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	left = 0;
	right = 1;
	Q[left] = 1;
	while (left < right)
	{
		u = Q[left++];
		for (auto v : graph[u])
		{
			if (v != parent[u])
			{
				parent[v] = u;
				Q[right++] = v;
			}
		}
	}
	
	for (i = n - 1; i >= 0; i--)
	{
		u = Q[i];
		dp[u][0][0] = 1;
		dp[u][1][k + 1] = 1;
		
		for (auto v : graph[u])
		{
			if (v == parent[u])
			{
				continue;
			}
			
			for (w1 = 0; w1 <= k + 1; w1++)
			{
				for (b1 = 0; b1 <= k + 1; b1++)
				{
					curDp[w1][b1] = dp[u][w1][b1];
				}
			}
			
			fill_n((ll*)dp[u], M*M, 0);
			
			for (w1 = 0; w1 <= k + 1; w1++)
			{
				for (b1 = 0; b1 <= k + 1; b1++)
				{
					for (w2 = 0; w2 <= k + 1; w2++)
					{
						for (b2 = 0; b2 <= k + 1; b2++)
						{
							pii tmp = cal(w1, b1, w2, b2);
							w = tmp.first;
							b = tmp.second;
							dp[u][w][b] = (dp[u][w][b] +  curDp[w1][b1]*dp[v][w2][b2]) % MOD;
						}
					}
				}
			}
		}
	}
	
	
	ll ans = 0LL;
	for (i = 0; i <= k; i++)
	{
		ans = (ans + dp[1][0][i]) % MOD;
	}
	
	printf("%lld\n", ans);
	return 0;
}