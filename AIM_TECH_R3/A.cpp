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
	int n, b, d, a, i, ans;
	
	scanf("%d%d%d", &n, &b, &d);
	
	ans = 0;
	ll sum = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (a <= b)
		{
			sum += a;
			if (sum > d)
			{
				sum = 0;
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}