#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

char s[100005];

int main()
{
	ll ans = 1;
	
	scanf("%s", s);
	
	int i = 0, j;
	ll cur;
	for (i = 0; s[i]; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cur = s[i] - '0';
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			cur = (s[i] - 'a') + 36;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			cur = (s[i] - 'A') + 10;
		}
		else if (s[i] == '-')
		{
			cur = 62;
		}
		else
		{
			cur = 63;
		}
		
		for (j = 0; j <= 5; j++)
		{
			if ((cur & (1 << j)) == 0)
			{
				ans = (ans * 3) % M;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

