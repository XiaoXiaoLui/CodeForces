#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 505;

int dp[N][N];
int a[N];

vector<int> ans;

int main()
{
	int n, K, i, j, k;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	dp[0][0] = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = K; j >= 0; j--)
		{
			for (k = j; k >= 0; k--)
			{
				dp[j][k] |= dp[j][k];
				if (a[i] <= j)
				{
					dp[j][k] |= dp[j - a[i]][k];
					if (a[i] <= k)
					{
						dp[j][k] |= dp[j - a[i]][k - a[i]];
					}
				}
			}
		}
	}
	
	for (i = 0; i <= K; i++)
	{
		if (dp[K][i])
		{
			ans.push_back(i);
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size();i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}