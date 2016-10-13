#include <iostream>

using namespace std;

const int N = 100006;


int a[N];
int sum[N];
int rsum[N];

int main()
{
	int n, i;
	int ans = 0;
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	sum[0] = a[0];
	for (i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	
	rsum[n - 1] = a[n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		rsum[i] = rsum[i + 1] + a[i];
	}
	
	for (i = 0; i <= n - 2; i++)
	{
		if (sum[i] == rsum[i + 1])
		{
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}