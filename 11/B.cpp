#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
	ll x, n, i;
	
	cin >> x;
	x = abs(x);
	
	n = (ll)sqrt(2 * x);
	
	while (n*(n+1)/2 < x)
	{
		n++;
	}
	
	if (n*(n+1)/2 == x || (n*(n+1)/2 - x) % 2 == 0)
	{
		
	}
	else
	{
		if (n % 2)
		{
			n += 2;
		}
		else
		{
			n++;
		}
	}
	
	cout << n;
	
	return 0;
}