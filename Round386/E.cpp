#include<bits/stdc++.h>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 2e5 + 100;

int a[N];

set<int> S;
int start0 = 2;
int start1 = 1;

int nextOdd()
{
	while (S.count(start1) > 0)
	{
		start1 += 2;
	}
	S.insert(start1);
	return start1;
}

int nextEven()
{
	while (S.count(start0) > 0)
	{
		start0 += 2;
	}
	S.insert(start0);
	return start0;
}

int main()
{
	USE_IOSTREAM;
	int n, m, i, c0, c1, size0, size1;
	
	
	cin >> n >> m;
	
	size0 = (m - start0) / 2 + 1;
	size1 = (m - start1) / 2 + 1;
	c0 = c1 = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (S.count(a[i]) > 0)
		{
			a[i] = -1;
			continue;
		}
		
		if (a[i] & 1)
		{
			if (a[i] <= m)
			{
				size1--;
			}
			c1++;
		}
		else
		{
			if (a[i] <= m)
			{
				size0--;
			}
			c0++;
		}
		
		S.insert(a[i]);
	}
	
	if (c0 + size0 < n / 2 || c1 + size1 < n / 2)
	{
		cout << -1 << endl;
		return 0;
	}
	
	int ans = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] < 0)
		{
			if (c0 < n / 2)
			{
				a[i] = nextEven();
				c0++;
			}
			else
			{
				a[i] = nextOdd();
				c1++;
			}
			ans++;
		}
		else if (a[i] % 2 && c1 > n / 2)
		{
			a[i] = nextEven();
			c1--;
			ans++;
		}
		else if (a[i] % 2 == 0 && c0 > n / 2)
		{
			a[i] = nextOdd();
			c0--;
			ans++;
		}
	}
	
	cout << ans << endl;
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
	return 0;
}