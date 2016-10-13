#include <cstdio>
#include <cmath>

using namespace std;

const int N = 3;
const double ERR = 1e-7;


double x[N], y[N], r[N];
double ansX, ansY;
double cot[3];

const double DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline double sqr(double a)
{
	return a*a;
}

double calDiffSum(double px, double py)
{
	double ret = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		cot[i] = sqrt(sqr(px - x[i]) + sqr(py - y[i])) / r[i];
	}
	
	for (i = 0; i < N; i++)
	{
		ret += sqr(cot[i] - cot[(i + 1) % N]);
	}
	
	return ret;
}

int main()
{
	int i;
	double diff = 1.0;
	double sum, tmp;
	bool inRange;
	for (i = 0; i < N; i++)
	{
		scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
		ansX += x[i];
		ansY += y[i];
	}
	
	ansX /= N;
	ansY /= N;
	sum = calDiffSum(ansX, ansY);
	
	while (diff > ERR)
	{
		inRange = true;
		for (i = 0; i < 4; i++)
		{
			tmp = calDiffSum(ansX + diff * DIR[i][0], ansY + diff * DIR[i][1]);
			if (tmp < sum)
			{
				ansX += DIR[i][0]*diff;
				ansY += DIR[i][1]*diff;
				inRange = false;
				sum = tmp;
				break;
			}
		}
		if (inRange)
		{
			diff *= 0.7;
		}
	}
	
	
	if (calDiffSum(ansX, ansY) < 1e-6)
	{
		printf("%.6lf %.6lf\n", ansX, ansY);
	}
	
	
	return 0;
}