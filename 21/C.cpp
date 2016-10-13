#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

const int N = 100005;

typedef long long ll;

int a[N];
deque<int> s1;
deque<int> s2;


int main()
{
	int sum = 0;
	int n, i, j, c;
	
	ll ans;
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	if (sum % 3 != 0)
	{
		ans = 0;
	}
	else
	{
		c = sum / 3;
		for (i = 1, sum = 0; i <= n; i++)
		{
			sum += a[i];
			if (sum == c)
			{
				s1.push_back(i);
			}
		}
		
		for (i = n, sum = 0; i >= 1; i--)
		{
			sum += a[i];
			if (sum == c)
			{
				s2.push_front(i);
			}
		}
		
		ans = 0;
		deque<int>::iterator iter;
		for (i = 0; i < s1.size(); i++)
		{
			iter = upper_bound(s2.begin(), s2.end(), s1[i] + 1);
			ans += s2.end() - iter;	
		}
	}
	cout << ans << endl;
	
	return 0;
}