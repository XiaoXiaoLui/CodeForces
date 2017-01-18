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

double comb(int a, int b)
{
	double res = 1;
	for (int i = 0; i < b; i++)
	{
		res = res * (a - i) / (i + 1);
	}
	
	return res;
}

int main()
{
	USE_IOSTREAM;
	int n, m, h, num, i, w, sum;
	cin >> n >> m >> h;
	
	sum = 0;
	for (i = 1; i <= m; i++)
	{
		cin >> num;
		if (i == h)
		{
			w = num;
		}
		sum += num;
	}
	
	if (sum < n)
	{
		cout << -1 << endl;
		return 0;
	}
	
	sum--;
	n--;
	w--;
	double ans = 0;
	for (i = 1; i <= w && i <= n; i++)
	{
		ans += comb(w, i) * comb(sum - w, n - i);
	}
	
	ans /= comb(sum, n);
	
	printf("%.9lf\n", ans);
	return 0;
}