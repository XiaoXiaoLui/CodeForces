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

const int INF = 1e9;
const int N = 55;
const int M = 26;


char s1[N];
char s2[N];

int t[M][M];
int tr1[N][N];
int tr2[N][N];
int dp[N][N];


void construct(char *str, int tr[N][N])
{
	int n, i, j, k, a, b;
	n = strlen(str);
	
	for (i = 0; i < n; i++)
	{
		tr[i][i] = 1 << (str[i] - 'a');
	}
	
	for (i = n - 2; i >= 0; i--)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = i; k < j; k++)
			{
				for (a = 0; a < M; a++)
				{
					if ((tr[i][k] >> a) & 1)
					{
						for (b = 0; b < M; b++)
						{
							if ((tr[k + 1][j] >> b) & 1)
							{
								tr[i][j] |= t[a][b];
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	int n, i, j, pi, pj, len1, len2;
	scanf("%s%s", s1, s2);
	
	char tmp[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", tmp);
		t[tmp[3] - 'a'][tmp[4] - 'a'] |= 1 << (tmp[0] - 'a');
	}
	
	construct(s1, tr1);
	construct(s2, tr2);
	
	len1 = strlen(s1);
	len2 = strlen(s2);
	fill((int*)dp, (int*)dp + N*N, INF);
	dp[0][0] = 0;
	for (i = 1; i <= len1; i++)
	{
		for (j = 1; j <= len2; j++)
		{
			for (pi = 0; pi < i; pi++)
			{
				for (pj = 0; pj < j; pj++)
				{
					if (tr1[pi][i - 1] & tr2[pj][j - 1])
					{
						dp[i][j] = min(dp[i][j], dp[pi][pj] + 1);
					}
				}
			}
		}
	}
	
	if (dp[len1][len2] == INF)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", dp[len1][len2]);
	}
	
	return 0;
}