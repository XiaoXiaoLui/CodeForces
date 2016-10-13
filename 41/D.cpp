#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;
const int K = 15;
const int EMPTY = -2;
int a[N][N];
int dp[N][N][K];
int dir[N][N][K];


int main()
{
	int n, m, mod, i, j, k;
	char ch;
	scanf("%d%d%d", &n, &m, &mod);
	mod++;
	
	while (getchar() != '\n');
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &ch);
			a[i][j] = ch - '0';
		}
		while (getchar() != '\n');
	}
	
	fill((int*)dp, (int*)dp + N*N*K, EMPTY);
	for (j = 1; j <= m; j++)
	{
		dp[0][j][0] = 0;
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			for (k = 0; k < mod; k++)
			{
				if (dp[i][j][k] == EMPTY)
				{
					continue;
				}
				
				if (j != 1 && dp[i][j][k] + a[i + 1][j - 1] > dp[i + 1][j - 1][(k + a[i + 1][j - 1]) % mod])
				{
					dp[i + 1][j - 1][(k + a[i + 1][j - 1]) % mod] = dp[i][j][k] + a[i + 1][j - 1];
					dir[i + 1][j - 1][(k + a[i + 1][j - 1]) % mod] = 1;
				}
				
				if (j != m && dp[i][j][k] + a[i + 1][j + 1] > dp[i + 1][j + 1][(k + a[i + 1][j + 1]) % mod])
				{
					dp[i + 1][j + 1][(k + a[i + 1][j + 1]) % mod] = dp[i][j][k] + a[i + 1][j + 1];
					dir[i + 1][j + 1][(k + a[i + 1][j + 1]) % mod] = 0;
				}
			}
		}
	}
	
	int maxPeas = -5;
	int bestCol;
	for (j = 1; j <= m; j++)
	{
		if (dp[n][j][0] > maxPeas)
		{
			maxPeas = dp[n][j][0];
			bestCol = j;
		}
	}
	
	if (maxPeas == EMPTY)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n%d\n", maxPeas, bestCol);
		j = bestCol;
		k = 0;
		for (i = n; i > 1; i--)
		{
			if (dir[i][j][k])
			{
				printf("R");
				k = (k - a[i][j] + 100 * mod) % mod;
				j++;
			}
			else
			{
				printf("L");
				k = (k - a[i][j] + 100 * mod) % mod;
				j--;
			}
		}
		
	}
	
	return 0;
}