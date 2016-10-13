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

const int N = 4e5 + 50;

vector<int> graph[N];
int n;
int cnt[N];
int maxIndex1, maxIndex2;
int root;
int ans[N];

void dfscnt(int u, int pre)
{
	int v, i;
	cnt[u] = 1;
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v == pre)
		{
			continue;
		}
		
		dfscnt(v, u);
		cnt[u] += cnt[v];
	}
}

void findCenter(int u, int pre)
{
	int v, i;
	int maxIdx = 0, maxSize = 0;
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v == pre)
		{
			continue;
		}
		
		if (cnt[v] > maxSize)
		{
			maxIdx = v;
			maxSize = cnt[v];
		}
	}
	
	if (2 * maxSize <= n)
	{
		root = u;
	}
	else
	{
		findCenter(maxIdx, u);
	}
}

void dfsSolve(int u, int pre, int ti, bool ok)
{
	int v, i;
	
	if (ok)
	{
		ans[u] = 1;
		
	}
	else if (ti == maxIndex1)
	{
		if ((cnt[u] + cnt[maxIndex2]) * 2 >= n)
		{
			ans[u] = 1;
		}
		else
		{
			ans[u] = 0;
		}
	}
	else
	{
		if ((cnt[u] + cnt[maxIndex1]) * 2 >= n)
		{
			ans[u] = 1;
		}
		else
		{
			ans[u] = 0;
		}
	}
	
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v == pre)
		{
			continue;
		}
		dfsSolve(v, u, ti, ok);
	}	
}

int main()
{
	int i, u, v;
	scanf("%d", &n);
	
	for (i = 1; i <= n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfscnt(1, 0);
	findCenter(1, 0);
	dfscnt(root, 0);
	//cnt[0] = 0;
	
	for (i = 0; i < graph[root].size(); i++)
	{
		v = graph[root][i];
		if (cnt[v] > cnt[maxIndex1])
		{
			maxIndex2 = maxIndex1;
			maxIndex1 = v;
		}
		else if (cnt[v] > cnt[maxIndex2])
		{
			maxIndex2 = v;
		}
	}
	
	for (i = 0; i < graph[root].size(); i++)
	{
		v = graph[root][i];
		if (cnt[v] * 2 == n)
		{
			dfsSolve(v, root, v, true);
		}
		else
		{
			dfsSolve(v, root, v, false);
		}
	}
	
	ans[root] = 1;
	for (i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}