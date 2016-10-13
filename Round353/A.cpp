#include <iostream>

using namespace std;



int main()
{
	int a, b, c, q, r;
	bool ok = false;
	cin >> a >> b >> c;
	
	if (c == 0)
	{
		ok = (a == b);
	}
	else
	{
		q = (b - a) / c;
		r = (b - a) % c;
		
		if (q >= 0 && r == 0)
		{
			ok = true;
		}
		else
		{
			ok = false;
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