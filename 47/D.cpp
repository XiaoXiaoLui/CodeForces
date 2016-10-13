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

const int N = 15;
ll a[N];
int c[N];

ll nextMask(ll curMask, int n)
{
	int first1;
	int count1 = 0;
	for (first1 = 0; first1 < n; first1++)
	{
		if ((curMask & (1LL << first1) )  && !(curMask & (1LL << (first1 + 1))))
		{
			break;
		}
		if (curMask & (1LL << first1))
		{
			count1++;
		}
	}
	
	if (first1 >= n - 1)
	{
		return -1;
	}
	
	ll res = curMask & ~((1LL << (first1 + 1)) - 1);
	res |= 1LL << (first1 + 1);
	res |= (1LL << count1) - 1;
	
	return res;
}

int calOnes(ll number)
{
	int c = 0;
	while (number)
	{
		c += number & 1;
		number >>= 1;
	}
	
	return c;
}

int main()
{
	int n, m, i, j;
	ll tmp;
	char s[40];
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%s%d", s, &c[i]);
		
		for (j = 0, tmp = 0; j < n; j++)
		{
			tmp = tmp * 2 + (s[j] - '0');
		}
		a[i] = tmp;
	}
	ll curMask = (1LL << c[0]) - 1;
	
	int ans = 0;
	bool ok ;
	ll curValue;
	do
	{
		ok = true;
		curValue = a[0] ^ (~curMask & ((1LL << n) - 1));
		for (i = 1; i < m && ok; i++)
		{
			if (calOnes(curValue ^ a[i]) != n - c[i])
			{
				ok = false;
			}
		}
		
		if (ok)
		{
			ans++;
		}
	} while ((curMask = nextMask(curMask, n)) != -1);
	
	printf("%d\n", ans);
	return 0;
}