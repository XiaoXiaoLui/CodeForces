#include <iostream>


using namespace std;

typedef long long ll;

const int N = 100002;
ll X[N];
ll M[N];

int main()
{
	ll n, i, m, x, ans = 0, a, b, c, d, j, maskA, maskB;
	int count;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> X[i] >> M[i];
	}
	
	for (i = 0; i < n; i++)
	{
		x = X[i];
		m = M[i];
		a = x;
		b = x + m - 1;
		c = 0;
		d = 1;
		
		if ((m >> 1) & 1)
		{
			c ^= 1;
		}
		if ((m & 1) && (a & 1))
		{
			c ^= 1;
		}
		
		maskA = -(a & 1);
		maskB = (b & 1) ? 0 : (ll)-1;
		a &= ~(ll)1;
		b &= ~(ll)1;
		c ^= (a & maskA) ^ (b & maskB);
		/*
		for (j = 1; j <= 62; j++)
		{
			d = (ll)1 << j;
			if ((a & d) && (a & 1))
			{
				c ^= d;
			}
			if ((b & d) && !(b & 1))
			{
				c ^= d;
			}
		}*/
		
		ans ^= c;
	}
	
	if (ans)
	{
		cout << "tolik" << endl;
	}
	else
	{
		cout << "bolik" << endl;
	}
	
	return 0;
}