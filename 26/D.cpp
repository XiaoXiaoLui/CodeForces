#include <cstdio>


int main()
{
	int n, m, k;
	double ans = 0;
	
	scanf("%d%d%d", &n, &m, &k);
	if (k >= m)
	{
		ans = 1.0;
	}
	else if (n + k < m)
	{
		ans = 0.0;
	}
	else
	{
		ans = 1.0;
		double c = 1.0;
		for (int i = 0; i <= k; i++)
		{
			c *= ((double)m - i) / (n + 1 + i);
		}
		ans -= c;
	}
	
	printf("%.6lf\n", ans);
	return 0;
}


/*
n + m  c(n + m, n) - c(n + m, n + (1 + k))/ c(n + m, n) = (n + m)!/(m!n!) - (n+m)!/(m - 1 - k)!(n+1+k)! / (n+m)!/(m!n!) = 1 - m!n!/(m-1-k)!(n+1+k)! = 1 - m*(m-1)*..*(m-k)/(n+1)*(n+2)*(n+1+k)
k + n - m
-2 - k

n - m + 2 + 2k
*/