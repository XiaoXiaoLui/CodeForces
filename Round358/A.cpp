#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

long long ans;
int main()
{
	int m, n;
	scanf("%d%d", &n, &m);
	
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = 5 - (i % 5);
		if (j <= m)
		{
			ans += (m - j) / 5 + 1;
		}
	}
	
	printf("%I64d\n", ans);
	return 0;
}
/*
j 1
m 1 2 3 4 5 6 7 8 9 10 11
  1 1 1 1 1 2 2 2 2 2   3
*/