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

const int N = 105;
const double ERROR = 1e-8;
const double EE = 2.7182818284590452;


int n;
int K;
int epison;
double d[N];
double dp[N][N];
double a[N];

inline double sqr(double x)
{
	return x*x;
}

inline double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

inline double calP(double r, double dis)
{
	return pow(EE, 1 - sqr(dis) / sqr(r));
}

bool pass(double r)
{
	bool res = true;
	int firstIndex = upper_bound(d, d + n, r) - d;
	
	if (firstIndex >= K)
	{
		return true;
	}
	
	int i, j, m, k;
	double sucP;
	m = n - firstIndex;
	k = K - firstIndex;
	for (j = 0, i = firstIndex; i < n; i++, j++)
	{
		a[j] = d[i];
	}
	
	fill((double*)dp, (double*)dp + N*N, 0);
	dp[0][0] = 1;
	for (i = 1; i <= m; i++)
	{
		dp[i][0] = 1;
		for (j = 1; j <= min(k, i); j++)
		{
			sucP = calP(r, a[i - 1]);
			dp[i][j] = sucP * dp[i - 1][j - 1] + (1 - sucP) * dp[i - 1][j];
		}
	}
	
	if (dp[m][k] >= (1000.0 - epison) / 1000)
	{
		res = true;
	}
	else
	{
		res = false;
	}
	
	
	return res;
}

int main()
{
	double x0, y0, x, y, ans, left, right, mid;
	int i;
	
	scanf("%d%d%d", &n, &K, &epison);
	scanf("%lf%lf", &x0, &y0);
	
	left = 0;
	right = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf", &x, &y);
		d[i] = dist(x, y, x0, y0);
		right = max(right, d[i]);
	}
	sort(d, d + n);
	
	while (right - left > ERROR)
	{
		mid = (right + left) / 2;
		if (pass(mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	
	printf("%.9lf\n", left);
	return 0;
}