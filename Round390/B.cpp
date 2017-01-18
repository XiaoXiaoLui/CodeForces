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

const int N = 105;

int a[N];

vector<pii> ans;
int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int n, i;
	cin >> n;
	bool flag = false;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i])
		{
			flag = true;
		}
	}
	if (!flag)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	for (i = 1; a[i] == 0; i++);
	
	ans.push_back({1, i});
	for (i++; i <= n; i++)
	{
		if (a[i])
		{
			ans.push_back({i, i});
		}
		else
		{
			ans[ans.size() - 1].second = i;
		}
	}
	
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for (i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	return 0;
}