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

const int N = 1e5 + 100;
ll ans[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	ans[1] = 2;
	for (i = 2; i <= n; i++)
	{
		ll tmp = i;
		ans[i] = tmp*(tmp + 1)*(tmp + 1) - (tmp - 1);
	}
	
	for (i = 1; i <= n; i++)
	{
		printf("%lld\n", ans[i]);
	}
	
	return 0;
}

/*

k + 1 a0 + a1*1 + a2*2 + a3*3

bk = c(k+1)*c(k+1) = c^2(k^2+2k+1)
b = (k + 1)*(k + 1)*k

2 1*2 2*3 3*4 4*5 5*6 .. k*(k+1)..n*(n+1)
*/