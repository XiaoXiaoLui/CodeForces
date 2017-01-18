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

const int N = 2e5 + 100;

pii couple[N];
int color[N];
vector<int> graph[N];

void dfs(int u, int c)
{
	color[u] = c;
	
	for (auto v : graph[u])
	{
		if (!color[v])
		{
			int nextC = c == 1 ? 2 : 1;
			
			dfs(v, nextC);
		}
	}
}

int main()
{
	//USE_IOSTREAM;
	
	int n, i, u, v;
	
	//cin >> n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		//cin >> u >> v;
		scanf("%d%d", &u, &v);
		couple[i] = {u, v};
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (u = 1; u < 2*n; u += 2)
	{
		v = u + 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (u = 1; u <= 2*n; u++)
	{
		if (!color[u])
		{
			dfs(u, 1);
		}
	}
	
	
	for (i = 1; i <= n; i++)
	{
		u = couple[i].first;
		v = couple[i].second;
		
		//cout << color[u] << " " << color[v] << endl;
		printf("%d %d\n", color[u], color[v]);
	}
	
	return 0;
}