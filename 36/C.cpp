#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


const int N = 3005;
const double ERROR = 1e-9;

/*
r/x = R/(x+h) = (R-r)/h = tan

h = (R - r) / tan
*/
struct Bowl
{
	double R;
	double r;
	double h;
	double tan;
};


Bowl a[N];
double h[N];

double calHeight(int i, int j)
{
	double height = 0;
	if (fabs(a[j].tan - a[i].tan) < ERROR)
	{
		if (a[i].r >= a[j].R)
		{
			height = a[j].h;
		}
		else if (a[i].r <= a[j].r)
		{
			height = 0;
		}
		else
		{
			height = (a[i].r - a[j].r) / a[i].tan;
		}
	}
	else if (a[i].tan > a[j].tan)
	{
		if (a[i].r >= a[j].R) // 3
		{
			height = a[j].h;
		}
		else if (a[i].R >= a[j].R) // 2
		{
			height = a[j].h - (a[j].R - a[i].r) / a[i].tan;
		}
		else // 1
		{
			height = (a[i].R - a[j].r) / a[j].tan - a[i].h;
		}
		if (height < 0)
		{
			height = 0;
		}
	}
	else
	{
		if (a[i].r >= a[j].R)
		{
			height = a[j].h;
		}
		else if (a[i].r <= a[j].r)
		{
			height = 0;
		}
		else
		{
			height = (a[i].r - a[j].r) / a[j].tan;
		}
	}
	
	return h[j] + height;
}

double calHeight(int i)
{
	double height = 0;
	for (int j = i - 1; j >= 0; j--)
	{
		height = max(height, calHeight(i, j));
	}
	
	return height;
}

int main()
{
	int n, i;
	double ans;
	
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%lf%lf%lf", &a[i].h, &a[i].r, &a[i].R);
		a[i].tan = (a[i].R - a[i].r) / a[i].h;
	}
	
	h[0] = 0;
	for (i = 1; i < n; i++)
	{
		h[i] = calHeight(i);
	}
	
	for (i = 0, ans = 0; i < n; i++)
	{
		ans = max(ans, h[i] + a[i].h);
	}
	
	fprintf(out, "%.8lf\n", ans);
	
	return 0;
}