#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 205;


int a[N];

struct AhoTree
{
	AhoTree() : num(1)
	{
	}
	
	void add(int index, const string &str)
	{
		int u, v, i, c;
		for (i = 0, u = 0; i < str.length(); i++)
		{
			c = str[i] - 'a';
			if (!tr[u][c])
			{
				tr[u][c] = num++;
			}
			u = tr[u][c];
		}
		e[u] += a[index];
	}
	
	void build()
	{
		queue<int> Q;
		Q.push(0);
		
		int u, v, i;
		
		while (!Q.empty())
		{
			u = Q.front();
			Q.pop();
			if (f[u] != u)
			{
				e[u] += e[f[u]];
			}
			for (i = 0; i < 26; i++)
			{
				v = tr[u][i];
				if (v)
				{
					au[u][i] = v;
					if (u)
					{
						f[v] = au[f[u]][i];
					}
					Q.push(v);
				}
				else
				{
					au[u][i] = au[f[u]][i];
				}
			}
		}
	}
	
	int e[N];
	int tr[N][28];
	int au[N][28];
	int f[N];
	int num;
};

struct Matrix
{
	Matrix(int rows, int cols) : n(rows), m(cols)
	{
		memset(array, -1, sizeof(array));
		
	}
	
	Matrix operator * (const Matrix &other) const
	{
		Matrix res(n, other.m);
		int i, j, k;
		for (i = 0; i < res.n; i++)
		{
			for (j = 0; j < res.m; j++)
			{
				for (k = 0; k < m; k++)
				{
					if (array[i][k] != -1 && other.array[k][j] != -1)
					{
						res.array[i][j] = max(res.array[i][j], array[i][k] + other.array[k][j]);
					}
				}
			}
		}
		return res;
	}
	
	void zeroDiagonal()
	{
		for (int i = 0; i < n; i++)
		{
			array[i][i] = 0LL;
		}
	}
	
	int m;
	int n;
	ll array[N][N];
};

Matrix mypow(const Matrix &a, ll b)
{
	Matrix res(a.n, a.n);
	res.zeroDiagonal();
	Matrix tmp(a);
	
	while (b)
	{
		if (b & 1)
		{
			res = res * tmp;
		}
		tmp = tmp * tmp;
		b >>= 1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, i, u;
	ll len;
	string str;
	AhoTree ahoTree;
	cin >> n >> len;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i <= n; i++)
	{
		cin >> str;
		ahoTree.add(i, str);
	}
	ahoTree.build();
	
	Matrix m1(ahoTree.num, ahoTree.num);
	for (u = 0; u < ahoTree.num; u++)
	{
		for (i = 0; i < 26; i++)
		{
			m1.array[ahoTree.au[u][i]][u] = ahoTree.e[ahoTree.au[u][i]];
		}
	}
	
	m1 = mypow(m1, len);
	Matrix m2(ahoTree.num, 1);
	m2.array[0][0] = 0;
	m2 = m1 * m2;
	
	ll ans = 0;
	for (i = 0; i < ahoTree.num; i++)
	{
		ans = max(ans, m2.array[i][0]);
	}
	
	cout << ans << endl;
	return 0;
}