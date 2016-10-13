#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int N = 505;
const int M = 26;

int dp1[N][M];
int dp2[N][M][M];
int min1[N][M][2];
int min2[N][M][M][3];
int ans1[N];
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
	
	memset(min1, -1, sizeof(min1));
	memset(min2, -1, sizeof(min2));
	
	
	if (m == 1)
	{
		for (c = 0; c < M; c++)
		{
			dp1[0][c] = 1;
		}
		dp1[0][a[0][0] - 'a'] = 0;
		for (c = 0; c < M; c++)
		{
			for (c2 = 0; c2 < M; c2++)
			{
				if (c2 != c && (min1[0][c][0] == -1 || min1[0][c][0] > dp1[0][c2]))
				{
					min1[0][c][0] = dp1[0][c2];
					min1[0][c][1] = c2;
				}
			}
		}
		
		for (i = 1; i < n; i++)
		{
			for (c = 0; c < M; c++)
			{
				dp1[i][c] = ((a[i][0] - 'a') != c) + min1[i - 1][c][0];
			}
			for (c = 0; c < M; c++)
			{
				for (c2 = 0; c2 < M; c2++)
				{
					if (c2 != c && (min1[i][c][0] == -1 || min1[i][c][0] > dp1[i][c2]))
					{
						min1[i][c][0] = dp1[i][c2];
						min1[i][c][1] = c2;
					}
				}
			}
		}
		
		bestc1 = 0;
		best = INT_MAX;
		for (c = 0; c < M; c++)
		{
			if (dp1[n - 1][c] < best)
			{
				best = dp1[n - 1][c];
				bestc1 = c;
			}
		}
		
		ans1[n - 1] = bestc1;
		for (i = n - 2; i >= 0; i--)
		{
			ans1[i] = min1[i][ans1[i + 1]][1];
		}
		
		cout << best << endl;
		for (i = 0; i < n; i++)
		{
			cout << char(ans1[i] + 'a') << endl;
		}
		
	}
	else
	{
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
	}
	
	return 0;
}