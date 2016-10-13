#include <cstdio>

using namespace std;

const int N = 1005;


int m;
int n;
double a[N];
double b[N];
double c[N];
double d[N];
double dp[N][N];

void init()
{
	int i;
	for (i = 2; i <= m; i++)
	{
		a[i] = -1.0;
	}
	
	b[1] = 2.0;
	for (i = 2; i <= m - 1; i++)
	{
		b[i] = 3.0;
	}
	b[m] = 2.0;
	
	for (i = 1; i <= m - 1; i++)
	{
		c[i] = -1.0;
	}
	
	c[1] = c[1] / b[1];
	
	for (i = 2; i <= m - 1; i++)
	{
		c[i] = c[i] / (b[i] - a[i]*c[i - 1]);
	}

}

void calRow(int r)
{
	int i;
	
	d[1] = dp[r + 1][1] + 3;
	for (i = 2; i <= m - 1; i++)
	{
		d[i] = dp[r + 1][i] + 4;
	}
	d[m] = dp[r + 1][m] + 3;
	
	d[1] = d[1] / b[1];
	for (i = 2; i <= m; i++)
	{
		d[i] = (d[i] - a[i]*d[i - 1]) / (b[i] - a[i]*c[i - 1]);
	}
	
	
	dp[r][m] = d[m];
	for (i = m - 1; i >= 1; i--)
	{
		dp[r][i] = d[i] - c[i]*dp[r][i + 1];
	}
	
}


int main()
{
	int row, col, i;
	double ans;
	scanf("%d%d%d%d", &n, &m, &row, &col);
	init();
	
	if (m == 1)
	{
		ans = (n - row) * 2;
	}
	else
	{
		for (i = n - 1; i >= row; i--)
		{
				calRow(i);
		}
		ans = dp[row][col];
	}
	
	
	printf("%.6lf\n", ans);
	
	return 0;
}


/*
E1 = 1/3d1 + 1/3E1 + 1/3(1+E2)
Ej = 1/4d2 + 1/4Ej + 1/4Ej-1 + 1/4Ej+1
En = 1/3dn + 1/3En + 1/3(1+En-1)

2E1 - E2 = d1 + 3
-Ej-1 + 3Ej - Ej+1 = d2 + 4
-En-1 + 2En = dn + 3


a2~an = -1, -1, ..., -1
b1~bn = 2, 3, 3, 3, ..., 3, 2
c1~cn-1 = -1, -1, -1...,-1

E1

*/










