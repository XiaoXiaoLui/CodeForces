#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;


const int N = 105;

vector<pii> a[N];

int main()
{
	int n, S, v, t, i, j, k, p1, p2, ans, preOffset, curOffset, curTime, s1, s2;
	scanf("%d%d", &n, &S);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		curTime = 0;
		for (j = 0; j < k; j++)
		{
			scanf("%d%d", &v, &t);
			curTime += t;
			a[i].push_back(mp(v, curTime));
		}
	}
	
	ans = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			preOffset = curOffset = curTime = 0;
			p1 = p2 = 0;
			s1 = s2 = 0;
			while (p1 < a[i].size() && p2 < a[j].size())
			{
				if (a[i][p1].second < a[j][p2].second)
				{
					s1 += (a[i][p1].second - curTime) * a[i][p1].first;
					s2 += (a[i][p1].second - curTime) * a[j][p2].first;
					curOffset = s1 - s2;
					
					/*
					if (curOffset == 0 || (ll)curOffset * preOffset < 0)
					{
						ans++;
					}
					
					preOffset = curOffset;
					*/
					if ((ll)curOffset * preOffset < 0)
					{
						ans++;
					}
					
					if (curOffset != 0)
					{
						preOffset = curOffset;
					}
					curTime = a[i][p1].second;
					p1++;
				}
				else if (a[i][p1].second > a[j][p2].second)
				{
					s2 += (a[j][p2].second - curTime) * a[j][p2].first;
					s1 += (a[j][p2].second - curTime) * a[i][p1].first;
					curOffset = s1 - s2;
					
					/*
					if (curOffset == 0 || (ll)curOffset * preOffset < 0)
					{
						ans++;
					}
					preOffset = curOffset;*/
					if ((ll)curOffset * preOffset < 0)
					{
						ans++;
					}
					
					if (curOffset != 0)
					{
						preOffset = curOffset;
					}
					curTime = a[j][p2].second;
					p2++;
				}
				else
				{
					s1 += (a[i][p1].second - curTime) * a[i][p1].first;
					s2 += (a[i][p1].second - curTime) * a[j][p2].first;
					curOffset = s1 - s2;
					
					/*
					if (curOffset == 0 || (ll)curOffset * preOffset < 0)
					{
						ans++;
					}
					
					preOffset = curOffset;*/
					if ((ll)curOffset * preOffset < 0)
					{
						ans++;
					}
					
					if (curOffset != 0)
					{
						preOffset = curOffset;
					}
					curTime = a[i][p1].second;
					p1++;
					p2++;
				}
			}
			/*
			if (p1 == a[i].size() && p2 == a[j].size())
			{
				ans--;
			}*/
		}
	}
	
	printf("%d\n", ans);
	return 0;
}