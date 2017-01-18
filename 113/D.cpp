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

template <class T>
struct Matrix
{
	Matrix(int nn) : n(nn), a(nn, vector<T>(nn, 0))
	{
		
	}
	Matrix(const Matrix<T> &other)
	{
		n = other.n;
		a = other.a;
	}
	
	void unit()
	{
		for (int i = 0; i < n; i++)
		{
			a[i][i] = 1;
		}
	}
	
	vector<T>& operator[](int i)
	{
		return a[i];
	}
	
	Matrix<T> operator*(const Matrix<T> &other) const
	{
		int i, j, k;
		Matrix<T> res(n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				T tmp = 0;
				for (k = 0; k < n; k++)
				{
					tmp += a[i][k] * other.a[k][j];
				}
				res.a[i][j] = tmp;
			}
		}
		return res;
	}
	
	Matrix<T> calPow(ll k)
	{
		Matrix<T> res(n);
		res.unit();
		
		Matrix<T> b(*this);
		while (k)
		{
			if (k & 1)
			{
				res = res * b;
			}
			
			b = b * b;
			k >>= 1;
		}
		
		return res;
	}
	
private:
	vector<vector<T> > a;
	int n;
};


int n, stateNum;
double stay[30];
vector<int> graph[30];
double ans[30];

/*
int getState(int u, int v)
{
	return u * n + v;
}

void getUV(int state, int &u, int &v)
{
	u = state / n;
	v = state % n;
}*/

int getState(int u, int v)
{
	if (u < v)
	{
		swap(u, v);
	}
	u++;
	v++;
	int res = (u - 1) * u / 2 + v - 1;
	return res;
}

void getUV(int state, int &u, int &v)
{
	int i, j;
	state++;
	for (i = 1; i <= n; i++)
	{
		if (state <= i)
		{
			j = state;
			break;
		}
		else
		{
			state -= i;
		}
	}
	
	u = i - 1;
	v = j - 1;
}

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif
	
	int m, u, v, i, j, k, a, b, nextState;
	cin >> n >> m >> a >> b;
	a--;
	b--;
	
	for (i = 0; i < m; i++)
	{
		cin >> u >> v;
		u--;
		v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (i = 0; i < n; i++)
	{
		cin >> stay[i];
	}
	
	//stateNum = n * n;
	stateNum = n * (n - 1) / 2 + n;
	
	Matrix<double> mat(stateNum);
	double stayU, stayV, moveU, moveV;
	for (i = 0; i < stateNum; i++)
	{
		getUV(i, u, v);
		if (u == v)
		{
			continue;
		}
		
		stayU = stay[u];
		stayV = stay[v];
		moveU = (1 - stay[u]) / graph[u].size();
		moveV = (1 - stay[v]) / graph[v].size();
		// both stay
		mat[i][i] += stayU * stayV;
		
		// u stay v move
		for (auto nextV : graph[v])
		{
			nextState = getState(u, nextV);
			mat[i][nextState] += stayU * moveV;
		}
		
		// u move v stay
		for (auto nextU : graph[u])
		{
			nextState = getState(nextU, v);
			mat[i][nextState] += moveU * stayV;
		}
		
		// both move
		for (auto nextU : graph[u])
		{
			for (auto nextV : graph[v])
			{
				nextState = getState(nextU, nextV);
				mat[i][nextState] += moveU * moveV;
			}
		}
	}
	
	for (i = 0; i < stateNum; i++)
	{
		getUV(i, u, v);
		if (u != v)
		{
			mat[i][i] -= 1;
		}
		else
		{
			mat[i][i] = 1;
		}
	}
	
	Matrix<double> matB(stateNum);
	for (i = 0; i < stateNum; i++)
	{
		matB[i][i] = 1;
	}
	
	// use gause elimination to solve Ax = b
	for (i = 0; i < stateNum; i++)
	{
		int mxIdx = i;
		for (j = i + 1; j < stateNum; j++)
		{
			if (fabs(mat[j][i])  > fabs(mat[mxIdx][i]))
			{
				mxIdx = j;
			}
		}
		
		for (j = 0; j < stateNum; j++)
		{
			swap(mat[i][j], mat[mxIdx][j]);
			swap(matB[i][j], matB[mxIdx][j]);
		}
		
		double div = mat[i][i];
		for (k = i + 1; k < stateNum; k++)
		{
			double mul = -mat[k][i];
			for (j = 0; j < stateNum; j++)
			{
				if (j > i)
				{
					mat[k][j] += mat[i][j] / div * mul;
				}
				else // can be omit
				{
					mat[k][j] = 0;
				}
				
				
				matB[k][j] += matB[i][j] / div * mul;
			}
		}
	}
	
	// backward substitution
	Matrix<double> matX(stateNum);
	
	// solve k  Ax = b
	for (k = 0; k < stateNum; k++)
	{
		for (i = stateNum - 1; i >= 0; i--)
		{
			double tmp = matB[i][k];
			for (j = i + 1; j < stateNum; j++)
			{
				tmp -= mat[i][j] * matX[j][k];
			}
			matX[i][k] = tmp / mat[i][i];
		}
	}
	
	int initState = getState(a, b);
	for (u = 0; u < n; u++)
	{
		int finalState = getState(u, u);
		ans[u] = matX[initState][finalState];
	}
	
	for (i = 0; i < n; i++)
	{
		printf("%.9lf ", ans[i]);
	}
	printf("\n");
	return 0;
}