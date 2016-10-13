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
const int ITER_NUM = 1e5;
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

inline double fun(double x0, double y0, double z0, int &idx)
{
	double res = 0;
	double tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = sqrDist(x0, y0, z0, i);
		if (tmp > res)
		{
			res = tmp;
			idx = i;
		}
	}
	return res;
}


int main()
{
	int i, j, idx;
	double ansX = 0, ansY = 0, ansZ = 0, res;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
	}
	
	double dt = 1;
	for (j = 0; j < ITER_NUM; j++)
	{
		res = fun(ansX, ansY, ansZ, idx);
		ansX += (x[idx] - ansX) * dt;
		ansY += (y[idx] - ansY) * dt;
		ansZ += (z[idx] - ansZ) * dt;
		
		dt *= 0.999;
	}
	
	printf("%.9lf %.9lf %.9lf\n", ansX, ansY, ansZ);
	//printf("%.9lf %.9lf %.9lf %.9lf\n", ansX, ansY, ansZ, res);
	return 0;
}