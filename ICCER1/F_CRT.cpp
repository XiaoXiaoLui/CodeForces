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
#define pll pair<ll,ll>
#define mpll make_pair<ll, ll>

typedef long long ll;

const int N = 1e5 + 100;

vector<pll> lst[N];
int kNum[N];
pll st[N][20];
int lg[N];
int myExp[20];
int ans[N];

inline ll gcd(ll a, ll b)
{
	ll c;
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

inline ll egcd(ll a, ll b, ll &x, ll &y)
{
	ll x1, y1, d;
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	
	d = egcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - a / b * y1;
	
	return d;
}

pll crt(pll p1, pll p2)
{
	ll &a1 = p1.first, &a2 = p2.first, &b1 = p1.second, &b2 = p2.second;
	ll x, y, d, c, a3, b3, q;
	
	if (p1.first == -1 || p2.first == -1)
	{
		return mpll(-1, -1);
	}
	
	
	d = egcd(b1, b2, x, y);
	c = a2 - a1;
	if (c % d != 0)
	{
		return mpll(-1, -1);
	}
	b3 = b1 / d * b2;
	q = b2 / d;
	x = (c / d * x) % q;
	a3 = ((b1 * x + a1) % b3 + b3) % b3;
	
	return mpll(a3, b3);
}

bool ok(int i, int j)
{
	int len = j - i + 1;
	int k = lg[len];
	
	pll tmp = crt(st[i][k], st[j - myExp[k] + 1][k]);
	return tmp.first != -1;
}

int main()
{
	int i, j, k, l, n, m, end, p1, p2, start;
	
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &kNum[i]);
		for (j = 0; j < kNum[i]; j++)
		{
			scanf("%d", &l);
			lst[l].push_back(mpll(j, i));
		}
	}
	
	lg[1] = 0;
	for (i = 2; i < N; i++)
	{
		lg[i] = lg[i / 2] + 1;
	}
	myExp[0] = 1;
	for (i = 1; i < 20; i++)
	{
		myExp[i] = myExp[i - 1] * 2;
	}
	
	fill((pll*)st, (pll*)st + N * 20, mpll(-1, -1));
	for (k = 1; k <= m; k++)
	{
		start = 0;
		end = lst[k].size();
		for (i = start; i <= end; i++)
		{
			if (i < end && (i == start || lst[k][i].second == lst[k][i - 1].second + 1))
			{
				st[i - start][0] = mpll(lst[k][i].first, kNum[lst[k][i].second]);
			}
			else // cal a segment and init st
			{
				int len = i - start;
				for (p2 = 1; p2 <= lg[len]; p2++)
				{
					for (p1 = 0; p1 + myExp[p2] - 1 < len; p1++)
					{
						st[p1][p2] = crt(st[p1][p2 - 1], st[p1 + myExp[p2 - 1]][p2 - 1]);
					}
				}
				
				for (p1 = p2 = 0; p2 < len;)
				{
					if (ok(p1, p2))
					{
						ans[k] = max(ans[k], p2 - p1 + 1);
						p2++;
					}
					else
					{
						p1++;
					}
				}
				
				if (i == end)
				{
					break;
				}
				
				start = i;
				i--;
			}
		}
	}
	
	for (i = 1; i <= m; i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}