#include <cstdio>
#include <cmath>

using namespace std;

struct Point
{
	double x;
	double y;
	
	bool operator == (const Point &other) const
	{
		return x == other.x && y == other.y;
	}
};

struct Line
{
	Point p1;
	Point p2;
	
};


template <class T>
void mySwap(T &t1, T &t2)
{
	T tmp;
	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

inline bool check(Line &line1, Line &line2)
{
	Point tmp;
	bool ret = false;
	if (line1.p1 == line2.p1)
	{
		ret = true;
	}
	else if (line1.p1 == line2.p2)
	{
		ret = true;
		mySwap(line2.p1, line2.p2);
	}
	else if (line1.p2 == line2.p1)
	{
		ret = true;
		mySwap(line1.p1, line1.p2);
	}
	else if (line1.p2 == line2.p2)
	{
		ret = true;
		mySwap(line1.p1, line1.p2);
		mySwap(line2.p1, line2.p2);
	}
	
	return ret;
}

inline double dist(const Point &p1, const Point &p2)
{
	return (sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)));
}

bool angleMeet(const Line &line1, const Line &line2)
{
	bool ret = true;
	double d1, d2, d3, cosA, angle;
	
	d1 = dist(line1.p1, line1.p2);
	d2 = dist(line2.p1, line2.p2);
	d3 = dist(line1.p2, line2.p2);
	
	cosA = (d1*d1 + d2*d2 - d3*d3) / (2*d1*d2);
	
	if (cosA > 0 && cosA < 1)
	{
		ret = true;
	}
	else
	{
		ret = false;
	}
	
	return ret;
}

inline bool pointMeetLine(Point p, Line line)
{
	bool ret = false;
	if ((p.y - line.p1.y)*(line.p2.x - line.p1.x) == (line.p2.y - line.p1.y)*(p.x - line.p1.x))
	{
		double d1, d2;
		d1 = dist(p, line.p1);
		d2 = dist(p, line.p2);
		
		if (d1 > d2)
		{
			mySwap(d1, d2);
		}
		
		if (d1 / d2 >= 0.25)
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
	}
	else
	{
		ret = false;
	}
	
	return ret;
}

Line a, b, c;

// try to make a & b has common point (a.x1, ay1), c.x1 in a, c.x2 in b
bool handle()
{
	bool ok = true;
	if (check(a, b))
	{
	}
	else if (check(a, c))
	{
		mySwap(b, c);
	}
	else if (check(b, c))
	{
		mySwap(a, c);
	}
	else
	{
		return false;
	}
	
	if (!angleMeet(a, b))
	{
		return false;
	}
	
	if (pointMeetLine(c.p1, a) && pointMeetLine(c.p2, b) || pointMeetLine(c.p2, a) && pointMeetLine(c.p1, b))
	{
		ok = true;
	}
	else
	{
		ok = false;
	}
	
	return ok;
	
}

int main()
{
	int n, i;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%lf%lf%lf%lf", &a.p1.x, &a.p1.y, &a.p2.x, &a.p2.y);
		scanf("%lf%lf%lf%lf", &b.p1.x, &b.p1.y, &b.p2.x, &b.p2.y);
		scanf("%lf%lf%lf%lf", &c.p1.x, &c.p1.y, &c.p2.x, &c.p2.y);
		
		if (handle())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	
	return 0;
}