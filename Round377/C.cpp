#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;



int main()
{
	// USE_IOSTREAM;
	ll b, d, s, n, minS, minD, minB;
	cin >> b >> d >> s;
	ll ans;
	n = max(max(b, d), s);
	
	if (s == n)
	{
		if (b == n)
		{
			minD = max(n - 1, d);
			ans = minD - d;
		}
		else if (d == n)
		{
			ans = n - 1 - b;
		}
		else
		{
			ans = n - 1 - b + n - 1 - d;
		}
	}
	else if (d == n)
	{
		if (b == n)
		{
			ans = n - 1 - s;
		}
		else
		{
			ans = n - 1 - s + n - 1 - b;
		}
	}
	else
	{
		ans = n - 1 - s + n - 1 - d;
	}
	
	
	cout << ans << endl;
	
	return 0;
}