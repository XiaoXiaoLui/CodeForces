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

const int N = 10005;
int x[N];
int y[N];
int n, w, u, v;

/*
y = (u/v)*(x - x0)
-u*x + vy = ?
*/
inline ll fun(int i)
{
	ll A = -u;
	ll B = v;
	
	return A*x[i] + B*y[i];
}

int main()
{
	int i, minIndex, maxIndex;
	double ans = 0;
	ll minRes = 1e18;
	ll maxRes = -1e18;
	
	scanf("%d%d%d%d", &n, &w, &v, &u);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}

	ll tmp;
	for (i = 0; i < n; i++)
	{
		tmp = fun(i);
		if (tmp > maxRes)
		{
			maxIndex = i;
			maxRes = tmp;
		}
		if (tmp < minRes)
		{
			minIndex = i;
			minRes = tmp;
		}
	}
	
	if (maxRes <= 0 || minRes >= 0)
	{
		ans = (double)w / u;
	}
	else
	{
		ans = (double)minRes / -u / v + (double)w / u;
	}
	
	printf("%.9lf\n", ans);
	return 0;
}