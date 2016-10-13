#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int a[1000002];

int main()
{
	ll n, k, i, s;
	
	cin >> n >> k;
	
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	
	i = (ll)sqrt(2*k);
	
	s = i*(i+1)/2;
	
	if (s != k)
	{
		if (s > k)
		{
			i--;
		}
		i = k - (i*(i+1)/2);
	}
	
	cout << a[i] << endl;
	
	
	
	
	return 0;
}
