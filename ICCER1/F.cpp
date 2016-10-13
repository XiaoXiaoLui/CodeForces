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

vector<pii> lst[N];
int kNum[N];
int g[50][50];
int pos[50];
int c[50];
pii seg[N];

int ans[N];

inline int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

bool ok(pii p)
{
	int k, len, offset;
	len = p.second;
	offset = p.first;
	for (k = 1; k <= 40; k++)
	{
		if (c[k])
		{
			if ((offset - pos[k]) % g[k][len] != 0)
			{
				return false;
			}
		}
	}
	return true;
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
			lst[l].push_back(mp(j, i));
		}
	}
	
	for (i = 1; i <= 40; i++)
	{
		for (j = 1; j <= 40; j++)
		{
			g[i][j] = gcd(i, j);
		}
	}
	
	
	for (k = 1; k <= m; k++)
	{
		start = 0;
		end = lst[k].size();
		for (i = start; i <= end; i++)
		{
			if (i < end && (i == start || lst[k][i].second == lst[k][i - 1].second + 1))
			{
				seg[i - start] = mp(lst[k][i].first, kNum[lst[k][i].second]);
			}
			else // cal a segment
			{
				int len = i - start;	
				//fill(pos, pos + 50, -1);	
				fill(c, c + 50, 0);
				for (p1 = 0, p2 = -1; p2 + 1 < len;)
				{
					if (ok(seg[p2 + 1]))
					{
						p2++;
						pos[seg[p2].second] = seg[p2].first;
						c[seg[p2].second]++;
						ans[k] = max(ans[k], p2 - p1 + 1);
					}
					else
					{
						c[seg[p1].second]--;
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