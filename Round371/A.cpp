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



int main()
{
	ll l1, r1, l2, r2, k;
	ll a, b;
	scanf("%lld%lld%lld%lld%lld", &l1, &r1, &l2, &r2, &k);
	a = max(l1, l2);
	b = min(r1, r2);
	
	ll ans = 0;
	if (a > b)
	{
		ans = 0;
	}
	else
	{
		ans = b - a + 1;
		if (k >= a && k <= b)
		{
			ans--;
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}