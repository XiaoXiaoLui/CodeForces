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

const int N = 2e5 + 100;
char path[N];

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int n, i;
	int vDir, hDir;
	cin >> n >> path;
	
	int ans = 1;
	vDir = hDir = 0;
	for (i = 0; i < n; i++)
	{
		switch (path[i])
		{
		case 'L':
			if (hDir > 0)
			{
				ans++;
				vDir = hDir = 0;
			}
			hDir = -1;
			break;
		case 'R':
			if (hDir < 0)
			{
				ans++;
				vDir = hDir = 0;
			}
			hDir = 1;
			break;
		case 'U':
			if (vDir < 0)
			{
				ans++;
				vDir = hDir = 0;
			}
			vDir = 1;
			break;
		case 'D':
			if (vDir > 0)
			{
				ans++;
				vDir = hDir = 0;
			}
			vDir = -1;
			break;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}