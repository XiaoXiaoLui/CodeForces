#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double ERROR = 1e-8;

/*
y - y1 = (y2-y1)/(x2-x1)*(x-x1)
(x2-x1)*(y-y1) = (y2-y1)*(x-x1)
(y1-y2)x + (x2-x1)*y + (x1-x2)*y1 + x1*(y2-y1)

*/
struct Segment
{
	double x1;
	double y1;
	double x2;
	double y2;
	double a;
	double b;
	double c;
	
	Segment(){}
	Segment(double x1, double y1, double x2, double y2)
	{
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
		calABC();
	}
	
	void calABC()
	{
		a = y1 - y2;
		b = x2 - x1;
		c = (x1 - x2) * y1 + x1 * (y2 - y1);
	}

	double calRes(double x, double y) const
	{
		return (a*x + b*y + c);
	}
	
	int inSegment(double x, double y) const
	{
		double p = calRes(x, y);
		if (abs(p) < ERROR)
		{
			if (abs(x1 - x2) > ERROR)
			{
				if (x < min(x1, x2) || x > max(x1, x2))
				{
					return 0;;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				if (y < min(y1, y2) || y > max(y1, y2))
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		
		return 0;
	}
	
	/*
	£¨a-£¨2A*£¨Aa+Bb+C£©£©/(A*A+B*B),b-£¨2B*(Aa+Bb+C£©£©/(A*A+B*B))
	*/
	void getReflect(double x, double y, double &ansX, double &ansY) const
	{
		ansX = x - 2*a*(a*x + b*y + c) / (a*a + b*b);
		ansY = y - 2*b*(a*x + b*y + c) / (a*a + b*b);
	}		
};


/*
result:
0: no common point
1: has 1 common point
2: seg2 is in seg1 or seg1 is in seg2

*/
int judge(const Segment &seg1, const Segment &seg2)
{
	if ((seg1.inSegment(seg2.x1, seg2.y1) ^ seg1.inSegment(seg2.x2, seg2.y2)) || (seg2.inSegment(seg1.x1, seg1.y1) ^ seg2.inSegment(seg1.x2, seg1.y2)))
	{
		return 1;
	}
	
	
	double p1, p2, a, b, c, d;
	a = seg1.calRes(seg2.x1, seg2.y1);
	b = seg1.calRes(seg2.x2, seg2.y2);
	c = seg2.calRes(seg1.x1, seg1.y1);
	d = seg2.calRes(seg1.x2, seg1.y2);
	p1 = a * b;
	p2 = c * d;
	
	if (abs(p1) < ERROR && abs(p2) < ERROR && 
		(seg1.inSegment(seg2.x1, seg2.y1) && seg1.inSegment(seg2.x2, seg2.y2) || seg2.inSegment(seg1.x1, seg1.y1) && seg2.inSegment(seg1.x2, seg1.y2)))
	{
		return 2;
	}
	
	// p < 0 || p == 0
	if ((p1 < 0 && abs(p1) > ERROR) && (p2 < 0 && abs(p2) > ERROR))
	{
		return 1;
	}
	
	return 0;
}

/*
a1*x + b1y + c1 = 0
a2*x + b2y + c2 = 0
a1a2x + b1a2y + c1a2 = 0
a1a2x + b2a1y + c2a1 = 0
y = (c2a1 - c1a2) / (b1a2 - b2a1)
x = (c2b1 - c1b2) / (b2a1 - b1a2)
*/
void solve(const Segment &seg1, const Segment &seg2, double &x, double &y)
{
	x = (seg2.c * seg1.b - seg1.c * seg2.b) / (seg2.b * seg1.a - seg1.b * seg2.a);
	y = (seg2.c * seg1.a - seg1.c * seg2.a) / (seg1.b * seg2.a - seg2.b * seg1.a);
}

double sqr(double x)
{
	return x*x;
}

int main()
{
	int xw1, xw2, yw1, yw2, xm1, ym1, xm2, ym2, xv, yv, xp, yp;
	double xi, yi, xr, yr;
	bool ans = false;
	
	/*
	scanf("%lf%lf", &xv, &yv);
	scanf("%lf%lf", &xp, &yp);
	scanf("%lf%lf%lf%lf", &xw1, &yw1, &xw2, &yw2);
	scanf("%lf%lf%lf%lf", &xm1, &ym1, &xm2, &ym2);
	*/
	scanf("%d%d", &xv, &yv);
	scanf("%d%d", &xp, &yp);
	scanf("%d%d%d%d", &xw1, &yw1, &xw2, &yw2);
	scanf("%d%d%d%d", &xm1, &ym1, &xm2, &ym2);
	
	Segment segWall(xw1, yw1, xw2, yw2);
	Segment segMirror(xm1, ym1, xm2, ym2);
	Segment seg1(xv, yv, xp, yp);
	
	if (judge(segWall, seg1) == 0 && judge(segMirror, seg1) != 1)
	{
		ans = true;
	}
	
	segMirror.getReflect(xp, yp, xr, yr);
	
	if (!ans && sqr(xr - xv) + sqr(yr - yv) > ERROR && sqr(xr - xp) + sqr(yr - yp) > ERROR)
	{
		Segment seg2(xv, yv, xr, yr);
		if (judge(segMirror, seg2) == 1)
		{
			solve(segMirror, seg2, xi, yi);
			Segment seg3(xv, yv, xi, yi);
			Segment seg4(xp, yp, xi, yi);
			
			if (!judge(segWall, seg3) && !judge(segWall, seg4))
			{
				ans = true;
			}
		}	
	}
	
	
	printf("%s\n", ans ? "YES" : "NO");
	
	return 0;
}