// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

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



const int N = 3e5 + 100;
const int INF = 2e9;



pii a[N];
int srt[N];
int b[N];

bool cmp(int i, int j)
{
	return a[i] < a[j];
}

int main()
{
	//USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int n, m, i, j, l, r;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &l, &r);
		a[i].first = l;
		a[i].second = r;
		srt[i] = i;
	}
	
	sort(srt + 1, srt + 1 + n, cmp);
	set<pii> S;
	pii ans = {0, 0};
	for (i = 1; i <= n; i++)
	{
		while (!S.empty() && S.begin()->first < a[srt[i]].first 
			|| S.size() >= m && S.begin()->first < a[srt[i]].second)
		{
			S.erase(S.begin());
		}
		
		if (S.size() >= m)
		{
			continue;
		}
		
		S.insert({a[srt[i]].second, srt[i]});
		if (S.size() == m)
		{
			ans = max(ans, {S.begin()->first - a[srt[i]].first + 1, i});
		}
	}
	
	S.clear();
	if (ans.first > 0)
	{
		for (i = 1; i <= n; i++)
		{
			while (!S.empty() && S.begin()->first < a[srt[i]].first 
				|| S.size() >= m && S.begin()->first < a[srt[i]].second)
			{
				S.erase(S.begin());
			}
			
			if (S.size() >= m)
			{
				continue;
			}
			
			S.insert({a[srt[i]].second, srt[i]});
			if (i == ans.second)
			{
				int cnt = 0;
				auto iter = S.begin();
				while (cnt < m)
				{
					b[++cnt] = iter->second;
					iter++;
				}
				break;
			}
		}
	}
	else
	{
		for (i = 1; i <= m; i++)
		{
			b[i] = i;
		}
	}
	
	printf("%d\n", ans.first);
	for (i = 1; i <= m; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	
	return 0;
}