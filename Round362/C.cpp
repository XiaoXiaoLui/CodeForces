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


map<ll, ll> costMap;

ll calCost(ll u, ll v)
{
	ll res = 0LL;
	while (u != v)
	{
		if (u > v)
		{
			res += costMap[u];
			u /= 2;
		}
		else
		{
			res += costMap[v];
			v /= 2;
		}
	}
	return res;
}

void inc(ll u, ll v, ll w)
{
	while (u != v)
	{
		if (u > v)
		{
			costMap[u] += w;
			u /= 2;
		}
		else
		{
			costMap[v] += w;
			v /= 2;
		}
	}
}

vector<ll> ans;
int main()
{
	int i, n, type;
	ll u, v, w;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf(LLD LLD LLD, &u, &v, &w);
			inc(u, v, w);
		}
		else
		{
			scanf(LLD LLD, &u, &v);
			ans.push_back(calCost(u, v));
		}
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		printf(LLD "\n", ans[i]);
	}
	
	printf("\n");
	return 0;
}