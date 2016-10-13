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




int main()
{
	int n, c, pre, cur, i, ans;
	ans = 0;
	scanf("%d%d", &n, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &cur);
		if (i == 0 || cur - pre > c)
		{
			ans = 1;
		}
		else
		{
			ans++;
		}
		pre = cur;
	}
	
	printf("%d\n", ans);
	return 0;
}