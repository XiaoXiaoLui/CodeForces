#include <iostream>
#include <climits>
#include <cmath>

using namespace std;


int main()
{
	int n, x0, a, b, i;
	int left = INT_MIN;
	int right = INT_MAX;
	
	cin >> n >> x0;
	
	bool failed = false;
	
	for (i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a > b)
		{
			swap(a, b);
		}
		
		if (a <= left)
		{
			if (b <= left)
			{
				failed = true;
				break;
			}
			else 
			{
				right = min(right, b);
			}
		}
		else if (a >left && a <= right)
		{
			left = a;
			right = min(right, b);
		}
		else
		{
			failed = true;
			break;
		}
	}
	
	int ans;
	if (failed)
	{
		ans = -1;
	}
	else
	{
		if (x0 < left)
		{
			ans = left - x0;
		}
		else if (x0 >= left && x0 <= right)
		{
			ans = 0;
		}
		else
		{
			ans = x0 - right;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}