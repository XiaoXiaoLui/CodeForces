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

const int N = 1e7 + 5;
int mark[N];

ll upSqrt(ll a)
{
	ll res = max((ll)sqrt(a) - 1, 0LL);
	while (res * res < a)
	{
		res++;
	}
	
	return res;
}

ll lowSqrt(ll a)
{
	ll res = max((ll)sqrt(a) - 1, 0LL);
	
	while ((res + 1) * (res + 1) <= a)
	{
		res++;
	}
	
	return res;
}


int main()
{
	int n, m, i;
	ll b, left, right, leftSqrt, rightSqrt, ans, maxC;
	scanf("%d%d", &n, &m);
	
	ans = 0;
	for (b = 1; b <= n; b++)
	{
		maxC = min((ll)m, b*b);
		right = b*b - 1;
		left = b*b - maxC;
		leftSqrt = upSqrt(left);
		rightSqrt = lowSqrt(right);
		
		ans += ((right - left + 1) - (rightSqrt - leftSqrt + 1)) * 2;
		
		right = -(leftSqrt - b);
		left = -(rightSqrt - b);
		mark[(int)left] += 1;
		mark[(int)right + 1] += -1;
		
		right = -(-rightSqrt - b);
		left = -(-leftSqrt - b);
		mark[(int)left] += 1;
		mark[(int)right + 1] += -1;
	}
	
	ll sum = 0;
	for (i = 1; i <= 2*n; i++)
	{
		sum += mark[i];
		if (sum > 0)
		{
			ans++;
		}
	}
	
	
	printf(LLD"\n", ans);
	return 0;
}


/*
x^2 + 2bx + c = 0
(x+b)^2 = b^2 - c

x = +-sqrt(b^2 - c) - b
*/