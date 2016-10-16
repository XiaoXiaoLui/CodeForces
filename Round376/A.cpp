#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;



int main()
{
	USE_IOSTREAM;
	string str;
	int i, ans;
	cin >> str;
	char cur = 'a';
	ans = 0;
	for (i = 0; i < str.size(); i++)
	{
		int tmp = abs(cur - str[i]);
		ans += min(tmp, 26 - tmp);
		cur = str[i];
	}
	
	cout << ans << endl;
	
	return 0;
}