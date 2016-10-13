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

const int N = 1e5 + 100;
const double DOUBLE_MIN = 1e-15;

struct Data
{
	Data() : f(0), g(0)
	{
		
	}
	Data(double ff, double gg) : f(ff), g(gg)
	{
		
	}
	double f;
	double g;
};

Data tr[4*N];
double p[N];

Data merge(const Data &d1, const Data &d2)
{
	Data res;
	const double &l1 = d1.f;
	const double &r1 = d1.g;
	const double &l2 = d2.f;
	const double &r2 = d2.g;
	
	double tmp;
	tmp = (1 - r1*(1-l2));
	if (tmp < DOUBLE_MIN)
	{
		res.f = res.g = 0;
	}
	else
	{
		res.f = l1*l2 / (1 - r1*(1-l2));
		res.g = r2 + (1 - r2)*r1*l2 / (1 - r1*(1 - l2));
	}
	
	return res;
}

void build(int idx, int left, int right)
{
	if (left == right)
	{
		tr[idx].f = p[left];
		tr[idx].g = p[left];
		return;
	}
	
	int mid = (left + right) / 2;
	build(idx*2, left, mid);
	build(idx*2 + 1, mid + 1, right);
	
	tr[idx] = merge(tr[idx*2], tr[idx*2 + 1]);
}

void update(int idx, int i, int left, int right)
{
	if (i < left || i > right)
	{
		return;
	}
	if (left == right)
	{
		tr[idx].f = p[left];
		tr[idx].g = p[left];
		return;
	}
	
	int mid = (left + right) / 2;
	update(idx*2, i, left, mid);
	update(idx*2 + 1, i, mid + 1, right);
	
	tr[idx] = merge(tr[idx*2], tr[idx*2 + 1]);
}

Data query(int idx, int start, int end, int left, int right)
{
	Data res;
	if (left == start && right == end)
	{
		res = tr[idx];
		return res;
	}
	
	
	int mid = (left + right) / 2;
	Data res1, res2;
	
	if (start >= left && end <= mid)
	{
		res = query(idx*2, start, end, left, mid);
	}
	else if (start >= mid + 1 && end <= right)
	{
		res = query(idx*2 + 1, start, end, mid + 1, right);
	}
	else
	{
		res1 = query(idx*2, start, mid, left, mid);
		res2 = query(idx*2 + 1, mid + 1, end, mid + 1, right);
		
		res = merge(res1, res2);
	}
	
	return res;
}


vector<double> ans;
int main()
{
	int n, qNum, i, a, b, l, r, k;
	int type;
	scanf("%d%d", &n, &qNum);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		p[i] = (double)a / b;
	}
	
	build(1, 1, n);
	for (i = 1; i <= qNum; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d%d%d", &k, &a, &b);
			p[k] = (double)a / b;
			update(1, k, 1, n);
		}
		else
		{
			scanf("%d%d", &l, &r);
			Data res = query(1, l, r, 1, n);
			ans.push_back(res.f);
		}
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%.9lf\n", ans[i]);
	}
	
	
	return 0;
}


/*
l1 = L(i, j)
r1 = R(i, j)
l2 = L(j + 1, k)
r2 = R(j + 1, k)

L(i, k) = l1*l2 + l1*(1-l2)*r1*l2 + ... q = (1 - l2)*r1
L(i, k) = l1*l2 / (1 - r1*(1-l2))
R(i, k) = r2 + (1-r2)*r1*l2 + (1-r2)*r1*(1-l2)*r1*l2 + ... q = r1*(1-l2)
R(i, k) = r2 + (1-r2)*r1*l2/(1-r1*(1-l2)) = (r2 - r1*r2 + r1*l2)/ (1-r1+r1*l2)

*/