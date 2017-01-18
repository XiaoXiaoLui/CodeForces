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
	int k2, k3, k5, k6, cnt256, cnt32;
	scanf("%d%d%d%d", &k2, &k3, &k5, &k6);
	
	cnt256 = min(k2, min(k5, k6));
	k2 -= cnt256;
	k5 -= cnt256;
	k6 -= cnt256;
	
	cnt32 = min(k2, k3);
	
	ll ans = (ll)cnt256 * 256 + cnt32 * 32;
	printf("%lld\n", ans);
	
	return 0;
}