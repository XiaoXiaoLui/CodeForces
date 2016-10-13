#include <cstdio>

const int N = 2000;
int a[N];
int main()
{
	int n, i, b, ans1, ans2;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b);
		a[b]++;
	}
	
	ans1 = 0;
	ans2 = 0;
	for (i = 0; i <= 1000; i++)
	{
		if (a[i])
		{
			ans2++;
			if (a[i] > ans1)
			{
				ans1 = a[i];
			}
		}
	}
	
	printf("%d %d\n", ans1, ans2);
	
	return 0;
}