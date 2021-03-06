#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"
//#define LLD "%I64d"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;
const int N = 55;
const int MAX = 1e9;

int d[N][N];
pii srt[N][N];
ll dp[N][N][N];
ll ans;

int main()
{
	int g1, g2, s1, s2, n, m, i, u, v, j, k, c;
	scanf("%d%d", &n, &m);
	
	fill((int*)d, (int*)d + N*N, MAX);
	for (i = 0; i < n; i++)
	{
		d[i][i] = 0;
	}
	
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		u--;
		v--;
		d[u][v] = d[v][u] = c;
	}
	scanf("%d%d%d%d", &g1, &g2, &s1, &s2);
	
	
	// floyd
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{

				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				
			}
		}
	}
	
	int pos = 0;
	for (i = 0; i < n; i++)
	{
		pos = 0;
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			srt[i][pos++] = mp(d[i][j], i);
		}
		pii *pDist = srt[i];
		sort(pDist, pDist + n - 1);
	}
	
	int lastGold, firstBronze, goldNum, silverNum;
	pii line1, line2;
	pii *p, *tmp;
	bool bGold, bSilver, bBronze;
	for (lastGold = 0; lastGold < n; lastGold++)
	{
		for (firstBronze = 0; firstBronze < n; firstBronze++)
		{
			line1 = srt[lastGold][0];
			line2 = srt[firstBronze][n - 2];
			if (lastGold == firstBronze || line1 >= line2)
			{
				continue;
			}
			memset(dp, 0, sizeof(dp));
			dp[0][0][0] = 1;
			for (i = 0; i < n; i++)
			{
				bGold = bSilver = bBronze = false;
				if (i == lastGold)
				{
					bGold = true;
				}
				else if (i == firstBronze)
				{
					bBronze = true;
				}
				else
				{
					bGold = srt[i][0] < line1;
					bBronze = srt[i][n - 2] > line2;
					tmp = srt[i];
					p = upper_bound(tmp, tmp + n - 1, line1);
					if (p < tmp + n - 1 && *p < line2)
					{
						bSilver = true;
					}
				}
				
				for (goldNum = 0; goldNum < n; goldNum++)
				{
					for (silverNum = 0; silverNum + goldNum <= i; silverNum++)
					{
						ll tmp = dp[i][goldNum][silverNum];
						if (bGold)
						{
							dp[i + 1][goldNum + 1][silverNum] += tmp;
						}
						if (bSilver)
						{
							dp[i + 1][goldNum][silverNum + 1] += tmp;
						}
						if (bBronze)
						{
							dp[i + 1][goldNum][silverNum] += tmp;
						}
					}
				}
			}
			
			for (goldNum = g1; goldNum <= g2; goldNum++)
			{
				for (silverNum = s1; silverNum <= s2; silverNum++)
				{
					ans += dp[n][goldNum][silverNum];
				}
			}
		}
	}
	
	printf(LLD "\n", ans);
	return 0;
}