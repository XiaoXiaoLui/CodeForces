#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1002;


struct House
{
	int x;
	int side;
};

House a[N];

bool cmp(const House &a, const House &b)
{
	return (a.x < b.x);
}

int main()
{
	int n, t, i, ans = 2;
	
	cin >> n >> t;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].side;
	}
	sort(a + 1, a + 1 + n, cmp);
	
	for (i = 1; i < n; i++)
	{
		if (2 * (a[i + 1].x - a[i].x) > (a[i + 1].side + a[i].side + 2 * t))
		{
			ans += 2;
		}
		else if  (2 * (a[i + 1].x - a[i].x) == (a[i + 1].side + a[i].side + 2 * t))
		{
			ans += 1;
		}
	}
	
	cout << ans << endl;
}