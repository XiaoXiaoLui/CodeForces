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
ll a[N];
ll b[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (i = 1; i <= n; i++)
	{
		b[i] = a[i] + a[i + 1];
	}
	
	for (i = 1; i <= n; i++)
	{
		printf("%lld ", b[i]);
	}
	printf("\n");
	return 0;
}

/*
ak = bk - b(k+1) + ...
bk = ak + a(k + 1)
*/