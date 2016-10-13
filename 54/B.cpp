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

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

inline void nextLine()
{
	while (getchar() != '\n');
}

const ll MOD = 1e9 + 7;
const int N = 25;

int n, m;
char a[N][N];



pii tran1(int i, int j, int x, int y)
{
	return mp(i, j);
}

pii tran2(int i, int j, int x, int y)
{
	return mp(x - 1 - i, y - 1 - j);
}

pii tran3(int i, int j, int x, int y)
{
	if (x != y)
	{
		return mp(i, j);
	}
	
	return mp(j, x - 1 - i);
}

pii tran4(int i, int j, int x, int y)
{
	if (x != y)
	{
		return mp(i, j);
	}
	
	return mp(y - 1 - j, i);
}

typedef pii (*TranFun)(int i, int j, int x, int y);
TranFun TF[4] = {tran1, tran2, tran3, tran4};

ll calHash(int row, int col, int x, int y, TranFun trFun)
{
	int i, j, ii, jj;
	pii tranPos;
	ll res = 0;
	ll exp = 1;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			tranPos = trFun(i, j, x, y);
			ii = row + tranPos.first;
			jj = col + tranPos.second;
			res += a[ii][jj] * exp;
			exp *= MOD;
		}
	}
	
	return res;
}


inline bool isGood(int x, int y)
{
	if (n % x || m % y)
	{
		return false;
	}
	
	int i, j, k;
	set<ll> hashSet;
	vector<ll> tmpVec;
	ll hashValue;
	for (i = 0; i < n; i += x)
	{
		for (j = 0; j < m; j += y)
		{
			tmpVec.clear();
			for (k = 0; k < 4; k++)
			{
				hashValue = calHash(i, j, x, y, TF[k]);
				if (hashSet.count(hashValue) > 0)
				{
					return false;
				}
				tmpVec.push_back(hashValue);
			}
			for (k = 0; k < 4; k++)
			{
				hashSet.insert(tmpVec[k]);
			}
		}
	}
	
	return true;
}

int main()
{
	int x, y;
	int minArea = 1000;
	int ansNum = 0;
	pii ans;
	
	scanf("%d%d", &n, &m);
	nextLine();
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < m; y++)
		{
			scanf("%c", &a[x][y]);
		}
		nextLine();
	}
	
	for (x = 1; x <= n; x++)
	{
		for (y = 1; y <= m; y++)
		{
			if (isGood(x, y))
			{
				ansNum++;
				if (x * y < minArea || x * y == minArea && x < ans.first)
				{
					minArea = x * y;
					ans = mp(x, y);
				}
			}
		}
	}
	
	printf("%d\n", ansNum);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}