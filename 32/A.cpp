#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int h[1005];
int main()
{
	int n, d, i, j;
	int ans = 0;
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &h[i]);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (abs(h[i] - h[j]) <= d)
			{
				ans++;
			}
		}
	}
	
	
	printf("%d\n", ans);
	return 0;
}