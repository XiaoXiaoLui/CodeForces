#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

int t[105];

int main()
{
	int n, a, i, j, d;
	
	scanf("%d%d", &n, &a);
	a--;
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
	}
	
	int ans = t[a];
	for (d = 1; d < n; d++)
	{
		if (a - d >= 0 && a + d < n)
		{
			if (t[a - d] && t[a + d])
			{
				ans += 2;
			}
		}
		else if (a - d >= 0)
		{
			if (t[a - d])
			{
				ans++;
			}
		}
		else if (a + d < n)
		{
			if (t[a + d])
			{
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}