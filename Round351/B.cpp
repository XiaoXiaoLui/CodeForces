#include <iostream>
#include <climits>

using namespace std;

void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
	

int main()
{
	int n,  m, i;
	
	cin >> n >> m;
	
	int max1, min2, a, b;
	
	max1 = 0;
	min2 = INT_MAX;
	for (i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (a > b)
		{
			swap(a, b);
		}
		
		if (a > max1)
		{
			max1 = a;
		}
		if (b < min2)
		{
			min2 = b;
		}
	}
	
	int ans = min2 - max1;
	
	if (ans < 0)
	{
		ans = 0;
	}
	if (ans > n - 1)
	{
		ans = n - 1;
	}
	
	cout << ans << endl;
	
	return 0;
}