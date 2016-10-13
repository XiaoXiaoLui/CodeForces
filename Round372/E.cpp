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

const int N = 1e5 + 100;

ll M, PHI;
ll myExp[N];
ll invmyExp[N];


int phi(int n)
{
	int i, j, p;
	int res = n;
	
	for (i = 2; i < N; i++)
	{
		p = i;
		if (n % p == 0)
		{
			res = res / p * (p - 1);
		}
		
		while (n % p == 0)
		{
			n /= p;
		}
	}
	
	if (n > 1)
	{
		res = res / n * (n - 1);
	}
	
	return res;
}

ll mypow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % M;
		}
		
		b >>= 1;
		a = (a * a) % M;
	}
	
	return res;
}


// pii.first = v, pii.second = digit
vector<pii> graph[N];
bool visit[N];
int c[N];
int h[N];
ll up[N];
ll down[N];
int curTreeSize;


map<ll, int> treeMap;
map<ll, int> subMap[N];

void dfsCount(int u, int pre)
{
	int v, i;
	c[u] = 1;
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		if (visit[v] || v == pre)
		{
			continue;
		}
		
		dfsCount(v, u);
		c[u] += c[v];
	}
	
	if (pre == 0)
	{
		curTreeSize = c[u];
	}
}

int findCentroid(int u, int pre)
{
	int v, i;
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		if (visit[v] || v == pre)
		{
			continue;
		}
		
		if (c[v] * 2 > curTreeSize)
		{
			return findCentroid(v, u);
		}
	}
	
	return u;
}

void dfsCalUpDown(int u, int pre)
{
	int v, i, w;
	
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		w = graph[u][i].second;
		if (visit[v] || v == pre)
		{
			continue;
		}
		
		h[v] = h[u] + 1;
		up[v] = (w * myExp[h[v] - 1] + up[u]) % M;
		down[v] = (down[u] * 10 + w) % M;
		dfsCalUpDown(v, u);
	}
}

void dfsBuildMap(int u, int pre, map<ll, int> &countMap)
{
	int i, v;
	int tmpDebug;
	tmpDebug = countMap[up[u]]++;
	
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		if (visit[v] || v == pre)
		{
			continue;
		}
		dfsBuildMap(v, u, countMap);
	}
}

ll dfsCalNum(int u, int pre, int idx)
{
	int i, v;
	int tmpDebug1, tmpDebug2;
	ll res = 0;
	ll d = (M - down[u]) * invmyExp[h[u]] % M;
	
	tmpDebug1 = treeMap[d];
	tmpDebug2 = subMap[idx][d];
	res = tmpDebug1 - tmpDebug2;
	
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		if (visit[v] || v == pre)
		{
			continue;
		}
		
		res += dfsCalNum(v, u, idx);
	}
	
	return res;
}


ll calPassRoot(int u)
{
	int i, v;
	
	h[u] = 0;
	up[u] = down[u] = 0;
	dfsCalUpDown(u, 0);
	
	treeMap.clear();
	dfsBuildMap(u, 0, treeMap);
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		if (visit[v])
		{
			continue;
		}
		
		subMap[i].clear();
		dfsBuildMap(v, u, subMap[i]);
	}
	
	
	ll res = 0;
	res = treeMap[0] - 1;
	
	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		if (visit[v])
		{
			continue;
		}
		res += dfsCalNum(v, u, i);
	}
	
	return res;
}

ll solve(int u)
{
	int root, v, i;
	dfsCount(u, 0);
	root = findCentroid(u, 0);
	
	visit[root] = true;
	
	ll res = calPassRoot(root);
	for (i = 0; i < graph[root].size(); i++)
	{
		v = graph[root][i].first;
		if (visit[v])
		{
			continue;
		}
		
		res += solve(v);
	}
	
	
	return res;
}


int main()
{
	int n, i, u, v, w;

	scanf("%d%lld", &n, &M);
	for (i = 1; i < n; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		u++, v++;
		graph[u].push_back(mp(v, w));
		graph[v].push_back(mp(u, w));
	}
	
	if (M == 1)
	{
		printf("%lld\n", (ll)n * (n - 1));
		return 0;
	}

	PHI = phi(M);
	myExp[0] = 1;
	invmyExp[0] = 1;
	
	ll inv10 = mypow(10, PHI - 1);
	for (i = 1; i < N; i++)
	{
		myExp[i] = (myExp[i - 1] * 10) % M;
		invmyExp[i] = (invmyExp[i - 1] * inv10) % M;
	}
	
	
	ll ans = solve(1);
	
	printf("%lld\n", ans);
	return 0;
}