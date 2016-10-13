#include <iostream>

using namespace std;


long long gcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long x1 = 0, y1 = 0;
	long long d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * x;
	
	return d;
}


int main()
{
	long long a, b, c;
	long long x, y;
	
	cin >> a >> b >> c;
	
	c = -c;
	long long d = gcd(a, b, x, y);
	
	if ((c % d) == 0)
	{
		cout << c / d * x << " " << c / d * y << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	
	
	return 0;
}