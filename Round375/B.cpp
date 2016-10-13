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


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 300;
char s[N];

int main()
{
	int n, i, ans1, ans2, start, c;
	bool bInParen;
	scanf("%d", &n);
	scanf("%s", s);
	s[n] = '_';
	
	ans1 = ans2 = 0;
	bInParen = false;
	c = 0;
	for (i = 0; i <= n; i++)
	{
		if (s[i] == '(')
		{
			if (c)
			{
				ans1 = max(ans1, c);
			}
			bInParen = true;
			c = 0;
		}
		else if (s[i] == ')')
		{
			if (c)
			{
				ans2++;
			}
			bInParen = false;
			c = 0;
		}
		else if (s[i] == '_')
		{
			if (c)
			{
				if (bInParen)
				{
					ans2++;
				}
				else
				{
					ans1 = max(ans1, c);
				}
			}
			c = 0;
		}
		else
		{
			c++;
		}
	}
	
	printf("%d %d\n", ans1, ans2);
	return 0;
}