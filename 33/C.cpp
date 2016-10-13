#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main()
{
	int n, i, j, sum, best, cur;
	
	scanf("%d", &n);
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += -a[i];
	}
	
	best = 0;
	for (cur = 0, i = 1; i <= n; i++)
	{
		if (cur > 0)
		{
			cur += a[i];
		}
		else
		{
			cur = a[i];
		}
		best = max(best, cur);
	}
	
	int ans = sum + 2 * best;
	printf("%d\n", ans);
	return 0;
}