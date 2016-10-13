#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 10005;
int x[N];
int y[N];

int main()
{
	int n, w, u, v, i, left, right, up, down;
	double ans = 0;
	scanf("%d%d%d%d", &n, &w, &v, &u);
	
	left = right = up = down = -1;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		if (left == -1 || x[i] < x[left] || (x[i] == x[left] && y[i] > x[left]))
		{
			left = i;
		}
		if (up == -1 || y[i] > y[up] || (y[i] == y[up] && x[i] < x[up]))
		{
			up = i;
		}
		if (x[i] > 0 && (right == -1 || x[i] > x[right] || (x[i] == x[right] && y[i] < y[right])))
		{
			right = i;
		}
		if (x[i] > 0 && (down == -1 || y[i] < y[down] || (y[i] == y[down] && x[i] > x[down])))
		{
			down = i;
		}
	}
	
	if (right == -1)
	{
		printf("%.9lf\n", (double)w / u);
	}
	
	bool ok = true;
	int offset = 0;
	double curTime, t, curY;
	if (x[left] >= 0)
	{
		t = (double)x[left] / v;
		curY = u * t;
		
		if (curY < y[left])
		{
			ok = false;
		}
		
		offset = x[left];
		curTime = t;
		for (i = left; i != (up - 1 + n) % n && ok; i = (i - 1 + n) % n)
		{
			t = (double)(x[i] - offset) / v;
			curY += u * t;
			if (curY < y[i])
			{
				ok = false;
			}
			
			curTime += t;
			offset = x[i];
		}
		
		if (ok)
		{
			ans = (double) w / u;
		}
	}
	else
	{
		ok = false;
	}
	
	if (!ok)
	{
		 t = (double)x[down] / v;
		 curY = min(u * t, (double)y[down]);
		 offset = x[down];
		 curTime = t;
		 for (i = down; i != (right + 1) % n; i = (i + 1) % n)
		 {
			 t = (double)(x[i] - offset) / v;
			 curY = min(curY + u * t, (double)y[i]);
			 curTime += t;
			 offset = x[i];
		 }
		 
		 ans = curTime + (w - curY) / u;
	}
	
	
	printf("%.9lf\n", ans);
	return 0;
}