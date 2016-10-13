#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int N = 505;
const int M = 26;


int dp2[N][M][M];
int min2[N][M][M][3];
int ans2[N][2];

char a[N][N];

int main()
{
	int n, m, c, i, j, c1, c2, c3, c4, c5, bestc1, bestc2, best;
	cin >> n >> m;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	memset(min2, -1, sizeof(min2));
	
	

	for (c1 = 0; c1 < M; c1++)
	{
		for (c2 = 0; c2 < M; c2++)
		{
			if (c1 == c2)
			{
				continue;
			}
			for (j = 0; j < m; j++)
			{
				c3 = (j % 2) ? c2 : c1;
				
				if (a[0][j] - 'a' != c3)
				{
					dp2[0][c1][c2]++;
				}
			}		
		}
	}
	
	for (c1 = 0; c1 < M; c1++)
	{
		for (c2 = 0; c2 < M; c2++)
		{
			if (c1 == c2)
			{
				continue;
			}
			
			for (c3 = 0; c3 < M; c3++)
			{
				for (c4 = 0; c4 < M; c4++)
				{
					if (c3 != c4 && c3 != c1 && c4 != c2 && (min2[0][c1][c2][0] == -1 || min2[0][c1][c2][0] > dp2[0][c3][c4]))
					{
						min2[0][c1][c2][0] = dp2[0][c3][c4];
						min2[0][c1][c2][1] = c3;
						min2[0][c1][c2][2] = c4;
					}
				}
			}
		}
	}
	
	for (i = 1; i < n; i++)
	{
		for (c1 = 0; c1 < M; c1++)
		{
			for (c2 = 0; c2 < M; c2++)
			{
				if (c1 == c2)
				{
					continue;
				}
				dp2[i][c1][c2] = min2[i - 1][c1][c2][0];
				for (j = 0; j < m; j++)
				{
					c3 = (j % 2) ? c2 : c1;
					dp2[i][c1][c2] += (a[i][j] - 'a') != c3;
				}
			}
		}
		
		for (c1 = 0; c1 < M; c1++)
		{
			for (c2 = 0; c2 < M; c2++)
			{
				if (c1 == c2)
				{
					continue;
				}
				
				for (c3 = 0; c3 < M; c3++)
				{
					for (c4 = 0; c4 < M; c4++)
					{
					if (c3 != c4 && c3 != c1 && c4 != c2 && (min2[i][c1][c2][0] == -1 || min2[i][c1][c2][0] > dp2[i][c3][c4]))
					{
						min2[i][c1][c2][0] = dp2[i][c3][c4];
						min2[i][c1][c2][1] = c3;
						min2[i][c1][c2][2] = c4;
					}
					}
				}
			}
		}
	}
	
	best = INT_MAX;
	
	for (c1 = 0; c1 < M; c1++)
	{
		for (c2 = 0; c2 < M; c2++)
		{
			if (c1 == c2)
			{
				continue;
			}
			
			if (dp2[n - 1][c1][c2] < best)
			{
				best = dp2[n - 1][c1][c2];
				bestc1 = c1;
				bestc2 = c2;
			}
		}
	}
	
	ans2[n - 1][0] = bestc1;
	ans2[n - 1][1] = bestc2;
	
	for (i = n - 2; i >= 0; i--)
	{
		ans2[i][0] = min2[i][ans2[i + 1][0]][ans2[i + 1][1]][1];
		ans2[i][1] = min2[i][ans2[i + 1][0]][ans2[i + 1][1]][2];
	}
	
	cout << best << endl;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			c = (j % 2) ? ans2[i][1] : ans2[i][0];
			cout << (char)('a' + c);
		}
		cout << endl;
	}
	
	
	return 0;
}