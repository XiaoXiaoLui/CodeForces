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

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll a[N];



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



int main()
{
	int n, i;
	bool bEven = false;
	//bZero = true;
	ll p, q, tmp;
	
	scanf("%d", &n);
	
	for (tmp = 1, i = 0; i < n; i++)
	{
		scanf(LLD, &a[i]);
		if (!(a[i] & 1))
		{
			bEven = true;
		}
		//p = mypow(p, a[i]);
		tmp = (tmp * (a[i] % (MOD - 1))) % (MOD - 1);
	}
	tmp = (tmp + MOD - 1 - 1) % (MOD - 1);
	
	//p = p * mypow(2, MOD - 2) % MOD;
	p = mypow(2, tmp);
	q = p;
	if (bEven)
	{
		p = (p + 1) % MOD;
	}
	else
	{
		p = (p + MOD - 1) % MOD;
	}
	p = p * mypow(3, MOD - 2) % MOD;
	
	
	printf("%lld/%lld\n", p, q);
	return 0;
}


/*
0 1 0
1 0 1
2 1/2 1/2
3 1/4 3/4
4 3/8 5/8
5 5/16 11/16
6 11/32 21/32
a(n+1) = 1/2*(1 - an) = 1/2 - 1/2an
y = 1/2 - 1/2x
(y+k)=-1/2(x+k)
-3/2k=1/2
k = -1/3
y-1/3 = -1/2(x - 1/3) = 2/3*(-1/2)^n
an = (2/3*(-1/2)^n) + 1/3 
= 1/3* (-1)^n /2^(n-1) + 1/3
=(2^(n-1) + (-1)^n)/(3*2^(n-1))
p = (2^(n-1) + (-1)^n)/3
q = 2^(n-1)

an = 1/3*(1 - (-1/2)^(n-1)) = (2^(n-1) - (-1)^(n-1))/(3*2^(n-1))



*/