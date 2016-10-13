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

const int N = 10;
const int M = 300;

int A, n, k;
int b[N];
int loy[N];
int org[N];
double kp[M];
double ans = 0.0;

double calP(int mask)
{
	int i;
	double res = 1;
	for (i = 0; i < n; i++)
	{
		if ((mask >> i) & 1)
		{
			res *= (double)loy[i] / 100;
		}
		else
		{
			res *= 1.0 - (double)loy[i] / 100;
		}
	}
	if (kp[mask] > 0)
	{
		res *= kp[mask];
	}
	
	return res;
}

double calCurP()
{
	double res = 0;
	for (int i = 0; i < 1 << n; i++)
	{
		res += calP(i);
	}
	
	return res;
}

void dfs(int idx, int r)
{
	double cur = 0;
	int i;
	if (idx == 0)
	{
		loy[idx] = min(100, loy[idx] + 10*r);
		cur = calCurP();
		ans = max(ans, cur);
		loy[idx] = org[idx];
	}
	else
	{
		for (i = 0; i <= r; i++)
		{
			loy[idx] = min(100, loy[idx] + 10*i);
			dfs(idx - 1, r - i);
			loy[idx] = org[idx];
		}
	}
}

int main()
{
	int i, j, c, sum;
	scanf("%d%d%d", &n, &k, &A);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &b[i], &org[i]);
		loy[i] = org[i];
	}
	
	for (i = 0; i < 1 << n; i++)
	{
		for (c = 0, sum = 0, j = 0; j < n; j++)
		{
			if (((i >> j) & 1) == 0)
			{
				c++;
				sum += b[j];
			}
		}
		
		if (2 * c < n)
		{
			kp[i] = -1;
		}
		else
		{
			kp[i] = (double)A / (A + sum);
		}
	}
	
	dfs(n - 1, k);
	
	printf("%.9lf\n", ans);
	return 0;
}