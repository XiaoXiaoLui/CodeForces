#include <iostream>

using namespace std;

typedef long long ll;


int main()
{
	ll n, d, m, l, start;
	int i;
	
	cin >> n >> d >> m >> l;
	
	ll pos = 0;
	ll end = (n - 1) * m + l;
	bool find = false;
	for (i = 0; i < m; i++)
	{
		pos = i * d;
		if (pos % m > l)
		{
			find = true;
			break;
		}
	}
	
	if (!find)
	{
		pos = (end / d + 1) * d;
	}
	
	cout << pos << endl;
	return 0;
}