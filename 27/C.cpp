#include <cstdio>

int a[100005];
int main()
{
	int n, index[3];
	scanf("%d", &n);
	
	bool bFind = false;
	
	int i;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 2; i <= n && a[i] == a[i - 1]; i++);

	
	if (i > n)
	{
	}
	else if (a[i] > a[i - 1])
	{
		for (i++; i <= n && a[i] >= a[i - 1]; i++);

		if (i <= n)
		{
			bFind = true;
			index[2] = i;
			index[1] = i - 1;
			for (i -= 2; i >= 1 && a[i] == a[i + 1]; i--);
			
			index[0] = i;
		}
	}
	else
	{
		for (i++; i <= n && a[i] <= a[i - 1]; i++);
		
		if (i <= n)
		{
			bFind = true;
			index[2] = i;
			index[1] = i - 1;
			for (i -= 2; i >= 1 && a[i] == a[i + 1]; i--);
			index[0] = i;
		}
	}
	
	if (bFind)
	{
		printf("3\n");
		printf("%d %d %d\n", index[0], index[1], index[2]);
	}
	else
	{
		printf("0\n");
	}
	
	return 0;
}