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
	int n, a, b, i;
	string s;
	cin >> n >> a >> b;
	cin >> s;
	
	int ans = 1e9;
	if (s[a - 1] == s[b - 1])
	{
		ans = 0;
	}
	
	int first, second;
	first = second = -1e9;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			first = i;
			ans = min(ans, i - second);
		}
		else
		{
			second = i;
			ans = min(ans, i - first);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}