#include <iostream>

using namespace std;

#define N 20
#define M (1 << 19)
typedef long long ll;

int a[N][N];
ll ans;
ll f[N][M];


int main()
{
	int n, m, i, j, k;
	cin >> n >> m;
	
	for (k = 1; k <= m; k++)
	{
		cin >> i >> j;

		
		a[i - 1][j - 1] = a[j - 1][i - 1] = 1;
	}
	
	for (i = 0; i < n; i++)
	{
		f[i][1 << i] = 1;
	}
	
	
	int s;
	int min;
	int count;
	for (s = 1; s < M; s++)
	{
		for (i = 0; ((1 << i) & s) == 0; i++);
		
		min = i;
		count = 0;
		for (i = min; i < n; i++)
		{
			if (((1 << i) & s))
			{
				count++;
			}
		}
		
		for (i = min; i < n; i++)
		{
			if ((1 << i) & s)
			{
				if (a[i][min] && count >= 3)
				{
					ans += f[i][s];
				}
				
				for (j = min + 1; j < n; j++)
				{
					if (!((1 << j) & s) && a[i][j])
					{
						f[j][s + (1 << j)] += f[i][s];
					}
				}
			}
		}
		
		
	}
	
	
	cout << ans / 2;
	
	return 0;
}