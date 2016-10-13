#include <iostream>
#include <cstring>

using namespace std;


typedef long long ll;

#define N 60

int n;
ll k;
int a[N];
ll d[N][2][2];


ll dfs(int l, bool less, bool lessInvert)
{
	int r = n + 1 - l;
	if (l > r)
	{
		return 1;
	}
	
	if (d[l][less][lessInvert] != -1)
	{
		return d[l][less][lessInvert];
	}
	
	int i, j;
	d[l][less][lessInvert] = 0;
	for (i = 0; i < 2; i++)
	{
		if (a[l] == -1 || a[l] == i)
		{
			for (j = 0; j < 2; j++)
			{
				if (a[r] == -1 || a[r] == j)
				{
					if ((l < r || i == j) && (less || i <= j) && (lessInvert || i <= 1 - j))
					{
						d[l][less][lessInvert] += dfs(l + 1, less || i < j, lessInvert || i < 1 - j);
					}
				}
			}
		}
	}
	
	
	return d[l][less][lessInvert];
}


int main()
{	
	cin >> n >> k;
	k++;
	
	memset(a, -1, sizeof(a));
	
	a[1] = 0;
	ll count = 0;
	
	memset(d, -1, sizeof(d));
	count = dfs(1, false, false);
	if (count < k)
	{
		cout << "-1" << endl;
		return 0;
	}
	
	for (int i = 2; i <= n; i++)
	{
		memset(d, -1, sizeof(d));
		a[i] = 0;
		count = dfs(1, false, false);
		
		if (count  < k)
		{
			a[i] = 1;
			k -= count;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << a[i];
	}
	cout << endl;
	
	return 0;
}