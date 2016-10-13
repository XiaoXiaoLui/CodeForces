#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100005;
int a[N];

int main()
{
	int n, h, k, i;
	
	scanf("%d%d%d", &n, &h, &k);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	long long ans = 0;
	long long r = 0;
	long long j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] + r <= h)
		{
			r += a[i];
		}
		else
		{
			j = (r + a[i] - h) / k;   
			if ((r + a[i] - h) % k)
			{
				j++;
			}
			
			r = r - k * j;
			if (r < 0)
			{
				r = 0;
			}
			r += a[i];
			ans += j;
		}
	}
	
	j = r / k;
	if (r % k)
	{
		j++;
	}
	ans += j;
	
	cout << ans << endl;
	
	return 0;
}