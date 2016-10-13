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
	int n, a, i;
	ll ans = 0LL;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		ans += (ll)i * (a - 1);
	}
	
	ans += n;
	
	
	printf(LLD"\n", ans);
	return 0;
}