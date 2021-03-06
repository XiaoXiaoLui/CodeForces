#include <iostream>

using namespace std;

typedef long long ll;

const int N = 503;

ll rx[N], ry[N], bx[N], by[N], a[N][N];

int main()
{
	int n, m, i, j, k;
	ll ans = 0;
	
	cin >> n >> m;
	
	for (i = 0; i < n; i++)
	{
		cin >> rx[i] >> ry[i];
	}
	for (i = 0; i < m; i++)
	{
		cin >> bx[i] >> by[i];
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (rx[i] < rx[j])
			{
				for (k = 0; k < m; k++)
				{
					if (bx[k] > rx[i] && bx[k] <= rx[j] && ((by[k] - ry[i])*(rx[i] - rx[j]) + (ry[j] - ry[i])*(bx[k] - rx[i]) > 0))
					{
						a[i][j]++;
					}
				}
				a[j][i] = -a[i][j];
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				if (a[i][j] + a[j][k] + a[k][i] == 0)
				{
					ans++;
				}
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}


