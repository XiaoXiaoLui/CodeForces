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
#include <list>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const ll LINF = 1e18;
const int N = 5050;
ll x[N], a[N], b[N], c[N], d[N];

ll myabs(ll res)
{
	return res >= 0 ? res : -res;
}

/* insert k between i and j
i->j
i->k->j

 - (x[j] - x[i]) - (d[i] + a[j]) + (x[k] - x[i]) + (x[k] - x[j]) + d[i] + a[k] + c[k] + b[j] = 2x[k] - 2x[j] + a[k] + c[k] + b[j] - a[j]
*/
ll calDiff(int i, int j, int k)
{
	ll res = 0;
	res -= myabs(x[i] - x[j]);
	if (i < j)
	{
		res -= d[i] + a[j];
	}
	else
	{
		res -= c[i] + b[j];
	}
	
	res += myabs(x[k] - x[i]) + myabs(x[j] - x[k]);
	if (i < k)
	{
		res += d[i] + a[k];
	}
	else
	{
		res += c[i] + b[k];
	}
	
	if (k < j)
	{
		res += d[k] + a[j];
	}
	else
	{
		res += c[k] + b[j];
	}
	
	return res;
}

int main()
{
	int n, s, e, i, j, last, pre;
	scanf("%d%d%d", &n, &s, &e);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &x[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &b[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &c[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &d[i]);
	}
	
	list<int> lst;
	list<int>::iterator iter, bestIter;
	ll ans = 0, curBest;
	
	
	if (s < e)
	{
		ans = myabs(x[s] - x[e]) + d[s] + a[e];
	}
	else
	{
		ans = myabs(x[s] - x[e]) + c[s] + b[e];
	}
	lst.push_back(e);
	
	for (i = 1; i <= n; i++)
	{
		if (i == s || i == e)
		{
			continue;
		}
		
		curBest = LINF;
		
		for (pre = s, iter = lst.begin(); iter != lst.end(); pre = *iter, iter++)
		{
			ll tmp = ans + calDiff(pre, *iter, i);
			if (tmp < curBest)
			{
				curBest = tmp;
				bestIter = iter;
			}
		}
		
		lst.insert(bestIter, i);
		ans = curBest;
	}
	
	
	
	printf("%lld\n", ans);
	return 0;
}