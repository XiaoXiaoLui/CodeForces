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

#define pdd pair<double, double>
#define mpd make_pair<double, double>

typedef long long ll;

const double ERROR = 1e-19;
const int N = 4e4 + 5;

double gx, gy;
double x[N];
double y[N];
double area[N];

inline double sqr(double x)
{
	return x * x;
}

inline double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

inline double dist(int i, int j)
{
	return dist(x[i], y[i], x[j], y[j]);
}

inline double calArea(int i, int j)
{
	double P, A, B, C;
	A = dist(gx, gy, x[i], y[i]);
	B = dist(gx, gy, x[j], y[j]);
	C = dist(i, j);
	P = (A + B + C) / 2;
	
	return sqrt(P * (P - A) * (P - B) * (P - C));
}



/*
y - y1 = (y2 - y1)/(x2 - x1)*(x - x1)
(x2 - x1)y - y1(x2 - x1) + (y1 - y2)x + (y2 - y1)x1 = 0
(x2 - x1)y + (y1 - y2)x - y1x2 + y2x1  = 0

// foot point
x = (  B*B*x0  -  A*B*y0  -  A*C  ) / ( A*A + B*B );
y  =  ( -A*B*x0 + A*A*y0 - B*C  ) / ( A*A + B*B );

// dist
 d = ( Ax0 + By0 + C ) / sqrt ( A*A + B*B );
*/
struct Line
{
	Line() : A(0), B(0), C(0)
	{
	}
	Line(int i, int j)
	{
		A = y[i] - y[j];
		B = x[j] - x[i];
		C = y[j]*x[i] - y[i]*x[j];
		p1 = mpd(x[i], y[i]);
		p2 = mpd(x[j], y[j]);
	}
	void init(int i, int j)
	{
		A = y[i] - y[j];
		B = x[j] - x[i];
		C = y[j]*x[i] - y[i]*x[j];
		p1 = mpd(x[i], y[i]);
		p2 = mpd(x[j], y[j]);
	}
	
	pdd calFootPoint(const pdd &p) const
	{
		double x, y;
		x = (B * B * p.first - A * B * p.second - A * C) / (sqr(A) + sqr(B));
		y = (-A * B * p.first + A * A * p.second - B * C) / (sqr(A) + sqr(B));
		return mpd(x, y);
	}
	
	// dist from p to line
	double dist(const pdd &p) const
	{
		return (A * p.first + B * p.second + C) / sqrt(sqr(A) + sqr(B));
	}
	
	// dist from foot point of p to x1, y1
	double footPointDist(const pdd &p) const
	{
		double res;
		pdd fp = calFootPoint(p);
		res = ::dist(fp.first, fp.second, p1.first, p1.second);
		
		if ((fp.first - p1.first) * (p2.first - p1.first) < -ERROR || (fp.second - p1.second) * (p2.second - p1.second) < -ERROR)
		{
			res = -res;
		}
		return res;
	}
	
	double A;
	double B;
	double C;
	pdd p1;
	pdd p2;
};

inline double calFinalArea(int i, int j, int second, double curAreaSum)
{
	double res = 0;
	Line curLine(i, second);
	pdd fp = curLine.calFootPoint(mpd(x[j], y[j]));
	
	res = dist(fp.first, fp.second, x[i], y[i]) * dist(fp.first, fp.second, x[j], y[j]) / 2;
	res -= curAreaSum - calArea(i, j);
	
	return res;
}


int main()
{
	int n, i, j, k;
	double curAreaSum, curArea;
	double ans = 1e100;
	Line curLine;
	pdd curPoint, nextPoint;
	scanf("%d", &n);
	gx = gy = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf", &x[i], &y[i]);
		gx += x[i];
		gy += y[i];
	}
	gx /= n;
	gy /= n;
	
	
	// direction 1, 0, 1, ..., n-1
	for (i = 0; i < n; i++)
	{
		j = (i + 1) % n;
		area[j] = calArea(i, j);
	}
	
	for (i = 0, j = 1, curAreaSum = area[1]; i < n; i++)
	{
		curLine.init(i, (i + 1) % n);
		while (1)
		{
			curPoint = mpd(x[j], y[j]);
			nextPoint = mpd(x[(j + 1) % n], y[(j + 1) % n]);
			if (curLine.footPointDist(nextPoint) >= curLine.footPointDist(curPoint))
			{
				j = (j + 1) % n;
				curAreaSum += area[j];
			}
			else
			{
				break;
			}
		}
		curArea = calFinalArea(i, j, (i + 1) % n, curAreaSum);
		if (curArea < ans)
		{
			ans = curArea;
		}
		curAreaSum -= area[(i + 1) % n];
	}
	
	// direction 2, n-1, n-2, ..., 0
	for (i = n - 1; i >= 0; i--)
	{
		j = (i - 1 + n) % n;
		area[j] = calArea(i, j);
	}
	
	for (i = n - 1, j = n - 2, curAreaSum = area[n - 2]; i >= 0; i--)
	{
		curLine.init(i, (i - 1 + n) % n);
		while (1)
		{
			curPoint = mpd(x[j], y[j]);
			nextPoint = mpd(x[(j - 1 + n) % n], y[(j - 1 + n) % n]);
			if (curLine.footPointDist(nextPoint) >= curLine.footPointDist(curPoint))
			{
				j = (j - 1 + n) % n;
				curAreaSum += area[j];
			}
			else
			{
				break;
			}
		}
		curArea = calFinalArea(i, j, (i - 1 + n) % n, curAreaSum);
		if (curArea < ans)
		{
			ans = curArea;
		}
		curAreaSum -= area[(i - 1 + n) % n];
	}
	
	printf("%.15lf\n", ans);
	return 0;
}