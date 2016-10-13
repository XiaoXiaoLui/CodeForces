#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
	ll n, m, x1, y1, x2, y2, ans, x, y;
	int i, t;
	cin >> t;
	
	for (i = 0; i < t; i++)
	{
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		x = abs(x1 - x2);
		y = abs(y1 - y2);
		
		if (x <= (n - 1) / 2 && y <= (m - 1) / 2)
		{
			ans = n * m - 2 * (n - x) * (m - y) + (n - 2 * x) * (m - 2 * y);
		}
		else
		{
			ans = n * m - 2 * (n - x) * (m - y);
		}
		
		
		cout << ans << endl;
	}
	
	
	return 0;
}