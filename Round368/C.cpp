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
	ll n, m, k, i, j;
	scanf("%lld", &n);
	
	if (n == 1 || n == 2)
	{
		printf("-1\n");
		return 0;
	}
	
	if (n % 2)
	{
		m = (n*n + 1) / 2;
		k = (n*n - 1) / 2;
	}
	else
	{
		n /= 2;
		m = n*n + 1;
		k = n*n - 1;
	}
	
	printf("%lld %lld\n", k, m);
	return 0;
}


/*
(c-b)(c+b)=a*a=x*y
c-b = a*a
c+b = 1
c = (a*a + 1)/2
b = (a*a - 1)/2
2*a*2*a
2*a*a-2

*/