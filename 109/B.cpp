// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 3000;

int a[N];
int mul[12];

int next(int cur)
{
	static int c[2] = {4, 7};
	int len = 0;
	int tmp;
	int add = 1;
	int res = 0;
	while (cur)
	{
		tmp = cur % 10;
		cur /= 10;
		
		int idx = c[0] == tmp ? 0 : 1;
		idx = (idx + add) % 2;
		res += c[idx] * mul[len];
		if (add && c[idx] == 7)
		{
			add = 0;
		}
		
		len++;
	}
	
	if (add)
	{
		res += 4 * mul[len];
	}
	
	return res;
}

double calP(int l1, int r1, int l2, int r2)
{
	// select point in [l1, r1], the prob it's in [l2, r2]
	int l, r;
	l = max(l1, l2);
	r = min(r1, r2);
	if (r < l)
	{
		return 0.0;
	}
	
	return (double)(r - l + 1) / (r1 - l1 + 1);
}

int main()
{
	// USE_IOSTREAM;
	int pl, pr, vl, vr, k;
	cin >> pl >> pr >> vl >> vr >> k;
	
	int i, j;
	mul[0] = 1;
	int len;
	for (i = 1; i < 10; i++)
	{
		mul[i] = mul[i - 1] * 10;
	}
	
	a[0] = 0;
	a[1] = 4;
	for (i = 2; true; i++)
	{
		a[i] = next(a[i - 1]);
		if (a[i] == 777777777)
		{
			break;
		}
	}
	len = i;
	a[i + 1] = 2e9;
	
	double ans = 0;
	for (i = 1; i + k - 1 <= len; i++)
	{
		j = i + k - 1;
		// [a[i - 1] + 1, a[i]] [a[j], a[j + 1] - 1]
		ans += calP(vl, vr, a[i - 1] + 1, a[i]) * calP(pl, pr, a[j], a[j + 1] - 1);
		ans += calP(pl, pr, a[i - 1] + 1, a[i]) * calP(vl, vr, a[j], a[j + 1] - 1);
		if (i == j)
		{
			ans -= calP(pl, pr, a[i], a[i]) * calP(vl, vr, a[i], a[i]);
		}
	}
	
	printf("%.10lf\n", ans);
	
	return 0;
}