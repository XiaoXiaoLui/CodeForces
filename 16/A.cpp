#include <iostream>


using namespace std;

const int N = 101;

char a[N][N];

int main()
{
	int n, m, i, j;
	bool ok = true;
	
	cin >> n >> m;
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 2; j <= m; j++)
		{
			if (a[i][j] != a[i][j - 1])
			{
				ok = false;
				break;
			}
		}
	}
	
	for (i = 2; i <= n; i++)
	{
		if (a[i][1] == a[i - 1][1])
		{
			ok = false;
			break;
		}
	}
	
	if (ok)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}