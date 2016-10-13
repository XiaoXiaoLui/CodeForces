#include <iostream>
#include <cmath>

using namespace std;

#define ERROR 0.0001



struct Position
{
	double x;
	double y;
};

double dist(Position p1, Position p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}


// http://blog.csdn.net/whu_zxl/article/details/9456259
void calCommonPoint(Position oa, Position ob, double ra, double rb, Position &p1, Position &p2)
{
	double d = dist(oa, ob);
	double a = (ra*ra - rb*rb + d*d) / (2 * d);
	double h = sqrt(abs(ra * ra - a * a));
	
	double x2 = oa.x + a * (ob.x - oa.x ) / d;
	double y2 = oa.y + a * (ob.y - oa.y) / d;
	
	p1.x = x2 + h * (ob.y - oa.y) / d;
	p1.y = y2 - h * (ob.x - oa.x) / d;
	
	p2.x = x2 - h * (ob.y - oa.y) / d;
	p2.y = y2 + h * (ob.x - oa.x) / d;
}

bool hasCommonArea(Position oa, Position ob, Position oc, double ra, double rb, double rc)
{
	double AB = dist(oa, ob);
	double BC = dist(ob, oc);
	double AC = dist(oa, oc);
	Position p1, p2;

	if (ra < 0 || rb < 0 || rc < 0 || AB > ra + rb || BC > rb + rc || AC > ra + rc)
	{
		return false;
	}
	
	int ret = false;
	
	if (AB <= abs(ra - rb))
	{
		if (ra > rb && BC <= rb + rc)
		{
			ret = true;
		}
		else if (rb > ra && AC <= ra + rc)
		{
			ret = true;
		}
	}
	else
	{
		calCommonPoint(oa, ob, ra, rb, p1, p2);
		
		if (dist(p1, oc) <= rc)
		{
			ret = true;
		}
		if (dist(p2, oc) <= rc)
		{
			ret = true;
		}
	}
	
	if (BC <= abs(rb - rc))
	{
		if (rb > rc && AC <= ra + rc)
		{
			ret = true;
		}
		else if (rc > rb && AB <= ra + rb)
		{
			ret = true;
		}
	}
	else
	{
		calCommonPoint(ob, oc, rb, rc, p1, p2);
		if (dist(p1, oa) <= ra)
		{
			ret = true;
		}
		if (dist(p2, oa) <= ra)
		{
			ret = true;
		}
	}
	
	if (AC <= abs(ra - rc))
	{
		if (ra > rc && BC <= rc + rb)
		{
			ret = true;
		}
		if (rc > ra && AB <= ra + rb)
		{
			ret = true;
		}
	}
	else
	{
		calCommonPoint(oa, oc, ra, rc, p1, p2);
		if (dist(p1, ob) <= rb)
		{
			ret = true;
		}
		if (dist(p2, ob) <= rb)
		{
			ret = true;
		}
	}
	
	return ret;
}


int main()
{
	double t1, t2;
	double AB, BC, AC, ra, rb, rc, ans;
	double left = 0, right = 100, mid;
	Position posCinema;
	Position posShop;
	Position posHome;
	
	cin >> t1 >> t2;
	cin >> posCinema.x >> posCinema.y;
	cin >> posHome.x >> posHome.y;
	cin >> posShop.x >> posShop.y;
	
	AB = dist(posCinema, posShop);
	AC = dist(posCinema, posHome);
	BC = dist(posShop, posHome);
	
	double T1 = AB + BC + t1;
	double T2 = AC + t2;
	
	mid = 51;
	//hasCommonArea(posCinema, posShop, posHome, mid, AB + t1 - mid, AC + t2 - mid);
	
	if (AB + BC <= T2)
	{
		if (T1 <= T2)
		{
			ans = T1;
		}
		else
		{
			ans = T2;
		}
	}
	else
	{
		
		while (right - left > ERROR)
		{
			mid = (right + left) / 2;
			if (hasCommonArea(posCinema, posShop, posHome, mid, AB + t1 - mid, AC + t2 - mid))
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		
		}
		
		ans = left;
		if (ans == 0 && t1 == 0 && t2 == 8)
		{
			cout << left << " " << right;
		}
	}
	
	
	cout.setf(ios::fixed);
	cout.precision(4);
	cout << ans << endl;
	
	
	return 0;
}