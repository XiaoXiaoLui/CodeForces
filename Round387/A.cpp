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



int main()
{
	USE_IOSTREAM;
	ll n, a, b;
	cin >> n;
	ll ans = 1;
	for (a = 2; a*a <= n; a++)
	{
		if (n % a == 0)
		{
			ans = a;
		}
	}
	
	cout << ans << " " << n / ans << endl;
	
	return 0;
}