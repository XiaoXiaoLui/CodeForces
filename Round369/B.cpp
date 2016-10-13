#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 600;

ll a[N][N];

int main()
{
	int n, i, j, row, col;
	ll sum;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%lld", &a[i][j]);
			if (a[i][j] == 0)
			{
				row = i;
				col = j;
			}
		}
	}
	
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	
	i = (row == 0) ? 1 : 0;
	sum = 0;
	for (j = 0; j < n; j++)
	{
		sum += a[i][j];
	}
	
	a[row][col] = sum;
	for (j = 0; j < n; j++)
	{
		if (j != col)
		{
			a[row][col] -= a[row][j];
		}
	}
	
	bool ok = true;
	
	if (a[row][col] <= 0)
	{
		ok = false;
	}
	
	ll tmp;
	
	// for row
	for (i = 0; i < n; i++)
	{
		tmp = 0;
		for (j = 0; j < n; j++)
		{
			tmp += a[i][j];
		}
		if (tmp != sum)
		{
			ok = false;
			break;
		}
	}
	
	// for col
	for (j = 0; j < n; j++)
	{
		tmp = 0;
		for (i = 0; i < n; i++)
		{
			tmp += a[i][j];
		}
		if (tmp != sum)
		{
			ok = false;
			break;
		}
	}
	
	// diagonal
	for (tmp = 0, i = 0; i < n; i++)
	{
		tmp += a[i][i];
	}
	if (tmp != sum)
	{
		ok = false;
	}
	
	for (tmp = 0, i = 0; i < n; i++)
	{
		tmp += a[i][n - i - 1];
	}
	if (tmp != sum)
	{
		ok = false;
	}
	
	if (ok)
	{
		printf("%lld\n", a[row][col]);
	}
	else
	{
		printf("-1\n");
	}
	

	return 0;
}