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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 2e5 + 100;

vector<int> graph[N];
int c[N];
bool visit[N];
vector<int> cash;
int cnt[N];
int tot;

void dfs(int u)
{
	int i, v;
	visit[u] = true;
	tot++;
	
	cnt[c[u]]++;
	if (cnt[c[u]] == 1)
	{
		cash.push_back(c[u]);
	}
	
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (!visit[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	// USE_IOSTREAM;
	int n, m, kNum, u, v, i;
	
	scanf("%d%d%d", &n, &m, &kNum);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int ans = 0, curMax;
	for (u = 1; u <= n; u++)
	{
		if (!visit[u])
		{
			dfs(u);
		}
		
		curMax = 0;
		for (i = 0; i < cash.size(); i++)
		{
			curMax = max(curMax, cnt[cash[i]]);
			cnt[cash[i]] = 0;
		}
		
		ans += tot - curMax;
		
		tot = 0;
		cash.clear();
	}
	
	printf("%d\n", ans);
	
	return 0;
}