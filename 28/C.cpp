#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 55;
double f[N][N][N];
double s[N];
int a[N];

int main()
{
	int n, m, i, j, k, l;
	double sum1 = 0;
	double sum2 = 0;
	double ans;
	scanf("%d%d", &n, &m);
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
	}
	
	s[0] = 1;
	for (i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] * i;
	}
	
	f[0][0][0] = 1;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			for (k = 0; k <= n; k++)
			{
				for (l = j; l <= n; l++)
				{
					f[i + 1][l][max(k, (l - j + a[i + 1] - 1) / a[i + 1])] += s[l] / s[l - j] / s[j] * f[i][j][k];
				}
			}
		}
	}
	
	for (k = 1; k <= n; k++)
	{
		sum1 += k * f[m][n][k];
		sum2 += f[m][n][k];
	}
	ans = sum1 / sum2;
	printf("%.12lf\n", ans);
	
	return 0;
}