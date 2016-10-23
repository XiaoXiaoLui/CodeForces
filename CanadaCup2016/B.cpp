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

const int TIME[] = {4, 5, 6, 3, 2, 1};

int main()
{
	USE_IOSTREAM;
	ll n, per4Row;
	per4Row = 16;
	char ch;
	cin >> n >> ch;
	
	n--;
	ll q, r;
	q = n / 4;
	r = n % 4 % 2;
	
	ll ans = q * per4Row;
	if (r)
	{
		ans += TIME[ch - 'a'] + 7;
	}
	else
	{
		ans += TIME[ch - 'a'];
	}
	
	cout << ans << endl;
	return 0;
}