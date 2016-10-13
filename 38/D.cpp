#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 105;
const double ERROR = 1e-9;

struct Point
{
	Point(){}
	Point(double a, double b) : x(a), y(b)
	{
	}
	double x;
	double y;	
};

struct Brick
{
	Point p1;
	Point p2;
	double m;
	Point center;
	void build(double x1, double x2, double y1, double y2)
	{
		p1 = Point(min(x1, x2), min(y1, y2));
		p2 = Point(max(x1, x2), max(y1, y2));
		m = (p2.x - p1.x) * (p2.x - p1.x) * (p2.x - p1.x);
		center.x = (x1 + x2) / 2;
		center.y = (y1 + y2) / 2;
	}
	
	bool containPoint(const Point &p) const
	{
		return (p.x  >= p1.x && p.x <= p2.x && p.y >= p1.y && p.y <= p2.y);
	}
};

Brick b[N];

bool balance(int top)
{
	bool res = true;
	int i;
	Point curCenter = Point(0, 0);
	double curMass = 0;
	for (i = top; i >= 1; i--)
	{
		curCenter.x = (curMass * curCenter.x + b[i].center.x * b[i].m) / (curMass + b[i].m);
		curCenter.y = (curMass * curCenter.y + b[i].center.y * b[i].m) / (curMass + b[i].m);
		curMass += b[i].m;
		if (!b[i - 1].containPoint(curCenter))
		{
			res = false;
			break;
		}
	}
	return res;
}

int main()
{
	int n, x1, x2, y1, y2, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		b[i].build(x1, x2, y1, y2);
	}
	
	int ans;
	for (i = 1;  i < n; i++)
	{
		if (!balance(i))
		{
			break;
		}
	}
	ans  = i;
	
	printf("%d\n", ans);
	return 0;
}