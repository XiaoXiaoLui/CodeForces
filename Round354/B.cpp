#include <iostream>

using namespace std;

const int M = 1 << 11;
const int N = 10;

int a[N][N];

int main()
{
	int i, j, p, ans, n, t;
	cin >> n >> t;
	bool poured = false;
	bool hasNotFull = true;
	for (; t > 0; t--)
	{
		a[0][0] += M;
		
		for (i = 0;  i < n; i++)
		{
			poured = false;
			for (j = 0; j <=i; j++)
			{
				if (a[i][j] > M)
				{
					p = a[i][j] - M;
					a[i][j] = M;
					a[i + 1][j] += p / 2;
					a[i + 1][j + 1] += p / 2;
					poured = true;
				}
				else if (a[i][j] < M)
				{
					hasNotFull = true;
				}
			}
			if (!poured)
			{
				break;
			}
		}
		
		if (i == n && !hasNotFull)
		{
			break;
		}
		
	}
	
	ans = 0;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (a[i][j] == M)
			{
				ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}