#include<bits/stdc++.h>

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
	USE_IOSTREAM;
	int n, i;
	string s;
	cin >> n >> s;
	
	int ans = 0;
	for (i = 0; i < n && s[i] == '<'; i++)
	{
		ans++;
	}
	
	for (i = n - 1; i >= 0 && s[i] == '>'; i--)
	{
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}