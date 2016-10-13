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

/*
a ka k^2a k^3a
n / 2^3 + n / 3^3 +.. n / 
4949100894494448

*/

const int N = 8e5 + 5;
ll c[N];

int main()
{
	ll m;
	int i;
	scanf(LLD, &m);
	for (i = 1; i < N; i++)
	{
		c[i] = (ll)i * i * i;
	}
	
	ll left, right, mid;
	ll count;
	left = 8;
	right = (ll)N*N*N;
	while (right - left > 1)
	{
		mid = (left + right) / 2;
		for (i = 2, count = 0LL; c[i] <= mid; i++)
		{
			count += mid / c[i];
		}
		if (count < m)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	
	ll ans;
	bool ok = false;
	for (i = 2, count = 0LL; c[i] <= left; i++)
	{
		count += left / c[i];
	}
	if (count == m)
	{
		ok = true;
		ans = left;
	}
	
	if (!ok)
	{
		for (i = 2, count = 0LL; c[i] <= right; i++)
		{
			count += right / c[i];
		}
		if (count == m)
		{
			ans = right;
			ok = true;
		}
	}
	
	if (ok)
	{
		printf(LLD "\n", ans);
	}
	else
	{
		printf("-1\n");
	}

	return 0;
}