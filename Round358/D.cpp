#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;
#define mp make_pair<int, int>

const int N = 1005;

char s1[N];
char s2[N];

int n, m;
int f[N][N][12][2];
pair<int, int> route[N][N][12];


int main()
{
	int k, i, j, num, len;
	int ans = 0;
	scanf("%d%d%d", &n, &m, &num);
	scanf("%s%s", s1 + 1, s2 + 1);
	

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			for (k = 1; k <= num; k++)
			{
				if (s1[i] == s2[j])
				{
					f[i][j][k][0] = max(f[i - 1][j][k][0], f[i - 1][j][k][1]);
					f[i][j][k][0] = max(f[i][j][k][0], f[i][j - 1][k][0]);
					f[i][j][k][0] = max(f[i][j][k][0], f[i][j - 1][k][1]);
					
					f[i][j][k][1] = max(f[i - 1][j - 1][k][1] + 1, f[i - 1][j - 1][k - 1][0] + 1);
				}
				else
				{
					f[i][j][k][0] = max(f[i - 1][j][k][0], f[i - 1][j][k][1]);
					f[i][j][k][0] = max(f[i][j][k][0], f[i][j - 1][k][0]);
					f[i][j][k][0] = max(f[i][j][k][0], f[i][j - 1][k][1]);
				}
				//f[i][j][k] = max(f[i][j][k], f[i + 1][j][k]);
				//f[i][j][k] = max(f[i][j][k], f[i][j + 1][k]);
			}
		}
	}
	
	for (k = 1; k <= num; k++)
	{
		ans = max(ans, f[n][m][k][0]);
		ans = max(ans, f[n][m][k][1]);
	}
	
	printf("%d\n", ans);
	return 0;
}