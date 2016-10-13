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


int guess(ll x1, ll y1, ll x2, ll y2)
{
	int res = 0;
	printf("? %lld %lld %lld %lld\n", x1, y1, x2, y2);
	fflush(stdout);
	scanf("%d", &res);
	return res;
}

int main()
{
	ll x11, y11, x12, y12, x21, y21, x22, y22, left, right, mid, n;
	
	int resLeft, resRight, resMid, res, res1, res2;
	scanf("%lld", &n);
	
	
	// find x11 and x21 
	
	left = 1;
	right = n;
	resLeft = guess(left, 1, n, n);
	resRight = guess(right, 1, n, n);
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		resMid = guess(mid, 1, n, n);
		if (resMid == 2)
		{
			left = mid;
			resLeft = resMid;
		}
		else
		{
			right = mid;
			resRight = resMid;
		}
	}
	
	if (resRight == 2)
	{
		x11 = x21 = n;
	}
	else if (resRight == 0)
	{
		x11 = x21 = left;
	}
	else
	{
		x11 = left;
		left++;
		right = n;
		resLeft = guess(left, 1, n, n);
		resRight = guess(right, 1, n, n);
		while (left + 1 < right)
		{
			mid = (left + right) / 2;
			resMid = guess(mid, 1, n, n);
			if (resMid == 1)
			{
				left = mid;
				resLeft = resMid;
			}
			else
			{
				right = mid;
				resRight = resMid;
			}
		}
		
		if (resRight == 1)
		{
			x21 = n;
		}
		else
		{
			x21 = left;
		}
	}
	
	// find x12 and x22
	left = 1;
	right = n;
	resLeft = guess(1, 1, left, n);
	resRight = guess(1, 1, right, n);
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		resMid = guess(1, 1, mid, n);
		if (resMid != 2)
		{
			left = mid;
			resLeft = resMid;
		}
		else
		{
			right = mid;
			resRight = resMid;
		}
	}
	
	if (resLeft == 2)
	{
		x12 = x22 = 1;
	}
	else if (resLeft == 0)
	{
		x12 = x22 = right;
	}
	else
	{
		x12 = right;
		right--;
		left = 1;
		resLeft = guess(1, 1, left, n);
		resRight = guess(1, 1, right, n);
		while (left + 1 < right)
		{
			mid = (left + right) / 2;
			resMid = guess(1, 1, mid, n);
			if (resMid != 1)
			{
				left = mid;
				resLeft = resMid;
			}
			else
			{
				right = mid;
				resRight = resMid;
			}
		}
		
		if (resLeft == 1)
		{
			x22 = 1;
		}
		else
		{
			x22 = right;
		}
	}
	
	swap(x12, x22);
	
	if (x21 <= x12)
	{
		res1 = guess(x11, 1, x22, n);
		res2 = guess(x21, 1, x12, n);
		if (res1 == 2 && res2 == 1)
		{
			swap(x12, x22);
		}
	}
	
	
	// find y11 and y21
	left = 1;
	right = n;
	resLeft = guess(1, left, n, n);
	resRight = guess(1, right, n, n);
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		resMid = guess(1, mid, n, n);
		if (resMid == 2)
		{
			left = mid;
			resLeft = resMid;
		}
		else
		{
			right = mid;
			resRight = resMid;
		}
	}
	
	if (resRight == 2)
	{
		y11 = y21 = n;
	}
	else if (resRight == 0)
	{
		y11 = y21 = left;
	}
	else
	{
		y11 = left;
		left++;
		right = n;
		resLeft = guess(1, left, n, n);
		resRight = guess(1, right, n, n);
		while (left + 1 < right)
		{
			mid = (left + right) / 2;
			resMid = guess(1, mid, n, n);
			if (resMid == 1)
			{
				left = mid;
				resLeft = resMid;
			}
			else
			{
				right = mid;
				resRight = resMid;
			}
		}
		
		if (resRight == 1)
		{
			y21 = n;
		}
		else
		{
			y21 = left;
		}
	}
	
	// find y12 and y22
	left = 1;
	right = n;
	resLeft = guess(1, 1, n, left);
	resRight = guess(1, 1, n, right);
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		resMid = guess(1, 1, n, mid);
		if (resMid != 2)
		{
			left = mid;
			resLeft = resMid;
		}
		else
		{
			right = mid;
			resRight = resMid;
		}
	}
	
	if (resLeft == 2)
	{
		y12 = y22 = 1;
	}
	else if (resLeft == 0)
	{
		y12 = y22 = right;
	}
	else
	{
		y12 = right;
		right--;
		left = 1;
		resLeft = guess(1, 1, n, left);
		resRight = guess(1, 1, n, right);
		while (left + 1 < right)
		{
			mid = (left + right) / 2;
			resMid = guess(1, 1, n, mid);
			if (resMid != 1)
			{
				left = mid;
				resLeft = resMid;
			}
			else
			{
				right = mid;
				resRight = resMid;
			}
		}
		
		if (resLeft == 1)
		{
			y22 = 1;
		}
		else
		{
			y22 = right;
		}
	}
	
	swap(y12, y22);
	if (y21 <= y12)
	{
		res1 = guess(1, y11, n, y22);
		res2 = guess(1, y21, n, y12);
		if (res1 == 2 && res2 == 1)
		{
			swap(y12, y22);
		}
	}
	
	
	
	res1 = guess(x11, y11, x12, y12);
	res2 = guess(x21, y21, x22, y22);
	
	if (res1 == 0 || res2 == 0)
	{
		swap(y11, y21);
		swap(y12, y22);
	}
	
	printf("! %lld %lld %lld %lld %lld %lld %lld %lld\n", x11, y11, x12, y12, x21, y21, x22, y22);
	fflush(stdout);
	return 0;
}