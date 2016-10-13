#include <cstdio>



int a[1005][1005];

int main()
{
	int n;
	scanf("%d", &n);
	
	int i, j;
	for (i = 0; i <= n - 2; i++)
	{
		for (j = 0; j <= n - 2; j++)
		{
			a[i][j] = (i + j) % (n - 1) + 1;
		}
	}
	
	for (i = 0; i <= n - 2; i++)
	{
		a[n - 1][i] = a[i][i];
		a[i][n - 1] = a[i][i];
		a[i][i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
