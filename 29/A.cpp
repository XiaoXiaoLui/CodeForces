#include <cstdio>

const int N = 105;
int x[N];
int d[N];

int main()
{
	int n, i, j, pos;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &d[i]);
	}
	
	bool ok = true;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i])
			{
				ok = false;
			}
		}
	}
	
	if (ok)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	
	return 0;
}