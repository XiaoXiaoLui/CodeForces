#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main()
{
	double a, v, l, d, w;
	cin >> a >> v >> l >> d >> w;
	double t = 0;
	double t1 = 0;
	double t2 = 0;
	double s1 = 0;
	double s2 = 0;
	double s3 = 0;
	double v1 = 0;
	
	if (v <= w)
	{
		s1 = v * v / (2.0 * a);
		if (s1 >= l)
		{
			t = sqrt(2.0 * l / a);
		}
		else
		{
			t1 = v / a;
			s2 = l - s1;
			t2 = s2 / v;
			t = t1 + t2;
		}
	}
	else
	{
		s1 = (v * v) / (2.0 * a);
		s2 = (v * v - w * w) / (2.0 * a);
		s3 = (w * w) / (2.0 * a);

		if (s3 >= d)
		{
			if (s1 >= l)
			{
				t = sqrt(2.0 * l / a);
			}
			else
			{
				t1 = v / a;
				s2 = l - s1;
				t2 = s2 / v;
				t = t1 + t2;
			}
		}
		else if (s1 + s2 >= d) // need slow ealier
		{
			v1 = sqrt((2.0 * a * d + w * w) / 2.0);
			t1 = v1 / a + (v1 - w) / a;
			
			s1 = (v * v - w * w) / (2.0 * a);
			if (s1 >= l - d)
			{
				t2 = (-w + sqrt(w*w + 2.0*a*(l-d))) / a;
			}
			else
			{
				t2 = (v - w) / a + (l - d - s1) / v;
			}
			t = t1 + t2;
		}
		else
		{
			t1 = v / a + (v - w) / a + (d - s1 - s2) / v;
			
			s1 = (v * v - w * w) / (2.0 * a);
			if (s1 >= l - d)
			{
				t2 = (-w + sqrt(w*w + 2.0*a*(l-d))) / a;
			}
			else
			{
				t2 = (v - w) / a + (l - d - s1) / v;
			}
			t = t1 + t2;
		}
		
	}
	
	cout.setf(ios::fixed);
	cout << setprecision(5);
	cout << t << endl;
	
}