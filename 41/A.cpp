#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s, t;
	cin >> s >> t;
	if (s.length() != t.length())
	{
		cout << "NO" << endl;
	}
	else
	{
		int len = s.length();
		for (int i = 0, j = len - 1; i < len; i++, j--)
		{
			if (s[i] != t[j])
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
	}
	
	return 0;
}