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

const int N = 105;
double ERROR = 1e-7;

int n;
double x[N];
double y[N];
double z[N];


inline double mysqr(double x)
{
	return x*x;
}

inline double sqrDist(double x0, double y0, double z0, int idx)
{
	return mysqr(x0 - x[idx]) + mysqr(y0 - y[idx]) + mysqr(z0 - z[idx]);
}

inline double fun(double x0, double y0, double z0)
{
	double res = 0;
	for (int i = 0; i < n; i++)
	{
		res = max(res, sqrDist(x0, y0, z0, i));
	}
	return res;
}

inline double calXY(double initX, double initY, double &resZ)
{
	double left = -1e4, right = 1e4, mid1, mid2;
	double resLeft, resRight, resMid1, resMid2;
	resLeft = fun(initX, initY, left);
	resRight = fun(initX, initY, right);
	while (right - left > ERROR)
	{
		mid1 = (2*left + right) / 3;
		mid2 = (left + 2*right) / 3;
		resMid1 = fun(initX, initY, mid1);
		resMid2 = fun(initX, initY, mid2);
		
		if (resMid1 < resMid2)
		{
			right = mid2;
			resRight = resMid2;
		}
		else
		{
			left = mid1;
			resLeft = resMid1;
		}
	}
	
	resZ = left;
	return fun(initX, initY, resZ);
}

inline double calX(double initX, double &resY, double &resZ)
{
	double left = -1e4, right = 1e4, mid1, mid2;
	double resLeft, resRight, resMid1, resMid2;
	resLeft = calXY(initX, left, resZ);
	resRight = calXY(initX, right, resZ);
	while (right - left > ERROR)
	{
		mid1 = (2*left + right) / 3;
		mid2 = (left + 2*right) / 3;
		resMid1 = calXY(initX, mid1, resZ);
		resMid2 = calXY(initX, mid2, resZ);
		
		if (resMid1 < resMid2)
		{
			right = mid2;
			resRight = resMid2;
		}
		else
		{
			left = mid1;
			resLeft = resMid1;
		}
	}
	
	resY = left;
	return calXY(initX, resY, resZ);
}

inline double cal(double &resX, double &resY, double &resZ)
{
	double left = -1e4, right = 1e4, mid1, mid2;
	double resLeft, resRight, resMid1, resMid2;
	resLeft = calX(left, resY, resZ);
	resRight = calX(right, resY, resZ);
	
	bool need1 = true, need2 = true;
	while (right - left > ERROR)
	{
		mid1 = (2*left + right) / 3;
		mid2 = (left + 2*right) / 3;
		if (need1) resMid1 = calX(mid1, resY, resZ);
		if (need2) resMid2 = calX(mid2, resY, resZ);
		
		if (resMid1 < resMid2)
		{
			right = mid2;
			resRight = resMid2;
		}
		else
		{
			left = mid1;
			resLeft = resMid1;
		}
	}
	
	resX = left;
	return calX(resX, resY, resZ);
}


int main()
{
	int i, j, r, s, t;
	double ansX = 0, ansY = 0, ansZ = 0, res;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
	}

	res = cal(ansX, ansY, ansZ);
	
	printf("%.9lf %.9lf %.9lf\n", ansX, ansY, ansZ);
	//printf("%.9lf %.9lf %.9lf %.9lf\n", ansX, ansY, ansZ, res);
	return 0;
}