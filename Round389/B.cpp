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

char changeTo[200];
bool visit[200];
vector<pair<char, char> > ans;

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int i, j, n;
	string s1, s2;
	cin >> s1 >> s2;
	
	bool ok = true;
	for (i = 0; i < s1.size(); i++)
	{
		if (changeTo[s1[i]] && changeTo[s1[i]] != s2[i])
		{
			ok = false;
			break;
		}
		
		changeTo[s1[i]] = s2[i];
		if (changeTo[s2[i]] && changeTo[s2[i]] != s1[i])
		{
			ok = false;
			break;
		}
		changeTo[s2[i]] = s1[i];
		
	}
	
	if (!ok)
	{
		cout << -1 << endl;
		return 0;
	}
	
	for (i = 'a'; i <= 'z'; i++)
	{
		if (visit[i])
		{
			continue;
		}
		if (changeTo[i] && changeTo[i] != i)
		{
			ans.push_back({(char)i, changeTo[i]});
			visit[changeTo[i]] = true;
		}
	}
	
	cout << ans.size() << endl;
	for (i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	return 0;
}