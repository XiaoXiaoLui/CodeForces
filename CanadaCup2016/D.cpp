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
#define pll pair<ll, ll>

typedef long long ll;

const int N = 3e5 + 100;
vector<pll> lst;

int main()
{
	USE_IOSTREAM;
	int i, n, ans, curRank;
	ll t,w, curT;
	cin >> n;
	
	cin >> t >> w;
	curT = t;
	
	//multiset<pll> S;
	priority_queue<ll, vector<ll>, greater<ll> > Q;
	for (i = 0; i < n - 1; i++)
	{
		cin >> t >> w;
		lst.push_back(mp(t, w));
	}
	sort(lst.begin(), lst.end());
	
	ans = n;
	while (curT >= 0)
	{
		while (!lst.empty() && lst.back().first > curT)
		{
			Q.push(lst.back().second - lst.back().first + 1);
			lst.pop_back();
		}
		
		ans = min(ans, (int)(Q.size() + 1));
		
		if (Q.empty())
		{
			break;
		}
		
		curT -= Q.top();
		Q.pop();
	}
	
	cout << ans << endl;
	
	return 0;
}