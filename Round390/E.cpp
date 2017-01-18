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
#include <bitset>

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

const int N = 405;
char pat[N][N];
char a[N][N];
bitset<N> mat[26][N];
bitset<N> ans[N];


// shift to lower bit
bitset<N> shift(const bitset<N> &bs, int len, int num)
{
	return bs >> num | bs << (len - num);
}

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int n, m, r, c, i, j, k;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	cin >> r >> c;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cin >> pat[i][j];
		}
	}
	
	for (k = 0; k < 26; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				mat[k][i][j] = a[i][j] == 'a' + k;
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			ans[i][j] = 1;
		}
	}
	
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (pat[i][j] == '?')
			{
				continue;
			}
			int ch = pat[i][j] - 'a';
			for (k = 0; k < n; k++)
			{
				ans[k] &= shift(mat[ch][(k + i) % n], m, j % m);
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
	
	return 0;
}