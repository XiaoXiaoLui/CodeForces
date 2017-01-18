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

int s;
void reverse(int &x)
{
	x = s - x;
}

double calTime(int x1, int x2, int t)
{
	return ((double)abs(x2 - x1)) * t;
}

int main()
{
	// USE_IOSTREAM;
	int x1, x2, t1, t2, x0, dir;
	cin >> s >> x1 >> x2;
	cin >> t1 >> t2;
	cin >> x0 >> dir;
	
	double ans = calTime(x1, x2, t2);
	
	// reverse
	if (x1 > x2)
	{
		reverse(x1);
		reverse(x2);
		reverse(x0);
		dir *= -1;
	}
	
	// now x1 < x2
	if (dir > 0)
	{
		if (x0 <= x1)
		{
			ans = min(ans, calTime(x0, x2, t1));
		}
		else if (x0 <= x2)
		{
			ans = min(ans, calTime(x0, x2, t1) + 2*s*t1);
		}
		else
		{
			ans = min(ans, calTime(x0, s, t1) + s*t1 + calTime(0, x2, t1));
		}
	}
	else
	{
		ans = min(ans, calTime(x0, 0, t1) + calTime(0, x2, t1));
	}

	cout << ans << endl;
	return 0;
}