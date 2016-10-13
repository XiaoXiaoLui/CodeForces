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

//#define DEBUG

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 23;
const int M = 1 << 20;
const double ERROR = 1e-11;

double p[N];
double dp[M];
double ans[N];

inline int bitCount(int a)
{
	int res = 0;
	while (a)
	{
		if (a & 1)
		{
			res++;
		}
		a >>= 1;
	}
	return res;
}

// for debug, counting how many total operations
int opCount = 0;
inline void debugCount()
{
#ifdef DEBUG
	opCount++;
#endif 
}

inline void debugPrint()
{
#ifdef DEBUG
	printf("%d\n", opCount);
#endif
}

int main()
{
	int n, k, i, j, l, nozeroCount;
	scanf("%d%d", &n, &k);
	for (i = 0, nozeroCount = 0; i < n; i++)
	{
		scanf("%lf", &p[i]);
		if (p[i] > ERROR)
		{
			nozeroCount++;
		}
	}
	
	k = min(k, nozeroCount);
	
	double sum;
	dp[0] = 1.0;
	
	
	for (l = 0; l < 1 << n; l++)
	{
		for (i = 0, sum = 0.0; i < n; i++)
		{
			if (((l >> i) & 1) == 0)
			{
				sum += p[i];
				debugCount();
			}
		}
		for (i = 0; i < n; i++)
		{
			if (((l >> i) & 1) == 0)
			{
				if (sum > ERROR)
				{
					dp[l | (1 << i)] += dp[l] * p[i] / sum;
				}
				debugCount();
			}
		}
	}
	
	for (l = 0; l < 1 << n; l++)
	{
		if (bitCount(l) == k)
		{
			for (i = 0; i < n; i++)
			{
				if ((l >> i) & 1)
				{
					ans[i] += dp[l];
					debugCount();
				}
			}
		}
	}
	
	debugPrint();
	
	for (i = 0; i < n; i++)
	{
		printf("%.9lf ", ans[i]);
	}

	printf("\n");
	return 0;
}