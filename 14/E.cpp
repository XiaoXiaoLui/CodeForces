#include <iostream>

using namespace std;

typedef long long ll;

ll dp[22][12][12][5][2];

int main()
{
	int n, t, t1, t2, i, j, k, l;
	
	cin >> n >> t;
	
	for (k = 1; k <= 4; k++)
	{
		dp[n - 1][0][1][k][0] = 4 - k;
		dp[n - 1][1][0][k][1] = k - 1;
		dp[n - 1][0][0][k][0] = k - 1;
		dp[n - 1][0][0][k][1] = 4 - k;
	}
	
	for (i = n - 2; i >= 2; i--)
	{
		for (t1 = 0; t1 <= t; t1++)
		{
			for (t2 = 0; t2 <= t; t2++)
			{
				if (t1 + t2 > n - i)
				{
					continue;
				}
				for (k = 1; k <= 3; k++)
				{
					for (l = 1; l <= 4; l++)
					{						
						if (l > k)
						{
							if (t2 > 0)
							{
								dp[i][t1][t2][k][0] += dp[i + 1][t1][t2 - 1][l][1];
							}
						}
						else if (l < k)
						{
							dp[i][t1][t2][k][0] += dp[i + 1][t1][t2][l][0];
							
						}
					}
				}
				for (k = 2; k <= 4; k++)
				{
					for (l = 1; l <= 4; l++)
					{
						if (l > k)
						{
							dp[i][t1][t2][k][1] += dp[i + 1][t1][t2][l][1];
						}
						else if (l < k)
						{
							if (t1 > 0)
							{
								dp[i][t1][t2][k][1] += dp[i + 1][t1 - 1][t2][l][0];
							}
						}
					}
				}
			}
		}
	}
	
	ll ans = 0;
	
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (j > i)
			{
				ans += dp[2][t][t - 1][j][1];
			}
			else if (j < i)
			{
				ans += dp[2][t][t - 1][j][0];
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}