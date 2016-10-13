#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 500003;
const int BIG_NUMBER = 2e9 + 2;

int a[N];


int main()
{
	int n;
	int k, left, right, mid,  i;
	ll t;
	
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	// increase
	left = *min_element(a + 1, a + 1 + n);
	right = BIG_NUMBER;
	
	while (right - left > 1)
	{
		t = 0;
		mid = ((ll)right + left) >> 1;
		for (i = 1; i <= n && t <= k; i++)
		{
			t += max(0, mid - a[i]);
		}
		
		if (t <= k)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	
	t = k;
	for (i = 1; i <= n; i++)
	{
		if (a[i] < left)
		{
			t -= left - a[i];
			a[i] = left;
		}
	}
	
	for (i = 1; i <= n && t; i++)
	{
		if (a[i] == left)
		{
			a[i]++;
			t--;
		}
	}
	
	// decrease
	left = 0;
	right = *max_element(a + 1, a + 1 + n);
	
	while (right - left > 1)
	{
		t = 0;
		mid = ((ll)right + left) >> 1;
		for (i = 1; i <= n && t <= k; i++)
		{
			t += max(0, a[i] - mid);
		}
		
		if (t <= k)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	
	t = k;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > right)
		{
			t -= a[i] - right;
			a[i] = right;
		}
	}
	
	for (i = 1; i <= n && t; i++)
	{
		if (a[i] == right)
		{
			a[i]--;
			t--;
		}
	}
	
	printf("%d\n", *max_element(a + 1, a + 1 + n) - *min_element(a + 1, a + 1 + n));
}