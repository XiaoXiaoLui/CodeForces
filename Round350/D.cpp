#include <iostream>

using namespace std;

typedef long long ll;

#define N 200002

ll a[N];
ll b[N];


int main()
{
	ll n, k, i;
	cin >> n >> k;
	
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	
	ll min = 0;
	ll max = 2 * 1000000000 + 1;
	ll mid;
	ll s;
	while (max - min > 1)
	{
		mid = (min + max) / 2;
		
		s = k;
		for (i = 1; i <= n && s >= 0; i++)
		{
			if (b[i] < a[i] * mid)
			{
				s -= a[i]*mid - b[i];
			}
		}
		
		if (s < 0)
		{
			max = mid;
		}
		else
		{
			min = mid;
		}
	}
	
	cout << min << endl;
	return 0;
}