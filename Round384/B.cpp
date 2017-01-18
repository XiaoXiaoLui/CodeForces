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

ll len[60];

int find(ll k, int n)
{
	if (k <= len[n - 1])
	{
		return find(k, n - 1);
	}
	else if (k == len[n - 1] + 1)
	{
		return n;
	}
	else
	{
		return find(k - len[n - 1] - 1, n - 1);
	}
}

int main()
{
	USE_IOSTREAM;
	int n;
	ll k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		len[i] = 2*len[i - 1] + 1;
	}
	
	int ans = find(k, n);
	cout << ans << endl;
	
	return 0;
}