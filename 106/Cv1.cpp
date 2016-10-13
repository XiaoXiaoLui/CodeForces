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

const int N = 1005;
const int M = 12;

int a[M];
int b[M];
int c[M];
int d[M];
int dp[M][N];

int main()
{
	int n, m, i, j, k, num, cont1, cont2;
	scanf("%d%d%d%d", &n, &m, &c[0], &d[0]);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	}
	
	for (i = 0; i <= n; i++)
	{
		num = i / c[0];
		dp[0][i] = num * d[0];
	}
	
	for (i = 1; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			for (k = 0; k <= j; k++)
			{
				num = min(k / c[i], a[i] / b[i]);
				cont1 = num * d[i];
				cont2 = dp[i - 1][j - k];
				dp[i][j] = max(dp[i][j], cont1 + cont2);
			}
		}
	}
	
	printf("%d\n", dp[m][n]);
	return 0;
}