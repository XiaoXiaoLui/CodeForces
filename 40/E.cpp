#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define mp make_pair<int, int>

const int N = 1005;
int a[N][N];

int rowCount[N];
int colCount[N];
int rowProduct[N];
int colProduct[N];

int calExp(int n, int mod)
{
	ll exp = 2;
	ll res = 1;
	while (n)
	{
		if (n & 1)
		{
			res = (exp * res) % mod;
		}
		exp = (exp * exp) % mod;
		n >>= 1;
	}
	
	return (int)res;
}


int main()
{
	int n, m, k, mod, i, j, value, ans;
	bool ok;
	scanf("%d%d%d", &n, &m, &k);
	int cm = m, cn = n, ck = k;
	
	fill(rowProduct, rowProduct + N, 1);
	fill(colProduct, colProduct + N, 1);
	while (k--)
	{
		scanf("%d%d%d", &i, &j, &value);
		a[i][j] = value;
		rowCount[i]++;
		colCount[j]++;
		rowProduct[i] *= value;
		colProduct[j] *= value;
	}
	scanf("%d", &mod);
	
	
	if ((m & 1) ^ (n & 1))
	{
		ok = false;
	}
	else
	{
		ok = true;
		for (i = 1; i <= n; i++)
		{
			if (rowCount[i] == m)
			{
				cn--;
				ck -= m;
				if (rowProduct[i] != -1)
				{
					ok = false;
					break;
				}
			}
		}
		
		for (j = 1; j <= m; j++)
		{
			if (colCount[j] == n)
			{
				cm--;
				ck -= n;
				if (colProduct[j] != -1)
				{
					ok = false;
					break;
				}
			}
		}
	}
	
	if (ok)
	{
		ans = calExp((cn - 1)*(cm - 1) - ck, mod);
	}
	else
	{
		ans = 0;
	}
	
	printf("%d\n", ans);
	
	return 0;
}