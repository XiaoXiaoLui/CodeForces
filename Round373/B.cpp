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

const int N = 1e5 + 100;

char init[N];
char s[N];
//int dp[N][2];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	scanf("%s", s);
	
	strcpy(init, s);
	
	int ans = 1e9;
	int c1, c2;
	
	// begin with r
	c1 = c2 = 0;
	for (i = 0; i < n; i++)
	{
		if (s[i] == 'r' && (i & 1))
		{
			c1++;
		}
		else if (s[i] == 'b' && !(i & 1))
		{
			c2++;
		}
	}
	
	ans = min(ans, min(c1, c2) + abs(c1 - c2));
	
	// begin with b
	strcpy(s, init);
	c1 = c2 = 0;
	for (i = 0; i < n; i++)
	{
		if (s[i] == 'r' && !(i & 1))
		{
			c1++;
		}
		else if (s[i] == 'b' && (i & 1))
		{
			c2++;
		}
	}
	
	ans = min(ans, min(c1, c2) + abs(c1 - c2));
	
	printf("%d\n", ans);
	return 0;
}

