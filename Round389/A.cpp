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



int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int n, m, k, i, j, dir;
	cin >> n >> m >> k;
	k--;
	j = k / (2*m);
	i = k % (2*m);
	dir = i % 2;
	i = i / 2;
	j++;
	i++;
	char ch = dir ? 'R' : 'L';
	cout << j << " " << i << " " << ch << endl;
	
	return 0;
}