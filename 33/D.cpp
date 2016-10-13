#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1005;

struct Point
{
	double x;
	double y;
};

Point a[N];
Point b[N];
//int ans[N][N];
double r[N];
double d[N][N];
pair<int, int> q[100005];

inline double sqr(double x)
{
	return x*x;
}

inline double dist(const Point &a, const Point &b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}


int main()
{
	int n, m, num, i, j, k;
	scanf("%d%d%d", &n, &m, &num);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &a[i].x, &a[i].y);
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%lf%lf%lf", &r[i], &b[i].x, &b[i].y);
	}
	
	for (i = 1; i <= num; i++)
	{
		scanf("%d%d", &q[i].first, &q[i].second);
		if (q[i].first > q[i].second)
		{
			swap(q[i].first, q[i].second);
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			d[i][j] = dist(a[i], b[j]) - r[j];
		}
	}
	
	
	int ans;
	for (k = 1; k <= num; k++)
	{
		i = q[k].first;
		j = q[k].second;
		ans = 0;
		for (int l = 1; l <= m; l++)
		{
			if (d[i][l] * d[j][l] < 0)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}