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
const ll INF = 1e18;
const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;


ll fact[N];
ll invFact[N];

ll mypow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	
	return res;
}

ll comb(int n, int k)
{
	ll res;
	res = fact[n] * invFact[k] % MOD;
	res = res * invFact[n - k] % MOD;
	return res;
}

int main()
{
	int n, i, j, k, num, left, right;
	ll ans = 0LL;
	map<int, int> rec;
	scanf("%d%d", &n, &num);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &left, &right);
		rec[left]++;
		rec[right + 1]--;
	}
	
	fact[0] = invFact[0] = 1;
	for (i = 1; i <= n; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		invFact[i] = mypow(fact[i], MOD - 2);
	}
	
	map<int, int>::iterator iter;
	int pointCount;
	int last = rec.begin()->first;
	int sum = 0;
	for (iter = rec.begin(); iter != rec.end(); iter++)
	{
		pointCount = iter->first - last;
		if (sum >= num)
		{
			ans = (ans + pointCount * comb(sum, num)) % MOD;
		}
		sum += iter->second;
		last = iter->first;
	}
	
	printf(LLD"\n", ans);
	return 0;
}