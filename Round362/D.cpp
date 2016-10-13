#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;


const int N = 1e5 + 5;

vector<int> son[N];
int parent[N];
int c[N];
double ans[N];

void dfsCount(int u)
{
	int i, v;
	c[u] = 1;
	for (i = 0; i < son[u].size(); i++)
	{
		v = son[u][i];
		dfsCount(v);
		c[u] += c[v];
	}
}


void dfsCal(int u)
{
	int i, v;
	double tmp = 0.0;
	int sum;
	for (i = 0; i < son[u].size(); i++)
	{
		v = son[u][i];
		sum = c[u] - c[v] - 1;
		ans[v] = ans[u] + 1 + sum / 2.0;
		dfsCal(v);
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		scanf("%d", &parent[i]);
		son[parent[i]].push_back(i);
	}
	
	dfsCount(1);
	
	ans[1] = 1.0;
	dfsCal(1);
	
	for (i = 1; i <= n; i++)
	{
		printf("%.9lf ", ans[i]);
	}
	
	printf("\n");
	return 0;
}