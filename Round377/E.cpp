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
int com[N];
int soc[N];
int cnt[N];
int ans[N];
bool used[N];

int main()
{
	// USE_IOSTREAM;
	int n, m, i, j, c, u, idx;
	scanf("%d%d", &n, &m);
	
	set<pii> comSet;
	set<pii> socSet;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &com[i]);
		comSet.insert(mp(com[i], i));
	}
	
	set<pii>::iterator iter;
	c = u = 0;
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &soc[i]);
		iter = comSet.lower_bound(mp(soc[i], 0));
		if (iter != comSet.end() && iter->first == soc[i])
		{
			ans[iter->second] = i;
			comSet.erase(iter);
			c++;
			used[i] = true;
		}
		else
		{
			if (soc[i] > 1)
			{
				socSet.insert(mp(soc[i], i));
			}
		}
	}
	
	while (!socSet.empty() && !comSet.empty())
	{
		idx = socSet.begin()->second;
		socSet.erase(socSet.begin());
		
		while (soc[idx] > 1)
		{
			cnt[idx]++;
			soc[idx] = (soc[idx] + 1) / 2;
			
			iter = comSet.lower_bound(mp(soc[idx], 0));
			if (iter != comSet.end() && iter->first == soc[idx])
			{
				ans[iter->second] = idx;
				comSet.erase(iter);
				c++;
				used[idx] = true;
				break;
			}
		}
	}
	
	for (i = 1, u = 0; i <= m; i++)
	{
		if (used[i])
		{
			u += cnt[i];
		}
	}
	
	printf("%d %d\n", c, u);
	for (i = 1; i <= m; i++)
	{
		if (used[i])
		{
			printf("%d ", cnt[i]);
		}
		else
		{
			printf("0 ");
		}
	}
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}