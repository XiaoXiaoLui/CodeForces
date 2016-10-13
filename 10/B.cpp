#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int f[101][101][2];
int g[101];
int h[101][2];
int n, k;


int find(int m, int &left)
{
	if (g[m] == -1)
	{
		return -1;
	}
	
	int i, j, minSum, minRow;
	
	minRow = -1;
	minSum = INT_MAX;
	for (i = 1; i <= k; i++)
	{
		if (f[i][m][1] < minSum)
		{
			minSum = f[i][m][1];
			minRow = i;
		}
	}
	
	g[m] = minRow;
	if (minRow == -1)
	{
		return minRow;
	}
	
	left = f[minRow][m][0];
	
	int mid;
	mid = (k + 1) / 2;
	
	if (h[minRow][0] == 0)
	{
		h[minRow][0] = mid - m / 2;
		h[minRow][1] = h[minRow][0] + m - 1;
	}
	else
	{
		if (left < h[minRow][0])
		{
			h[minRow][0] = left;
		}
		else
		{
			h[minRow][1] = h[minRow][1] + m;
		}
	}
	
	if (mid - h[minRow][0] <= h[minRow][1] - mid)
	{
		for (i = 1; i <= h[minRow][0] - 1; i++)
		{
			f[minRow][i][0] = h[minRow][0] - i;
			f[minRow][i][1] = (2*mid - 2*h[minRow][0] + i + 1) * i / 2	+	abs(minRow - mid) * i;
		}
		/*
		for (; i <= k - h[minRow][1]; i++)
		{
			f[minRow][i][0] = h[minRow][1] + 1;
			f[minRow][i][1] = (2*h[minRow][1] - 2*mid + i + 1) * i / 2	+	abs(minRow - mid) * i;
		}*/
		for (; i <= k; i++)
		{
			f[minRow][i][0] = 0;
			f[minRow][i][1] = INT_MAX;
		}
	}
	else
	{
		for (i = 1; i <= k - h[minRow][1]; i++)
		{
			f[minRow][i][0] = h[minRow][1] + 1;
			f[minRow][i][1] = (2*h[minRow][1] - 2*mid + i + 1) * i / 2	+	abs(minRow - mid) * i;
		}
		/*
		for (; i <= h[minRow][0] - 1; i++)
		{
			f[minRow][i][0] = h[minRow][0] - i;
			f[minRow][i][1] = (2*mid - 2*h[minRow][0] + i + 1) * i / 2	+	abs(minRow - mid) * i;
		}*/
		for (; i <= k; i++)
		{
			f[minRow][i][0] = 0;
			f[minRow][i][1] = INT_MAX;
		}
	}
	
	
	
	return minRow;
}

int main()
{
	int i, j, m, l, x, y, row;
	
	cin >> n >> k;
	x = y = (k + 1) / 2;
	
	
	
	// init f
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= k; j++)
		{
			f[i][j][0] = x - j / 2;
			if (j % 2)
			{
				f[i][j][1] = abs(i - y) * j + (j / 2)*(j / 2 + 1);
			}
			else
			{
				f[i][j][1] = abs(i - y) * j + (j / 2)*(j / 2);
			}
		}
	}
	
	
	
	for (i = 1; i <= n; i++)
	{
		cin >> m;
		
		row = find(m, l);
		
		if (row == -1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << row << " " << l << " " << l + m - 1 << endl;
		}
	}
	
	
	return 0;
}