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

const ll MOD = 1e6 + 3;

ll mypow(ll a, ll b, ll M = MOD)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = res * a % M;
		}
		
		a = a * a % M;
		b >>= 1;
	}
	
	return res;
}

int bitCount(ll a)
{
	int res = 0;
	for (int i = 0; i <= 62; i++)
	{
		if ((a >> i) & 1)
		{
			res++;
		}
	}
	
	return res;
}

int main()
{
	ll n, k, A, B, revGcd;
	
	scanf("%lld%lld", &n, &k);
	
	if (n <= 62 && (1LL << n) < k)
	{
		printf("1 1\n");
		return 0;
	}
	
	B = mypow(2, n);
	B = mypow(B, k);
	ll exp = mypow(2, n);
	
	if (k >= MOD)
	{
		A = 0;
	}
	else
	{
		A = 1;
		
		for (ll i = 1; i <= k; i++)
		{
			A = A * (exp - i + 1 + MOD) % MOD;
		}
	}
	
	const ll MOD2 = MOD - 1;
	exp = mypow(2, n, MOD2);
	
	revGcd = (exp - 1 + MOD2) % MOD2;
	//revGcd = mypow(revGcd, MOD - 2);
	ll tmp = ((exp - k) % MOD2 + MOD2) % MOD2;
	if (n >= 63)
	{
		tmp = (tmp - (bitCount(-k) + n - 1 - 63 + 1) + MOD2) % MOD2;
	}
	else
	{
		tmp = (tmp - bitCount((1LL << n) - k) + MOD2) % MOD2;
	}
	
	revGcd = (revGcd - tmp + MOD2) % MOD2;
	revGcd = (-revGcd + MOD2) % MOD2;
	revGcd = mypow(2, revGcd);
	A = A * revGcd % MOD;
	B = B * revGcd % MOD;
	A = (B - A + MOD) % MOD;
	
	
	printf("%lld %lld\n", A, B);
	return 0;
}

/*
(2^n)*(2^n-1)*...*(2^n - k + 1)
(2^n)^k

n! = 2^m, m = (n - bitsum(n)) / 1 //Legendre's formula
gcd = 
*/