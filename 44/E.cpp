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

const int N = 205;
char s[N];
int dp[N][N];
int main()
{
	int n, lineNum, i, j, k, a, b;
	scanf("%d%d%d", &lineNum, &a, &b);
	scanf("%s", s);
	
	n = strlen(s);
	fill((int*)dp, (int*)dp + N*N, -1);
	
	dp[0][0] = 0;
	for (i = a; i <= n; i++)
	{
		for (j = 1; j <= lineNum; j++)
		{
			for (k = a; k <= b && k <= i; k++)
			{
				if (dp[i - k][j - 1] != -1)
				{
					dp[i][j] = k;
					break;
				}
			}
		}
	}
	
	if (dp[n][lineNum] != -1)
	{
		string tmp;
		int curIndex = 0;
		for (i = lineNum; i > 0; i--)
		{
			tmp.assign(s + curIndex, dp[n - curIndex][i]);
			printf("%s\n", tmp.c_str());
			curIndex += dp[n - curIndex][i];
		}
	}
	else
	{
		printf("No solution\n");
	}
	
	printf("\n");
	return 0;
}