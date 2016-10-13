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

const int N = 2e5 + 50;

ll a[N];
ll b[N];
int sign[N];

int main()
{
	int n, k, x, i, idx;
	ll q, r;
	int p = 1;
	multiset<pair<ll, int> > S;
	fill(sign, sign + N, 1);
	scanf("%d%d%d", &n, &k, &x);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if (a[i] < 0)
		{
			p *= -1;
			a[i] = -a[i];
			sign[i] = -1;
		}
		S.insert(make_pair<ll, int>(a[i], i));
	}
	
	multiset<pair<ll, int> >::iterator iter;
	if (p == 1)
	{
		iter = S.begin();
		idx = iter->second;
		S.erase(iter);
		q = a[idx] / x;
		r = a[idx] % x;
		if (r)
		{
			q++;
		}
		if (q > k)
		{
			a[idx] -= k * x;
			goto END;
		}
		a[idx] -= q * x;
		a[idx] = -a[idx];
		sign[idx] *= -1;
		k -= q;
		S.insert(make_pair<ll, int>(a[idx], idx));
	}
	
	// now product <= 0
	while (k)
	{
		iter = S.begin();
		idx = iter->second;
		S.erase(iter);
		a[idx] += x;
		k--;
		
		S.insert(make_pair<ll, int>(a[idx], idx));
	}

END:
	for (i = 1; i <= n; i++)
	{
		b[i] = a[i] * sign[i];
	}
	
	for (i = 1; i <= n; i++)
	{
		printf("%lld ", b[i]);
	}
	
	printf("\n");
	return 0;
}