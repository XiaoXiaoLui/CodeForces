#include <iostream>

using namespace std;


const int N = 11;

int count[N];

int main()
{
	int i;
	long long n, a, b, m;
	long long ans = 0;
	
	cin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		cin >> a >> b;
		count[b] += a;
	}
	
	for (i = 10; i >= 1 && n; i--)
	{
		if (n >= count[i])
		{
			ans += count[i] * i;
			n -= count[i];
		}
		else
		{
			ans += (long long)i * n;
			n = 0;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}