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

const int N = 2e5 + 100;

vector<int> graph[N];
vector<int> comVec[N];
bool isTeam[N];
int size[N];
vector<pii> ans;

void dfsSize(int u, int pre)
{
	if (isTeam[u])
	{
		size[u] = 1;
	}
	
	for (auto v : graph[u])
	{
		if (v == pre)
		{
			continue;
		}
		dfsSize(v, u);
		size[u] += size[v];
	}
}

int dfsFindCenter(int u, int pre, int totSize)
{
	for (auto v : graph[u])
	{
		if (v == pre)
		{
			continue;
		}
		if (size[v] * 2 > totSize)
		{
			return dfsFindCenter(v, u, totSize);
		}
	}
	
	return u;
}

void dfsCollect(int u, int pre, int idx)
{
	if (isTeam[u])
	{
		comVec[idx].push_back(u);
	}
	
	for (auto v : graph[u])
	{
		if (v != pre)
		{
			dfsCollect(v, u, idx);
		}
	}
}

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif
	
	int n, m, i, j, u, v;
	
	scanf("%d%d", &n, &m);
	m *= 2;
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &u);
		isTeam[u] = true;
	}
	
	dfsSize(1, 0);
	int center = dfsFindCenter(1, 0, size[1]);
	
	for (i = 0; i < graph[center].size(); i++)
	{
		dfsCollect(graph[center][i], center, i);
	}
	
	if (isTeam[center])
	{
		comVec[i++].push_back(center);
	}
	
	int vecNum = i;
	set<pii, greater<pii> > S;
	for (i = 0; i < vecNum; i++)
	{
		if (!comVec[i].empty())
		{
			S.insert({comVec[i].size(), i});
		}
	}
	
	while (!S.empty())
	{
		i = S.begin()->second;
		S.erase(S.begin());
		j = S.begin()->second;
		S.erase(S.begin());
		
		u = comVec[i].back();
		v = comVec[j].back();
		comVec[i].pop_back();
		comVec[j].pop_back();
		ans.push_back({u, v});
		
		if (!comVec[i].empty())
		{
			S.insert({comVec[i].size(), i});
		}
		if (!comVec[j].empty())
		{
			S.insert({comVec[j].size(), j});
		}
	}
	
	printf("1\n%d\n", center);
	for (auto tmp : ans)
	{
		printf("%d %d %d\n", tmp.first, tmp.second, center);
	}
	
	return 0;
}