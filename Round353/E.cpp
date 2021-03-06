#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 500005;

int a[N];
deque<int> dq;
ll sum[N];
int n;

int main()
{
	int i;
	ll ans = 0;
	
	cin >> n;
	
	for (i = 1; i < n; i++)
	{
		cin >> a[i];
	}
	
	sum[n - 1] = 1;
	ans = 1;
	dq.push_front(n - 1);
	int index;
	for (i = n - 2; i >= 1; i--)
	{
		index = upper_bound(dq.begin(), dq.end(), a[i]) - dq.begin() - 1;
		sum[i] = n - i + sum[dq[index]] - (a[i] - dq[index]);
		ans += sum[i];
		
		while (!dq.empty() && a[i] >= a[dq.front()])
		{
			dq.pop_front();
		}
		dq.push_front(i);
	}
	
	cout << ans << endl;
	
	return 0;
}