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
set<pii> S;
int main()
{
	USE_IOSTREAM;
	int n, k, i, ans, cnt;
	ans = cnt = 0;
	cin >> n >> k;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int pre = -1;
	for (i = 1; i <= n; i++)
	{
		if (a[i] >= 0)
		{
			if (a[i - 1] < 0)
			{
				ans++;
			}
		}
		else
		{
			if (a[i - 1] >= 0)
			{
				ans++;
			}
			cnt++;
			
			if (pre != -1 && i - pre > 1)
			{
				S.insert({i - pre - 1, pre + 1});
			}
			
			pre = i;
		}
	}
	
	if (cnt > k)
	{
		cout << -1 << endl;
		return 0;
	}
	
	int rest = k - cnt;
	while (!S.empty() && rest >= S.begin()->first)
	{
		rest -= S.begin()->first;
		ans -= 2;
		S.erase(S.begin());
	}
	
	if (pre != -1 && i - pre - 1 > 0 && rest >= i - pre - 1)
	{
		ans -= 1;
	}
	
	cout << ans << endl;
	
	return 0;
}