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


const int N = 1e5 + 100;

int cnt[N];
int isPrime[N];
int a[N];

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int n, i, j;
	cin >> n;
	
	int maxNum = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
		maxNum = max(maxNum, a[i]);
	}
	
	int ans = 1;
	for (i = 2; i <= maxNum; i++)
	{
		int curCnt = 0;
		for (j = i; j <= maxNum; j += i)
		{
			curCnt += cnt[j];
		}
		
		ans = max(ans, curCnt);
	}
	
	cout << ans << endl;
	
	return 0;
}