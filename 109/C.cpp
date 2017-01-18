// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 1e5 + 100;

vector<pii> graph[N];
int lucky[N];
int size[N];
ll ans;

void dfs1(int u, int pre)
{
	size[u] = 1;
	
	for (auto tmp : graph[u])
	{
		int v = tmp.first;
		int w = tmp.second;
		if (v == pre)
		{
			continue;
		}
		
		dfs1(v, u);
		size[u] += size[v];
		if (w)
		{
			lucky[u] += size[v];
		}
		else
		{
			lucky[u] += lucky[v];
		}
	}
	
	ans += (ll)lucky[u] * (lucky[u] - 1);
}

void dfs2(int u, int pre, int preLucky, int preSize)
{
	ans += (ll)preLucky * (preLucky - 1);
	ans += (ll)preLucky * lucky[u] * 2;
	for (auto tmp : graph[u])
	{
		int v = tmp.first;
		int w = tmp.second;
		if (v == pre)
		{
			continue;
		}
		
		int curSize = preSize + size[u] - size[v];
		int curLucky = w ? curSize : preLucky + lucky[u] - lucky[v];
		
		dfs2(v, u, curLucky, curSize);
	}
}

bool isLucky(int num)
{
	while (num)
	{
		if (num % 10 != 4 && num % 10 != 7)
		{
			return false;
		}
		num /= 10;
	}
	return true;
}

int main()
{
	USE_IOSTREAM;
	int n, i, u, v, w;
	cin >> n;
	for (i = 2; i <= n; i++)
	{
		cin >> u >> v >> w;
		w = isLucky(w);
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	
	dfs1(1, 0);
	dfs2(1, 0, 0, 0);
	
	cout << ans << endl;
	
	return 0;
}