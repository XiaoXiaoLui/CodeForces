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
//#define LLD "%I64d"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1005;
double p[N];
double dp[N][N];

inline double calP(ll left, ll right)
{
	int i;
	ll goodCount = 0, tmp, exp10;
	pii leftMsd, rightMsd;
	leftMsd = mp(0, 0);
	rightMsd = mp(0, 0);
	
	tmp = left;
	while (tmp >= 10)
	{
		tmp /= 10;
		leftMsd.first++;
	}
	leftMsd.second = tmp;
	
	tmp = right;
	while (tmp >= 10)
	{
		tmp /= 10;
		rightMsd.first++;
	}
	rightMsd.second = tmp;
	
	for (i = 0, exp10 = 1; i < leftMsd.first; i++)
	{
		exp10 *= 10;
	}
	
	if (rightMsd.first == leftMsd.first)
	{
		if (leftMsd.second == 1)
		{
			goodCount += min(2*exp10, right + 1) - left;
		}
	}
	else
	{	
		if (leftMsd.second == 1)
		{
			goodCount += 2*exp10 - left;
		}
		
		for (i = leftMsd.first + 1; i < rightMsd.first; i++)
		{
			exp10 *= 10;
			goodCount += exp10;
		}
		exp10 *= 10;
		
		goodCount += min(right + 1, 2 * exp10)- exp10;
		
	}
	
	return (double)goodCount / (right - left + 1);
}

int main()
{
	int n, i, j, K, needNum, end;
	ll left, right;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf(LLD LLD, &left, &right);
		p[i] = calP(left, right);
	}
	scanf("%d", &K);
	for (i = 0; i <= n; i++)
	{
		if (i * 100 >= K * n)
		{
			break;
		}
	}
	needNum = i;
	
	dp[0][0] = 1;
	for (i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
		end = min(needNum, i);
		for (j = 1; j <= end; j++)
		{
			dp[i][j] = p[i - 1] * dp[i - 1][j - 1] + (1 - p[i - 1]) * dp[i - 1][j];
		}
	}
	
	
	printf("%.11lf\n", dp[n][needNum]);
	return 0;
}