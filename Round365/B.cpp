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

const int N = 1e5 + 50;
ll c[N];
ll total;
int cap[N];
bool isCap[N];

int main()
{
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &c[i]);
	}

	for (i = 0; i < k; i++)
	{
		scanf("%d", &cap[i]);
		cap[i]--;
		isCap[cap[i]] = true;
	}
	
	for (i = 0; i < n; i++)
	{
		if (!isCap[i])
		{
			total += c[i];
		}
	}
	
	ll ans = 0;
	for (i = 0; i < n; i++)
	{
		j = (i + 1) % n;
		ans += c[i] * c[j];
	}
	
	ll sum = 0;
	ll tmp;
	for (i = 0; i < k; i++)
	{
		tmp = total + sum;
		
		j = (cap[i] + n - 1) % n;
		if (!isCap[j] || j < cap[i])
		{
			tmp -= c[j];
		}
		
		j = (cap[i] + 1) % n;
		if (!isCap[j] || j < cap[i])
		{
			tmp -= c[j];
		}
			
		ans += c[cap[i]] * tmp;	
		sum += c[cap[i]];		
	}
	
	
	
	
	
	printf("%lld\n", ans);
	return 0;
}