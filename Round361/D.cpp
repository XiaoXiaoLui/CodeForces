#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int INF = 1e9 + 50;
const int N = 2e5 + 5;
const int M = 18;
int a[N];
int b[N];
int sta[N][M];
int stb[N][M];
int lgk[N];

int maxA(int l, int r)
{
	int k = lgk[r - l + 1];
	return max(sta[l][k], sta[r - (1 << k) + 1][k]);
}

int minB(int l, int r)
{
	int k = lgk[r - l + 1];
	return min(stb[l][k], stb[r - (1 << k) + 1][k]);
}

int main()
{
	int n, i, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sta[i][0] = a[i];
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		stb[i][0] = b[i];
	}
	
	for (i = 2; i <= n; i++)
	{
		lgk[i] = lgk[i >> 1] + 1;
	}
	
	for (k = 1; k <= lgk[n - 1]; k++)
	{
		for (i = 0; i + (1 << k) - 1 < n; i++)
		{
			sta[i][k] = max(sta[i][k - 1], sta[i + (1 << (k - 1))][k - 1]);
		}
	}
	
	for (k = 1; k <= lgk[n - 1]; k++)
	{
		for (i = 0; i + (1 << k) - 1 < n; i++)
		{
			stb[i][k] = min(stb[i][k - 1], stb[i + (1 << (k - 1))][k - 1]);
		}
	}
	
	int left, right, first, p, d;
	ll ans = 0;
	for (i = 0; i < n; i++)
	{
		// lower_bound
		left = i - 1;
		d = n  - i;
		while (d)
		{
			if (left + d < n && maxA(i, left + d) < minB(i, left + d))
			{
				left += d;
			}
			else
			{
				d /= 2;
			}
		}
		/*
		if (maxA(i, left) < minB(i, left))
		{
			left++;
		}*/
		
		// upper_bound
		right = i - 1;
		d = n - i;
		while (d)
		{
			if (right + d < n && maxA(i, right + d) <= minB(i, right + d))
			{
				right += d;
			}
			else
			{
				d /= 2;
			}
		}
		/*
		if (maxA(i, right) <= minB(i, right))
		{
			right++;
		}*/
		ans += right - left;
	}
	
	
	printf(LLD "\n", ans);
	return 0;
}