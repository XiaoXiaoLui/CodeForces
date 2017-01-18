#include<bits/stdc++.h>

/*#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>*/

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define pdd pair<double, double>
#define mp make_pair

typedef long long ll;

const int N = 1e5 + 100;
int a[N];

pdd operator+(const pdd &p1, const pdd &p2)
{
	return {p1.first + p2.first, p1.second + p2.second};
}

pdd operator-(const pdd &p1, const pdd &p2)
{
	return {p1.first - p2.first, p1.second - p2.second};
}

struct FenwickTree
{
	void init(int nn)
	{
		n = nn;
	}
	
	int lowbit(int idx)
	{
		return idx & (-idx);
	}
	
	void add(int i, int orgIdx)
	{
		pdd tmp(1, orgIdx);
		while (i <= n)
		{
			array[i] = array[i] + tmp;
			i += lowbit(i);
		}
	}
	
	pdd query(int i)
	{
		pdd res(0, 0);
		while (i > 0)
		{
			res = res + array[i];
			i -= lowbit(i);
		}
		return res;
	}
	
private:
	int n;
	pdd array[N];
} tr;

inline double comb(int num)
{
	return (double)num * (num - 1) / 2;
}

/*
3
2 3 1
1.58333333333


*/

int main()
{
	// USE_IOSTREAM;
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	tr.init(n);
	
	double dm = (double) n * (n + 1) / 2;
	double ans = 0;
	tr.add(a[1], 1);
	for (i = 2; i <= n; i++)
	{
		ans += 0.5 * (n - i + 1) * (i - 1) * i / 2;
		auto ret = tr.query(n) - tr.query(a[i]);
		double num = ret.first;
		double sum = ret.second;
		ans += num * dm - sum * (n - i + 1);
		tr.add(a[i], i);
	}
	
	ans /= dm;
	
	printf("%.11lf\n", ans);
	
	return 0;
}