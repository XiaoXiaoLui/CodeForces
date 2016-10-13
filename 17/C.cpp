#include <iostream>
#include <cmath>

using namespace std;

const int N = 152;
const int M = N / 3 + 3;
const int MD = 51123987;

char str[N];
int f[N][M][M][M];
int next[N][3];

int main()
{
	int ans = 0, n, m, i, j, x, y, z, cur;
	cin >> n >> str;
	
	next[n][0] = next[n][1] = next[n][2] = n;
	for (i = n - 1; i >= 0; i--)
	{
		for (j = 0; j < 3; j++)
		{
			if (str[i] - 'a' == j)
			{
				next[i][j] = i;
			}
			else
			{
				next[i][j] = next[i + 1][j];
			}
		}
	}
	
	f[0][0][0][0] = 1;
	m = n / 3 + 2;
	for (i = 0; i < n; i++)
	{
		for (x = 0; x < m; x++)
		{
			for (y = 0; y < m; y++)
			{
				for (z = 0; z < m; z++)
				{
					cur = f[i][x][y][z];
					if (x + y + z == n && abs(x - y) <= 1 && abs(x - z) <= 1 && abs(y - z) <= 1)
					{
						ans = (ans + cur) % MD;
					}
					f[next[i][0]][x + 1][y][z] = (f[next[i][0]][x + 1][y][z] + cur) % MD;
					f[next[i][1]][x][y + 1][z] = (f[next[i][1]][x][y + 1][z] + cur) % MD;
					f[next[i][2]][x][y][z + 1] = (f[next[i][2]][x][y][z + 1] + cur) % MD;
				}
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}

