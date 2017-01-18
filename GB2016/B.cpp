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

const int N = 100;
const int M = 2e4;
int w[N];
string dir[N];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> w[i] >> dir[i];
	}
	
	bool ok = true;
	int cur = 0;
	for (i = 1; i <= n; i++)
	{
		if (dir[i] == "North")
		{
			if (cur == 0)
			{
				ok = false;
				break;
			}
			cur += w[i];
		}
		else if (dir[i] == "South")
		{
			if (cur == -M)
			{
				ok = false;
				break;
			}
			cur -= w[i];
		}
		else 
		{
			if (cur == 0 || cur == -M)
			{
				ok = false;
				break;
			}
		}
		
		if (cur > 0 || cur < -M)
		{
			ok = false;
			break;
		}
	}
	
	if (cur != 0)
	{
		ok = false;
	}
	
	if (ok)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}