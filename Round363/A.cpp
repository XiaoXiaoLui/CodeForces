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

const int N = 2e5 + 5;
char s[N];
int a[N];

int main()
{
	int n, i;
	char ch;
	scanf("%d", &n);
	scanf("%s", s);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	int ans = 2e9 + 5;
	bool ok = false;
	for (i = 0; i < n - 1; i++)
	{
		if (s[i] == 'R' && s[i + 1] == 'L')
		{
			ok = true;
			ans = min(ans, (a[i + 1] - a[i]) / 2);
		}
	}
	
	if (ok)
	{
		printf("%d\n", ans);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}