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

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;


vector<char> ans;

int main()
{
	ll n, k, x;
	int m, i;
	scanf(LLD LLD, &n, &k);
	scanf("%d", &m);
	if (n >= 2 * k)
	{
		ll left = 2 * k;
		char ch;
		for (i = 0; i < m; i++)
		{
			scanf(LLD, &x);
			x = n + 1 - x;
			if ((n - left) & 1 && k > 1)
			{
				if (x == 1 || (!(x & 1) && x < left))
				{
					ch = 'X';
				}
				else
				{
					ch = '.';
				}
			}
			else
			{
				if (x & 1 && x < left)
				{
					ch = 'X';
				}
				else
				{
					ch = '.';
				}
			}
			
			
			ans.push_back(ch);
		}
	}
	else
	{
		ll right = 2 * (n - k) - 1;
		for (i = 0; i < m; i++)
		{
			scanf(LLD, &x);
			if (x & 1 && x <= right)
			{
				ans.push_back('.');
			}
			else
			{
				ans.push_back('X');
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		printf("%c", ans[i]);
	}
	printf("\n");
	
	return 0;
}