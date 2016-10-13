#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 5005;

double x[N], y[N], z[N];

inline double sqr(double x)
{
	return x*x;
}

inline double dist(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2));
}

inline double dist(int i, int j)
{
	return dist(x[i], y[i], z[i], x[j], y[j], z[j]);
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
	}
	
	double ans = 1e9;
	double perimeter;
	for (i = 1; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			perimeter = dist(0, i) + dist(0, j) + dist(i, j);
			ans = min(ans, perimeter / 2);
		}
	}
	
	
	printf("%.9lf\n", ans);
	return 0;
}