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
	// USE_IOSTREAM;
	ll n, a, b, c, ans;
	scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
	switch (n % 4)
	{
	case 0:
		ans = 0;
		break;
	case 1:
		ans = a*3;
		ans = min(ans, c);
		ans = min(ans, a + b);
		break;
	case 2:
		ans = min(2*a, min(b, 2*c));
		break;
	case 3:
		ans = min(a, 3*c);
		ans = min(ans, b + c);
		break;
	}
	
	printf("%lld\n", ans);
	return 0;
}