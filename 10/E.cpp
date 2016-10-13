#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int n, i, j, k, w1, w2, s1, s2, c, ans;
	int a[402];
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	
	ans = INT_MAX;
	for (i = 1; i < n; i++)
	{
		for (j = i; j <= n; j++)
		{
			c = a[i] - 1;
			w1 = 0;
			s1 = 0;
			for (k = i; k <= j; k++)
			{
				s1 += c / a[k];
				w1 += (c / a[k]) * a[k];
				c = c % a[k];
			}
			s1++;
			w1 += a[j];
			
			s2 = 0;
			w2 = w1;
			for (k = 1; k <= n; k++)
			{
				s2 += w2 / a[k];
				w2 %= a[k];
			}
			
			if (s1 < s2 && ans > w1)
			{
				ans = w1;
			}
		}
	}
	
	
	if (ans == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}

	
	return 0;
}