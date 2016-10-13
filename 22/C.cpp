#include <iostream>

using namespace std;

int main()
{
	int n, m, v, minm, maxm, i, j;
	
	cin >> n >> m >> v;
	minm = n - 1;
	maxm = (int)((long long)(n - 1)*(n - 2) / 2 + 1);
	
	if (m < minm || m > maxm)
	{
		cout << -1;
	}
	else
	{
		int u = (v == 1) ? 2 : 1;
		int c = m;
		for (i = 1; c > 0 && i <= n; i++)
		{
			if (i != v)
			{
				cout << v << " " << i << endl;
				c--;
			}
		}
		
		for (i = 1; c && i <= n; i++)
		{
			for (j = i + 1; c && j <= n; j++)
			{
				if (i != u && i != v && j != v && j != u)
				{
					cout << i << " " << j << endl;
					c--;
				}
			}
		}
		
	}
	
	
}