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


const int MOD = 12345;

int stateNum;

// zero base
struct Matrix
{
	Matrix(int nn = stateNum) : n(nn), a(nn, vector<ll>(nn, 0))
	{
	}
	
	Matrix(const Matrix &other) : n(other.n), a(other.a)
	{
	}
	
	void unit()
	{
		for (int i = 0; i < n; i++)
		{
			a[i][i] = 1;
		}
	}
	
	Matrix operator*(const Matrix &other) const
	{
		Matrix res;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ll tmp = 0;
				for (int k = 0; k < n; k++)
				{
					tmp += a[i][k] * other.a[k][j];
					if (tmp >= MOD)
					{
						tmp %= MOD;
					}
				}
				res.a[i][j] = tmp;
			}
		}
		
		return res;
	}
	
	void mul(const Matrix &other)
	{
		Matrix res;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ll tmp = 0;
				for (int k = 0; k < n; k++)
				{
					tmp += a[i][k] * other.a[k][j];
					if (tmp >= MOD)
					{
						tmp %= MOD;
					}
				}
				res.a[i][j] = tmp;
			}
		}
		
		a.swap(res.a);
	}
	
	vector<ll>& operator[](int i)
	{
		return a[i];
	}
	
	Matrix power(ll k) const
	{
		Matrix res;
		res.unit();
		Matrix a(*this);
		
		while (k)
		{
			if (k & 1)
			{
				res.mul(a);
			}
			a.mul(a);
			k >>= 1;
		}
		
		return res;
	}
	
private:
	vector<vector<ll> > a;
	int n;
};

const int N = 30;
set<int> mul[N];
int base[N];
int curArray[N];

int main()
{
	USE_IOSTREAM;
	ll k;
	int c, i, j, num;
	char ch;
	cin >> k >> c;
	for (i = 1; i <= c; i++)
	{
		cin >> ch;
		cin >> num;
		mul[ch - 'A'].insert(num);
	}
	
	stateNum = 1;
	for (i = 0; i < 26; i++)
	{
		if (!mul[i].empty())
		{
			base[i] = 1;
			for (auto tmp : mul[i])
			{
				base[i] *= tmp;
			}
			stateNum *= base[i];
		}
	}
	
	Matrix mat;
	for (i = 0; i < stateNum; i++)
	{
		int curState = i;
		for (j = 0; j < 26; j++)
		{
			if (!base[j])
			{
				continue;
			}
			curArray[j] = curState % base[j];
			curState /= base[j];
		}
		
		for (j = 0; j < 26; j++)
		{
			if (!base[j])
			{
				continue;
			}
			
			curArray[j]++;
			if (curArray[j] >= base[j])
			{
				curArray[j] = 0;
			}
			
			int nextState = 0;
			
			for (int l = 25; l >= 0; l--)
			{
				if (!base[l])
				{
					continue;
				}
				nextState = nextState * base[l] + curArray[l];
			}
			
			mat[i][nextState] += 1;
			curArray[j]--;
			if (curArray[j] < 0)
			{
				curArray[j] = base[j] - 1;
			}
		}
	}
	
	Matrix res = mat.power(k);
	int ans = 0;
	
	for (i = 0; i < stateNum; i++)
	{
		bool ok = true;
		int curState = i;
		for (j = 0; j < 26; j++)
		{
			if (!base[j])
			{
				continue;
			}
			curArray[j] = curState % base[j];
			curState /= base[j];
			
			
			bool isMul = false;
			for (auto tmp : mul[j])
			{
				if (curArray[j] % tmp == 0)
				{
					isMul = true;
					break;
				}
			}
			
			if (!isMul)
			{
				ok = false;
				break;
			}
		}
		
		if (ok)
		{
			ans = (ans + res[0][i]) % MOD;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}