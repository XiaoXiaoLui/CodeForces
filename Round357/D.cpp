#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n;
int m;
int p[N];
int w[N];
bool visit[N];
bool hasSon[N];
bool used[N];

vector<int> ans[N];

int main()
{
	int u, v, i, j, pre;
	bool ok = true;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		p[v] = u;
		hasSon[u] = true;
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	
	int preWant;
	int len = 0;
	for (i = 1; i <= n && ok; i++)
	{
		if (hasSon[i])
		{
			continue;
		}
		
		u = i;
		pre = u;
		if (!used[w[u]])
		{
			ans[len].push_back(w[u]);
			used[w[u]] = true;
		}
		for (u = p[u]; u != 0 && !visit[u]; u = p[u])
		{
			if (w[pre] != pre && w[u] != w[pre])
			{
				ok = false;
				break;
			}
			if (!used[w[u]])
			{
				ans[len].push_back(w[u]);
				used[w[u]] = true;
			}
			pre = u;
			visit[u] = true;
		}
		
		if (visit[u])
		{
			if (w[pre] != pre && w[u] != w[pre])
			{
				ok = false;
				break;
			}
		}
		
		
		len++;
	}
	
	if (!ok)
	{
		printf("-1\n");
	}
	else
	{
		int sum = 0;
		for (i = len - 1; i >= 0; i--)
		{
			sum += ans[i].size();
		}
		printf("%d\n", sum);
		for (i = len - 1; i >= 0; i--)
		{
			for (j = 0; j < ans[i].size(); j++)
			{
				printf("%d\n", ans[i][j]);
			}
		}
	
	}
	
	return 0;
}