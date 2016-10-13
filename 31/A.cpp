#include <cstdio>


int main()
{
	int a[110];
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	bool found = false;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (j == i)
			{
				continue;
			}
			for (k = 1; k <= n; k++)
			{
				if (k == j || k == i)
				{
					continue;
				}
				if (a[i] == a[j] + a[k])
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		if (found)
		{
			break;
		}
	}
	
	if (found)
	{
		printf("%d %d %d\n", i, j, k);
	}
	else
	{
		printf("-1\n");
	}
	
	
	return 0;
}