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

char a[10][10];
const int N = 4;

bool check()
{
	int i, j, k;
	bool ret = false;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 'x' && a[i + 1][j] == 'x' && a[i + 2][j] == 'x')
			{
				ret = true;
			}
			
			if (a[j][i] == 'x' && a[j][i + 1] == 'x' && a[j][i + 2] == 'x')
			{
				ret = true;
			}
		}	
	}
	
	for (k = 0; k < 2*N - 1; k++)
	{
		int startRow = max(0, k - N + 1);
		int endRow = min(N - 1, k) - 2;
		for (i = startRow; i <= endRow; i++)
		{
			int offset = k - N + 1;
			if (a[i][i - offset] == 'x' && a[i + 1][i + 1 - offset] == 'x' && a[i + 2][i + 2 - offset] == 'x')
			{
				ret = true;
			}
		}
		
		startRow = max(0, k - N + 1);
		endRow = min(N - 1, k) - 2;
		for (i = startRow; i <= endRow; i++)
		{
			if (a[i][k - i] == 'x' && a[i + 1][k - i - 1] == 'x' && a[i + 2][k - i - 2] == 'x')
			{
				ret = true;
			}
		}
	}
	
	return ret;
}

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	int n, i, j;
	n = 4;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	bool ok = false;

	for (i = 0; i < 4 && !ok; i++)
	{
		for (j = 0; j < 4 && !ok; j++)
		{
			if (a[i][j] == '.')
			{
				a[i][j] = 'x';
				if (check())
				{
					ok = true;
					break;
				}
				a[i][j] = '.';
			}
		}
	}
	
	if (ok)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}