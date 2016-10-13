#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

struct Wall
{
	Wall(){}
	Wall(double xx, double yy) : x(xx), y(yy)
	{
	}
	double x;
	double y;
	
	bool operator < (const Wall &other) const
	{
		return (x < other.x) || (x == other.x && y < other.y);
	}
};

const int N = 10005;
const int M = 100005;
const double G = 9.8;
const double ERROR = 1e-9;

double a[N];
Wall w[M];

double ansX[N];
double ansY[N];
int srt[N];


bool cmpCannon(const int &i, const int &j) 
{
	return a[i] < a[j];
}

int main()
{
	int n, m, i, j, v, idx;
	double t, x, y, vx, vy;
	scanf("%d%d", &n, &v);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
		srt[i] = i;
	}
	
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%lf%lf", &w[i].x, &w[i].y);
	}
	
	sort(srt, srt + n, cmpCannon);
	
	w[m++] = Wall(1e9, 0); // to simplify coding
	sort(w, w + m);
	
	for (i = 0, j = 0; i < n; i++)
	{
		idx = srt[i];
		vx = cos(a[idx]) * v;
		vy = sin(a[idx]) * v;
		for (; j < m; j++)
		{
			t = w[j].x / vx;
			y = vy * t - G * t * t / 2;
			if (y <= w[j].y)
			{
				if (y >= 0)
				{
					ansX[idx] = w[j].x;
					ansY[idx] = y;
				}
				else
				{
					t = 2 * vy / G;
					x = vx * t;
					ansX[idx] = x;
					ansY[idx] = 0;
				}
				break;
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		printf("%.9lf %.9lf\n", ansX[i], ansY[i]);
	}
	
	printf("\n");
	return 0;
}