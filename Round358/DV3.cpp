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
int f[N][N][12];
int l[N][N];
pair<int, int> route[N][N][12];


int main()
{
	int k, i, j, num, len;
	scanf("%d%d%d", &n, &m, &num);
	scanf("%s%s", s1, s2);
	
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (l[i][j])
			{
				continue;
			}
			for (len = 0; len < min(n - i, m - j) && s1[i + len] == s2[j + len]; len++);
			l[i][j] = len;
			for (k = 1; k < len; k++)
			{
				l[i + k][j + k] = len - k;
			}
		}
	}

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			for (k = 1; k <= num; k++)
			{
				if (l[i][j])
				{
					if (l[i][j] + f[i][j][k - 1] > f[i + l[i][j]][j + l[i][j]][k])
					{
						f[i + l[i][j]][j + l[i][j]][k] = l[i][j] + f[i][j][k - 1];
						route[i + l[i][j]][j + l[i][j]][k] = mp(i, j);
					}
				}
				if (i > 0 && f[i - 1][j][k] > f[i][j][k])
				{
					f[i][j][k] = f[i - 1][j][k];
					route[i][j][k] = mp(i - 1, j);
				}
				if (j > 0 && f[i][j - 1][k] > f[i][j][k])
				{
					f[i][j][k] = f[i][j - 1][k];
					route[i][j][k] = mp(i, j - 1);
				}
				//f[i][j][k] = max(f[i][j][k], f[i + 1][j][k]);
				//f[i][j][k] = max(f[i][j][k], f[i][j + 1][k]);
			}
		}
	}
	
	printf("%d\n", f[n][m][num]);
	return 0;
}