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

const char VOWEL[6] = { 'A', 'E', 'I', 'O', 'U', 'Y'};

bool isVowel(char ch)
{
	for (int i = 0; i < 6; i++)
	{
		if (ch == VOWEL[i])
		{
			return true;
		}
	}
	
	return false;
}

int main()
{
	USE_IOSTREAM;
	
	string s;
	cin >> s;
	int pre = -1, i, ans;
	ans = 0;
	for (i = 0; i < s.size(); i++)
	{
		if (isVowel(s[i]))
		{
			ans = max(ans, i - pre);
			pre = i;
		}
	}
	
	ans = max(ans, (int)s.size() - pre);
	
	cout << ans << endl;
	
	return 0;
}