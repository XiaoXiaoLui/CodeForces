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

const int N = 1e5 + 100;

vector<pii> srt;

bool cmp(const pii &a, const pii &b)
{
	return (a.first + a.second) > (b.first + b.second);
}


int main()
{
	// USE_IOSTREAM;
	int n, i, a1, b1, a2, b2;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
		
		if (a1 + b1 >= a2 + b2)
		{
			srt.push_back(mp(a1, b1));
			srt.push_back(mp(a2, b2));
		}
		else if (a1 > b2)
		{
			srt.push_back(mp(a1 - b2, b2 - a1));
		}
		else if (b1 > a2)
		{
			srt.push_back(mp(a2 - b1, b1 - a2));
		}
	}
	
	ll ans = 0;
	sort(srt.begin(), srt.end(), cmp);
	for (i = 0; i < srt.size(); i++)
	{
		if (i & 1)
		{
			ans -= srt[i].second;
		}
		else
		{
			ans += srt[i].first;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}