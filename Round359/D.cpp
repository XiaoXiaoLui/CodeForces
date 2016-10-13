#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define mp make_pair<int, int>

const int N = 3e5 + 5;
int parent[N];
vector<int> son[N];
int c[N];
int size[N];
int maxChildSize[N];

int q[N];


void dfs(int u)
{
	int i, v;
	size[u] = 1;
	int maxChild = 0;
	for (i = 0; i < son[u].size(); i++)
	{
		v = son[u][i];
		dfs(v);
		size[u] += size[v];
		if (size[v] > maxChildSize[u])
		{
			maxChildSize[u] = size[v];
			maxChild = v;
		}
	}
	
	if (maxChildSize[u] * 2 <= size[u])
	{
		c[u] = u;
	}
	else
	{
		c[u] = c[maxChild];
		while ((size[u] - size[c[u]]) * 2 > size[u] || maxChildSize[c[u]] * 2 > size[u])
		{
			c[u] = parent[c[u]];
		}
	}
	
	
}

int main()
{
	int n, i, j, qNum, u;
	scanf("%d%d", &n, &qNum);
	for (i = 2; i <= n; i++)
	{
		scanf("%d", &parent[i]);
		son[parent[i]].push_back(i);
	}
	
	for (i = 0; i < qNum; i++)
	{
		scanf("%d", &q[i]);
	}
	dfs(1);
	for (i = 0; i < qNum; i++)
	{
		printf("%d\n", c[q[i]]);
	}
	
	
	return 0;
}


/*
consider vertex u, let v be the maxSize Child of u, let w be centroid of v, iterate through path from w to u, there are 2 case
1. size(v)<=size(u)/2, u itself is centroid of u.
2. size(v)>size(u)/2, along the path from w to v, the first vertex x satisfying the condition (size(x)>=size(u)/2) is centroid of u, such x must exist as x=v satisfy the condition.
let prove case 2, x must be a centroid of u.
if x=w, obviously true;
if x!=w, let y be the preceding vectex of x along the path(y is a child of x), there are 3 types of components, 
1.subtree(u) - subtree(x), obviously ok.
2.subtree(y), ok because size(y)<size(u)/2, otherwise the first vertex satisfying the condition will be y or some preceding vertex instead of x.
3.subtree(z) (z != y && z is a child of x), size(z) < size(v) - size(w) <= size(v)/2 < size(u)/2, ok



*/