#include <iostream>

using namespace std;


int gcd(int a, int b)
{
	int c;
	while (a % b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	
	return b;
}

int main()
{
	int a, b, x, y, g, k;
	
	cin >> a >> b >> x >> y;
	g = gcd(x, y);
	x = x / g;
	y = y / g;
	
	k = min(a / x, b / y);
	a = k * x;
	b = k * y;
	
	cout << a << " " << b << endl;
	
	return 0;
}