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

struct Point
{
	Point()
	{
	}
	Point(int xx, int yy) : x(xx), y(yy)
	{
	}
	
	int x;
	int y;
};

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return (int)a;
}

const int N = 1005;
const int K = 8;
int n, k;
Point m[N];
Point p[K];
int pm[K];
vector<int> pointLst[K][N];
int mark[N];

int main()
{
	int i, j, l, u;
	int ans;
	ll x, y, d;
	scanf("%d%d", &k, &n);
	for (i = 0; i < k; i++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &m[i].x, &m[i].y);
	}
	
	for (i = 0; i < k; i++)
	{
		map<pii, vector<pii> > tmpMap;
		for (j = 0; j < n; j++)
		{
			x = m[j].x - p[i].x;
			y = m[j].y - p[i].y;
			d = abs(gcd(x, y));
			x /= d;
			y /= d;
			
			pii pk = mp(x, y);
			tmpMap[pk].push_back(mp(d, j));
		}
		
		for (map<pii, vector<pii> >::iterator iter = tmpMap.begin(); iter != tmpMap.end(); iter++)
		{
			vector<pii> &curVec = iter->second;
			sort(curVec.begin(), curVec.end());
			vector<int> tmpVec;
			for (l = 0; l < curVec.size(); l++)
			{
				pointLst[i][curVec[l].second] = tmpVec;
				tmpVec.push_back(curVec[l].second);
			}
		}
	}
	
	
	ans = 0;
	deque<int> Q;
	int markNum = 0, placeIdx;
	bool out;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			pm[j] = j;
		}
		
		bool ok = false;
		do 
		{
			++markNum;
			Q.clear();
			Q.push_back(i);
			mark[i] = markNum;
			out = false;
			for (j = 0; j < k && !out; j++)
			{
				placeIdx = pm[j];
				if (Q.empty())
				{
					break;
				}
				u = Q.front();
				Q.pop_front();
				
				for (vector<int>::iterator iter = pointLst[placeIdx][u].begin(); iter != pointLst[placeIdx][u].end(); iter++)
				{
					if (mark[*iter] != markNum)
					{
						mark[*iter] = markNum;
						Q.push_back(*iter);
						
						if (Q.size() > k - j)
						{
							out = true;
							break;
						}
					}
				}
			}
			
			if (Q.empty())
			{
				ok = true;
			}
			
		} while (next_permutation(pm, pm + k) && !ok);
		
		if (ok)
		{
			ans++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}