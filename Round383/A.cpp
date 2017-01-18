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

const int N = 105;

int a[N];
bool visit[N];

inline ll gcd(ll a, ll b)
{
	ll c;
	
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	
	return a;
}

ll lcm(ll a, ll b)
{
	ll c = gcd(a, b);
	return a / c * b;
}

int main()
{
	USE_IOSTREAM;
	int n, i, j, len;
	set<int> S;
	cin >> n;
	bool ok = true;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (S.count(a[i]) > 0)
		{
			ok = false;
		}
		S.insert(a[i]);
	}
	
	if (!ok)
	{
		cout << -1 << endl;
		return 0;
	}
	
	S.clear();
	for (i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			len = 1;
			visit[i] = true;
			for (j = a[i]; j != i; j = a[j], len++)
			{
				visit[j] = true;
			}
			
			if (len % 2 == 0)
			{
				len /= 2;
			}
			S.insert(len);
		}
	}
	
	ll ans = 1;
	for (auto l : S)
	{
		ans = lcm(ans, l);
	}
	
	cout << ans << endl;
	
	
	return 0;
}

