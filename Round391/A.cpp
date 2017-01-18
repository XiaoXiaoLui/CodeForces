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


// "Bulbasaur".
int cnt[256];

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int i;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++)
	{
		cnt[s[i]]++;
	}
	
	int ans = 1e9;
	ans = min(ans, cnt['B']);
	ans = min(ans, cnt['u'] / 2);
	ans = min(ans, cnt['l']);
	ans = min(ans, cnt['b']);
	ans = min(ans, cnt['a'] / 2);
	ans = min(ans, cnt['s']);
	ans = min(ans, cnt['r']);
	
	cout << ans << endl;
	
	return 0;
}