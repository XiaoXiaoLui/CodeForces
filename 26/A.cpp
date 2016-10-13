#include <cstdio>


const int N = 3005;
int prime[N];
int factors[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);

	for (i = 2; i <= 3000; i++)
	{
		prime[i] = true;
	}
	for (i = 2; i <= 3000; i++)
	{
		if (!prime[i])
		{
			continue;
		}
		for (j = i + i; j <= 3000; j += i)
		{
			prime[j] = false;
		}
	}
	
	for (i = 2; i <= 3000; i++)
	{
		if (!prime[i])
		{
			continue;
		}
		for (j = i; j <= 3000; j += i)
		{
			factors[j]++;
		}
	}
	
	int count = 0;
	
	for (i = 2; i <= n; i++)
	{
		if (factors[i] == 2)
		{
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}