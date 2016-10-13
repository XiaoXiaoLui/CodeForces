#include <cstdio>

const int N = 105;
int d[N];


int main()
{
	int n, a, b, i;
	scanf("%d", &n);
	for (i = 1; i <= n - 1; i++)
	{
		scanf("%d", &d[i]);
	}
	
	scanf("%d%d", &a, &b);
	
	int ans = 0;
	for (i = a; i < b; i++)
	{
		ans += d[i];
	}
	printf("%d\n", ans);
	
	return 0;
}