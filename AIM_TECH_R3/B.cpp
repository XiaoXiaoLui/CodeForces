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

int x[N];

int main()
{
	int n, a, i, ans;
	scanf("%d%d", &n, &a);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	
	sort(x, x + n);
	
	if (n == 1)
	{
		ans = 0;
	}
	else
	{
		ans = 1e9;
		if (a <= x[0])
		{
			ans = min(ans, x[n - 2] - a);
		}
		else if (a <= x[n - 2])
		{
			ans = min(ans, 2 * (a - x[0]) + (x[n - 2] - a));
			ans = min(ans, 2 * (x[n - 2] - a) + (a - x[0]));
		}
		else
		{
			ans = min(ans, a - x[0]);
		}
		
		if (a <= x[1])
		{
			ans = min(ans, x[n - 1] - a);
		}
		else if (a <= x[n - 1])
		{
			ans = min(ans, 2 * (a - x[1]) + (x[n - 1] - a));
			ans = min(ans, 2 * (x[n - 1] - a) + (a - x[1]));
		}
		else
		{
			ans = min(ans, a - x[1]);
		}
	}
	
	printf("%d\n", ans);
	return 0;
}