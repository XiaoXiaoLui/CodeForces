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



int main()
{
	ll t, s, x;
	bool ok = false;
	scanf(LLD LLD LLD, &t, &s, &x);
	
	if (x >= t && (x - t) % s == 0)
	{
		ok = true;
	}
	if (x >= s + t + 1 && (x - t - 1) % s == 0)
	{
		ok = true;
	}
	
	if (ok)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}