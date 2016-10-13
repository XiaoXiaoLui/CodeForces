#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 23;
const int LOOP = 1000;
const double ERROR = 1e-11;

double f[N][N];
double p[N];
double g[N][N];
double sum[N][N];
double ans[N];

int main()
{
	int n, k, i, j, l, nozeroCount = 0;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%lf", &p[i]);
		if (p[i] > ERROR)
		{
			nozeroCount++;
		}
	}
	k = min(k, nozeroCount);
	
	fill((double*)f, (double*)f + N*N, 0.0);
	for (i = 1; i <= n; i++)
	{
		for (l = 1; l <= n; l++)
		{
			f[i][l] = 1.0 / n;
			//f[i][l] = 0.0;
		}
	}
	
	for (int loop = 0; loop < LOOP; loop++)
	{
		fill((double*)g, (double*)g + N*N, 0.0);
		fill((double*)sum, (double*)sum + N*N, 0.0);
		for (i = 1; i <= n; i++)
		{
			for (l = 1; l <= n; l++)
			{
				sum[i][l] = sum[i][l - 1] + f[i][l];
			}
		}
		
		for (l = 1; l <= n; l++)
		{
			if (l == 1)
			{
				for (i = 1; i <= n; i++)
				{
					g[i][l] = p[i];
				}
			}
			else
			{
				for (i = 1; i <= n; i++)
				{
					for (j = 1; j <= n; j++)
					{
						if (i == j)
						{
							continue;
						}
						
						if (fabs(sum[j][n] - f[j][l]) > ERROR)
						{
							g[i][l] += f[i][l] * p[j] * (sum[j][l - 1] / (sum[j][n] - f[j][l]));
						}
			
						
						if (fabs(sum[j][n] - f[j][l - 1]) > ERROR)
						{
							g[i][l] += f[i][l - 1] * p[j] * ((sum[j][n] - sum[j][l - 1]) / (sum[j][n] - f[j][l - 1]));
						}

					}
				}
			}
		}
		
		for (i = 1; i <= n; i++)
		{
			for (l = 1; l <= n; l++)
			{
				f[i][l] = g[i][l];
			}
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		for (l = 1; l <= k; l++)
		{
			ans[i] += f[i][l];
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		printf("%.9lf ", ans[i]);
	}
	printf("\n");
	return 0;
}