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
	string s, ans;
	int n, i;
	cin >> n >> s;
	for (i = 0; i < n; )
	{
		if (s.substr(i, 3) == "ogo")
		{
			i += 3;
			while (s.substr(i, 2) == "go")
			{
				i += 2;
			}
			ans += "***";
		}
		else
		{
			ans += s[i];
			i++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}