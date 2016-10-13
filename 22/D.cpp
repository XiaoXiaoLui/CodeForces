#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval
{
	int l;
	int r;
	
};

bool cmp(const Interval &a, const Interval &b)
{
	return a.l < b.l || (a.l == b.l && a.r < b.r);
}

const int N = 1005;
const Interval INIT = {-1000000, 1000000};

vector<int> ans;
Interval a[N];


int main()
{
	int n, i, l, r;
	Interval cur = INIT;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> l >> r;
		a[i].l = min(l, r);
		a[i].r = max(l, r);
	}
	
	sort(a, a + n, cmp);
	
	for (i = 0; i < n; i++)
	{
		if (a[i].l > cur.r)
		{
			ans.push_back(cur.l);
			cur = a[i];
		}
		else
		{
			cur.l = max(cur.l, a[i].l);
			cur.r = min(cur.r, a[i].r);
		}
	}
	
	ans.push_back(cur.l);
	cout << ans.size() << endl;
	for (i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}