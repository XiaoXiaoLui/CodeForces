#include <cstdio>

const int N = 2005;
int a[N];

int main()
{
	int i, j, n, b;
	scanf("%d%d", &n, &b);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	int ans = b;
	int q, r, p;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			q = b / a[i];
			r = b % a[i];
			p = a[j] * q;
			if (r + p > ans)
			{
				ans = r + p;
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}