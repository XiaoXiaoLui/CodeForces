#include <iostream>

using namespace std;

const int N = 30;
int a[N][N];
int r[N][N][N][N];
int p[N][N];

int main()
{
	int n, m, w, h, i, j, k, ans = 0;
	char c;
	
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	
	
	for (i = n - 1; i >= 0; i--)
	{
		for (j = m - 1; j >= 0; j--)
		{
			for (h = 1; i + h - 1 < n && !a[i + h - 1][j]; h++)
			{
				for (w = 1; j + w - 1 < m && !a[i][j + w - 1]; w++)
				{
					if (h == 1 || w == 1)
					{
						r[i][j][h][w] = 1;
					}
					else
					{
						r[i][j][h][w] = r[i + 1][j + 1][h - 1][w - 1];
					}
					if (r[i][j][h][w] && 2 * (h + w) > ans)
					{
						ans = 2 * (h + w);
					}
				}
			}
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}