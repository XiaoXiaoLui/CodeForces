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

const int N = 1e6 + 100;
const ll MOD = 1e9 + 7;
const int BASE1 = 1266113;
const int BASE2 = 1260713;

ll ha1[N];
ll ha2[N];
int cnt[N];
ll fact[N];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int n, m, i, num, type;
	scanf("%d%d", &n, &m);
	
	ll exp1 = 1;
	ll exp2 = 1;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		while (num--)
		{
			scanf("%d", &type);
			ha1[type] = (ha1[type] +  exp1) % MOD;
			ha2[type] = (ha2[type] +  exp2) % MOD;
		}
		exp1 = exp1 * BASE1 % MOD;
		exp2 = exp2 * BASE2 % MOD;
	}
	
	map<pair<ll, ll>, int> cntMap;
	for (i = 1; i <= m; i++)
	{
		cntMap[mp(ha1[i], ha2[i])]++;
	}
	
	fact[0] = 1;
	for (i = 1; i <= m; i++)
	{
		fact[i] = i * fact[i - 1] % MOD;
	}
	
	ll ans = 1;
	for (auto &tmp : cntMap)
	{
		int curNum = tmp.second;
		ans = (ans * fact[curNum]) % MOD;
	}
	
	printf("%lld\n", ans);
	return 0;
}