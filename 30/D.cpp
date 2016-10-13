#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e5 + 5;
double x[N];
double XN, YN;
int n, k;

double sqr(double x)
{
	return x*x;
}

inline double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

inline double dist(int i)
{
	return dist(x[i], 0, XN, YN);
}

int main()
{
	int i, j;
	double ans = 1e9;
	scanf("%d%d", &n, &k);
	k--;
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &x[i]);
	}
	double start = x[k];
	
	scanf("%lf%lf", &XN, &YN);
	sort(x, x + n);
	
	if (n == 1)
	{
		ans = dist(x[0], 0, XN, YN);
	}
	else if (k == n)
	{
		ans = min(dist(x[0], 0, XN, YN), dist(x[n - 1], 0, XN, YN)) + x[n - 1] - x[0];
	}
	else
	{
		double tmpAns;
		
		for (i = 0; i < n; i++)
		{
			if (x[i] <= start)
			{
				tmpAns = x[n - 1] - start + x[n - 1] - x[i] + dist(i) + ((i == 0) ? 0 : min(dist(i - 1), dist(0)) + x[i - 1] - x[0]);
				ans = min(ans, tmpAns);
				tmpAns = start - x[i] + x[n - 1] - x[i] + dist(n - 1) + ((i == 0) ? 0 : min(dist(i - 1), dist(0)) + x[i - 1] - x[0]);
				ans = min(ans, tmpAns);
			}
			if (x[i] >= start)
			{
				tmpAns = start - x[0] + x[i] - x[0] + dist(i) + ((i == n - 1) ? 0 : min(dist(i + 1), dist(n - 1)) + x[n - 1] - x[i + 1]);
				ans = min(ans, tmpAns);
				tmpAns = x[i] - start + x[i] - x[0] + dist(0) + ((i == n - 1) ? 0 : min(dist(i + 1), dist(n - 1)) + x[n - 1] - x[i + 1]);
				ans = min(ans, tmpAns);
			}
			
		}
	}
	
	
	printf("%.9lf\n", ans);
	
	
	return 0;
}