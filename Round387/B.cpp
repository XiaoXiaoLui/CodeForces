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

int size[4];
char ch[4] = {'A', 'C', 'G', 'T'};

int main()
{
	USE_IOSTREAM;
	int n;
	string s;
	cin >> n >> s;
	
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (s[i] == ch[j])
			{
				size[j]++;
			}
		}
	}
	
	bool ok = true;
	if (n % 4 != 0)
	{
		ok = false;
	}
	for (j = 0; j < 4; j++)
	{
		if (size[j] > n / 4)
		{
			ok = false;
		}
	}
	
	if (!ok)
	{
		cout << "===" << endl;
		return 0;
	}
	
	for (i = 0; i < n; i++)
	{
		if (s[i] == '?')
		{
			for (j = 0; j < 4; j++)
			{
				if (size[j] < n / 4)
				{
					s[i] = ch[j];
					size[j]++;
					break;
				}
			}
		}
	}
	
	cout << s << endl;
	
	return 0;
}