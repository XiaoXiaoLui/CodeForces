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

double sqr(double a)
{
	return a * a;
}

int main()
{
	double ans = 1e9, tmp;
	int n, a, b, x, y, v, i;
	scanf("%d%d", &a, &b);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &v);
		
		if (a == x && b == y)
		{
			ans = 0.0;
			break;
		}
		else
		{
			tmp = sqrt(sqr(x - a) + sqr(y - b)) / v;
			ans = min(ans, tmp);
		}
	}
	
	printf("%.9lf\n", ans);
	return 0;
}