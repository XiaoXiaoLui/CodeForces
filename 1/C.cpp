#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>

//#define N 1000000
#define PI 3.141592653

//error 
#define ERROR 0.02

/*
long long lgcd(long long a, long long b)
{
	long long c = a;
	while (a % b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	
	return b;
}*/

double getGcd(double a, double b)
{
	double base = a;
	double tmp = 0.0;
	
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	
	// a is bigger than b
	while ((a - b) / base > ERROR)
	{
		tmp = a - b;
		
		if (tmp  > b)
		{
			a = tmp;
		}
		else
		{
			a = b;
			b = tmp;
		}
	}
	
	return a;
}

int getSideNum(double fSide1, double fSide2, double fSide3, double fRadius)
{
	double fSideLen = 0;
	double fAng1, fAng2, fAng3;
	int n = 0;
	
	fAng1 = 2 * asin(0.5 * fSide1 / fRadius);
	fAng2 = 2 * asin(0.5 * fSide2 / fRadius);
	fAng3 = 2 * asin(0.5 * fSide3 / fRadius);
	
	/*
	long long lAng1 = (long long)(fAng1 * N);
	long long lAng2 = (long long)(fAng2 * N);
	long long lAng3 = (long long)(fAng3 * N);
	
	long long lGcd1 = lgcd(lAng1, lAng2);
	long long lGcdFinal = lgcd(lGcd1, lAng3);
	
	*pN = (int)(2.0*PI / lGcdFinal + 0.1);*/
	double fGcd1 = getGcd(fAng1, fAng2);
	double fGcd2 = getGcd(fGcd1, fAng3);
	double fAng = getGcd(fGcd2, 2.0*PI);
	n = (int)(2.0*PI / fAng + 0.1);
	
	
	//*pfHigh = fRadius * cos(fAng / 2);
	//fSideLen = 2 * fRadius * sin(fAng / 2);;
	
	return n;
	
}

double distXY(double x1, double y1, double x2, double y2)
{
	double a, b;
	a = x1 - x2;
	b = y1 - y2;
	
	return sqrt(a*a + b*b);
}

double getArea(double fRadius, int n)
{
	double fArea = 0.5 * fRadius * fRadius * sin(2.0*PI/n) * n;
	
	return fArea;
}

int main()
{
	double fX1, fX2, fX3, fY1, fY2, fY3, fCenterX, fCenterY, fRadius, fSide1, fSide2, fSide3, fArea;
	int n = 0;
	
	scanf("%lf%lf%lf%lf%lf%lf", &fX1, &fY1, &fX2, &fY2, &fX3, &fY3);
	//printf("%lf %lf %lf %lf %lf %lf", fX1, fY1, fX2, fY2, fX3, fY3);
	fCenterX = 0.5 * ((fY3 - fY1)*(fX2*fX2 + fY2*fY2 - fX1*fX1 - fY1*fY1) - (fY2 - fY1)*(fX3*fX3 + fY3*fY3 - fX1*fX1 - fY1*fY1))
				/ ((fY3 - fY1)*(fX2 - fX1) - (fY2 - fY1)*(fX3 - fX1));
	fCenterY = 0.5 * ((fX3 - fX1)*(fX2*fX2 + fY2*fY2 - fX1*fX1 - fY1*fY1) - (fX2 - fX1)*(fX3*fX3 + fY3*fY3 - fX1*fX1 - fY1*fY1))
				/ ((fX3 - fX1)*(fY2 - fY1) - (fX2 - fX1)*(fY3 - fY1));
				
	fSide1 = distXY(fX1, fY1, fX2, fY2);
	fSide2 = distXY(fX2, fY2, fX3, fY3);
	fSide3 = distXY(fX3, fY3, fX1, fY1);
				
	fRadius = distXY(fCenterX, fCenterY, fX1, fY1);
	
	//printf("radius=%lf, x=%lf, y=%lf\n", fRadius, fCenterX, fCenterY);
	n = getSideNum(fSide1, fSide2, fSide3, fRadius);
	
	

	
	fArea = getArea(fRadius, n);
	
	printf("%.6lf", fArea);
	return 0;
}