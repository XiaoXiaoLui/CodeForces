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

const int N = 3e8 + 100;
vector<bool> isPrime(N, true);

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int l, r, ans, i, j;
	cin >> l >> r;
	for (i = 3; i * i <= r; i += 2)
	{
		if (!isPrime[i])
		{
			continue;
		}
		for (j = i + i; j <= r; j += i)
		{
			isPrime[j] = false;
		}
	}
	
	int start = (l / 4) * 4 + 1;
	if (start < l || start == 1)
	{
		start += 4;
	}
	
	ans = 0;
	for (i = start; i <= r; i += 4)
	{
		if (isPrime[i])
		{
			ans++;
		}
	}
	
	if (l <= 2 && 2 <= r)
	{
		ans++;
	}
	cout << ans << endl;
	return 0;
}