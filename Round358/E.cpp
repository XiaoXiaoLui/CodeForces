#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"
//#define LLD "%I64d"

typedef long long ll;

struct Point
{
	ll x;
	ll y;
	
	Point(){}
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	
	Point operator + (const Point &other) const
	{
		return Point(x + other.x, y + other.y);
	}
	
	Point operator - (const Point &other) const
	{
		return Point(x - other.x, y - other.y);
	}
	
	ll sqrLen() const
	{
		return x*x + y*y;
	}	
	
	bool operator < (const Point &other) const
	{
		return x < other.x || x == other.x && y < other.y;
	}
};

const int N = 5005;
Point p[N];
Point convex[N];
Point minP(1e9, 1e9);


ll calCross(const Point &p1, const Point &p2)
{
	return p2.y * p1.x - p1.y * p2.x;
}

bool lessVector(const Point &a, const Point &b)
{
		Point p1, p2;
		p1 = a - minP;
		p2 = b - minP;
		ll res = calCross(p1, p2);
		return res > 0 || res == 0 && p1.sqrLen() < p2.sqrLen();
}

ll getArea(const Point &p1, const Point &p2, const Point p3)
{
	return calCross(p1 - p2, p1 - p3);
}

inline void getPoint(Point &a, Point &b, Point &c, int i, int j, int k, int n)
{
	a = convex[i % n];
	b = convex[j % n];
	c = convex[k % n];
}


int main()
{
	int n, m, i, j, k;
	ll S;
	
	scanf("%d" LLD, &n, &S);
	for (i = 0; i < n; i++)
	{
		scanf(LLD LLD, &p[i].x, &p[i].y);
		if (p[i] < minP)
		{
			minP = p[i];
		}
	}
	
	sort(p, p + n, lessVector);
	
	m = 0;
	for (i = 0; i < n; i++)
	{
		while (m >= 2 && calCross(p[i] - convex[m - 1], p[i] - convex[m - 2]) >= 0)
		{
			m--;
		}
		convex[m++] = p[i];
	}
	
	n = m;
	ll maxArea = 0;
	ll cur;
	Point a, b, c;
	Point ans1, ans2, ans3;
	bool changed = false;
	for (i = 0, j = 1, k = 2; i < n - 2; i++)
	{
		//j = i + 1;
		//k = i + 2;
		if (i == j)
		{
			j++;
		}
		if (j == k)
		{
			k++;
		}
		while (k < i + n)
		{
			getPoint(a, b, c, i, j, k, n);
			cur = getArea(a, b, c);
			changed = false;
			while (k < i + n)
			{
				getPoint(a, b, c, i, j, k + 1, n);
				if (getArea(a, b, c) <= cur)
				{
					break;
				}
				cur = getArea(a, b, c);
				k++;
				changed = true;
			}
			
			while (j < k)
			{
				getPoint(a, b, c, i, j + 1, k, n);
				if (getArea(a, b, c) <= cur)
				{
					break;
				}
				cur = getArea(a, b, c);
				j++;
				changed = true;
			}
			

			
			getPoint(a, b, c, i, j, k, n);
			if (cur > maxArea)
			{
				maxArea = cur;
				ans1 = a; 
				ans2 = b;
				ans3 = c;
			}
			if (!changed)
			{
				break;
			}
		}
	}
	
	Point p1 = ans1;
	Point p2 = ans2;
	Point p3 = ans3;
	ans1 = p1 + p2 - p3;
	ans2 = p1 + p3 - p2;
	ans3 = p2 + p3 - p1;
	
	printf(LLD " " LLD "\n" LLD " " LLD "\n" LLD " " LLD "\n", ans1.x, ans1.y, ans2.x, ans2.y, ans3.x, ans3.y);
	return 0;
}