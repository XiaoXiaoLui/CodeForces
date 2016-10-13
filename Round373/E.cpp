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

const int MOD = 1e9 + 7;


/*
a1 b1    a2 b2    a2*a1+c2*b1  b2*a1+d2*b1
c1 d1 *  c2 d2 =  a2*c1+c2*d1  b2*c1+d2*d1

*/

struct Matrix
{
	Matrix() : a(1), b(1), c(1), d(0)
	{
	}
	void zero()
	{
		a = d = 1;
		b = c = 0;
	}
	ll a;
	ll b;
	ll c; 
	ll d;
};

Matrix mul(const Matrix &m1, const Matrix &m2)
{
	Matrix res;
	res.a = (m2.a*m1.a + m2.c*m1.b) % MOD;
	res.b = (m2.b*m1.a + m2.d*m1.b) % MOD;
	res.c = (m2.a*m1.c + m2.c*m1.d) % MOD;
	res.d = (m2.b*m1.c + m2.d*m1.d) % MOD;
	
	return res;
}

Matrix add(const Matrix &m1, const Matrix &m2)
{
	Matrix res;
	res.a = (m1.a + m2.a) % MOD;
	res.b = (m1.b + m2.b) % MOD;
	res.c = (m1.c + m2.c) % MOD;
	res.d = (m1.d + m2.d) % MOD;
	
	return res;
}

Matrix mypow(Matrix a, int b)
{
	Matrix res;
	b--;
	while (b)
	{
		if (b & 1)
		{
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	
	return res;
}

Matrix expA(int b)
{
	Matrix res;
	Matrix a;
	b--;
	while (b)
	{
		if (b & 1)
		{
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	
	return res;
}

const int N = 1e5 + 100;

Matrix tr[4*N];
Matrix a[N];
Matrix lazy[4*N];

void build(int idx, int start, int end)
{
	if (start == end)
	{
		tr[idx] = a[start];
		return;
	}
	
	int mid = (start + end) / 2;
	build(2*idx, start, mid);
	build(2*idx + 1, mid + 1, end);
	
	tr[idx] = add(tr[2*idx], tr[2*idx + 1]);
}

inline void checkLazy(int idx, int start, int end)
{
	if (lazy[idx].b != 0)
	{
		tr[idx] = mul(tr[idx], lazy[idx]);
		if (start != end)
		{
			lazy[2*idx] = mul(lazy[2*idx], lazy[idx]);
			lazy[2*idx + 1] = mul(lazy[2*idx + 1], lazy[idx]);
		}
		
		lazy[idx].zero();
	}
}

void update(int idx, int start, int end, int l, int r, const Matrix &Ax)
{
	checkLazy(idx, start, end);
	
	if (end < l || start > r)
	{
		return;
	}
	
	if (start >= l && end <= r)
	{
		tr[idx] = mul(tr[idx], Ax);
		if (start != end)
		{
			lazy[2*idx] = mul(lazy[2*idx], Ax);
			lazy[2*idx + 1] = mul(lazy[2*idx + 1], Ax);
		}
		return;
	}
	
	int mid = (start + end) / 2;
	update(2*idx, start, mid, l, r, Ax);
	update(2*idx + 1, mid + 1, end, l, r, Ax);
	
	tr[idx] = add(tr[2*idx], tr[2*idx + 1]);
}

ll query(int idx, int start, int end, int l, int r)
{	
	checkLazy(idx, start, end);
	if (end < l || start > r)
	{
		return 0;
	}
	
	if (start >= l && end <= r)
	{
		return tr[idx].b;
	}
	
	int mid = (start + end) / 2;
	ll resLeft, resRight;
	resLeft = query(2*idx, start, mid, l, r);
	resRight = query(2*idx + 1, mid + 1, end, l, r);
	
	return (resLeft + resRight) % MOD;
}

vector<ll> ans;

int main()
{
	int i, n, qNum, type, l, r, x;
	scanf("%d%d", &n, &qNum);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		a[i] = expA(x);
	}
	
	for (i = 0; i < 4*N; i++)
	{
		lazy[i].zero();
	}
	
	build(1, 1, n);
	Matrix tmp;
	for (i = 1; i <= qNum; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d%d%d", &l, &r, &x);
			tmp = expA(x);
			update(1, 1, n, l, r, tmp);
		}
		else
		{
			scanf("%d%d", &l, &r);
			ans.push_back(query(1, 1, n, l, r));
		}
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%lld\n", ans[i]);
	}
	
	return 0;
}