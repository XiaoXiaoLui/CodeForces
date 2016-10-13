#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;


const int N = 55;
char s[N];
int dp[N][20];

int main()
{
	int n, i, j, k, digit, sum, d1, d2;
	ll ans;
	scanf("%s", s);
	n = strlen(s);
	
	for (j = 0; j <= 9; j++)
	{
		dp[n - 1][j] = 1;
	}
	
	for (i = n - 2; i >= 0; i--)
	{
		digit = s[i + 1] - '0';
		for (j = 0; j <= 9; j++)
		{
			sum = digit + j;
			if (sum & 1)
			{
				dp[i][j] = dp[i + 1][sum / 2] + dp[i + 1][sum / 2 + 1]; 
			}
			else
			{
				dp[i][j] = dp[i + 1][sum / 2];
			}
		}
	}
	
	ans = 0;
	for (j = 0; j <= 9; j++)
	{
		ans += dp[0][j];
	}
	
	// except her own number
	bool ok = true;
	for (i = 0; i <= n - 2; i++)
	{
		d1 = s[i] - '0';
		d2 = s[i + 1] - '0';
		sum = d1 + d2;
		
		if (sum & 1)
		{
			if (sum / 2 != d2 && sum / 2 + 1 != d2)
			{
				ok = false;
				break;
			}
		}
		else
		{
			if (sum / 2 != d2)
			{
				ok = false;
				break;
			}
		}
	}
	
	if (ok)
	{
		ans--;
	}
	
	printf(LLD"\n", ans);
	return 0;
}