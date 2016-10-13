#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LLD "%I64d"
//#define LLD "%l" "ld"

typedef long long ll;
const int N = 1005;
const ll MAX = 2e18;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int dp[11][N][N];

int n;
ll ans;

ll solve(int i, int r, int pre)
{
	if (dp[i][r][pre] != 0)
	{
		return dp[i][r][pre];
	}
	if (r == 1)
	{
		dp[i][r][pre] = 1;
		return 1;
	}
	
	int k;
	int m = min(pre, r);
	ll minValue = MAX;
	ll tmp = 1;
	for (k = 2; k <= m; k++)
	{
		if (r % k)
		{
			continue;
		}
		tmp = solve(i + 1, r / k, k);
		if (tmp >= MAX)
		{
			continue;
		}
		for (int c = 0; c < k - 1; c++)
		{
			tmp *= prime[i];
			if (tmp >= MAX)
			{
				tmp = MAX;
				break;
			}
		}
		minValue = min(minValue, tmp);
	}
	dp[i][r][pre] = minValue;
	
	return minValue;
}

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	
	ans = solve(0, n, 1001);


	printf(LLD "\n", ans);
	
	return 0;
}