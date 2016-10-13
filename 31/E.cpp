#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 30;



ll dp[N][N];
int a[2*N];
char route[N][N];
ll exp10[N];

int main()
{
	int n, i, j, k;
	char ch;
	scanf("%d%*c", &n);
	
	for (i = 1; i <= 2*n; i++)
	{
		scanf("%c", &ch);
		a[i] = ch - '0';
	}
	
	exp10[0] = 1;
	for (i = 1; i <= n; i++)
	{
		exp10[i] = exp10[i - 1] * 10;
	}
	
	dp[0][0] = 0;
	ll tmp1, tmp2;
	for (i = 2*n; i >= 1; i--)
	{
		for (j = 0; j <= min(n, 2*n - i + 1); j++)
		{
			k = 2*n - i + 1 - j;
			if (k > n)
			{
				continue;
			}
			tmp1 = tmp2 = 0;
			if (j > 0)
			{
				//dp[j][k] = max(dp[j][k], a[i] * exp10[j - 1] + dp[j - 1][k]);
				tmp1 = a[i] * exp10[j - 1] + dp[j - 1][k];
			}
			if (k > 0)
			{
				//dp[j][k] = max(dp[j][k], a[i] * exp10[j - 1] + dp[j][k - 1]);
				tmp2 = a[i] * exp10[k - 1] + dp[j][k - 1];
			}
			if (tmp1 > tmp2 || k == 0)
			{
				dp[j][k] = tmp1;
				route[j][k] = 'M';
			}
			else
			{
				dp[j][k] = tmp2;
				route[j][k] = 'H';
			}
		}
	}
	
	for (j = n, k = n; j > 0 || k > 0;)
	{
		printf("%c", route[j][k]);
		if (route[j][k] == 'M')
		{
			j--;
		}
		else
		{
			k--;
		}
	}
	printf("\n");
	
	
}