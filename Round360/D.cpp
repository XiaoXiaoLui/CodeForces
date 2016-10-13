#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

inline ll gcd(ll a, ll b)
{
	ll c;
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	
	return a;
}

inline ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}

const int N = 1e6 + 10;
ll a[N];

int main()
{
	int n, k, i;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf(LLD, &a[i]);
	}
	
	ll cur = 1;

	for (i = 0; i < n; i++)
	{
		cur = lcm(cur, a[i]);
		cur = gcd(cur, k);
	}
	
	if (cur == k)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	printf("\n");
	return 0;
}