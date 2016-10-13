#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

//#define DEBUG

#define LLD "%l" "ld"
//#define LLD "%I64d"

typedef long long ll;

#define pii pair<int, int>
#define mp make_pair<int, int>

#define pll pair<ll, ll>
#define mpl make_pair<ll, ll>

const int N = 1e5 + 5;
const ll MAX = 8e18;
const ll MIN = -8e18;
//const ll DIR[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

/* for 2 inequation 
A x+y
B x-y


dist(x,y,z, x1, y1, z1) <= D
h = abs(z - z1)
equal to
dist(x,y,  x1-h, y1) <= D
dist(x,y,  x1+h, y1) <= D
dist(x,y,  x1, y1-h) <= D
dist(x,y,  x1, y1+h) <= D
so transform 3D to 2D.
*/

int n;
ll x[N];
ll y[N];
ll z[N];
vector<ll> ansX;
vector<ll> ansY;
vector<ll> ansZ;

inline ll llabs(const ll &a, const ll &b)
{
	ll res = a - b;
	return (res >= 0 ? res : -res);
}

inline ll calDist(ll z0, pll &xy)
{
	ll minA, maxA, minB, maxB, h, dist2, a, b;
	int i, j, k;
	
	minA = minB = MAX;
	maxA = maxB = MIN;
	for (i = 0; i < n; i++)
	{
		h = llabs(z0, z[i]);
		minA = min(minA, x[i] + y[i] - h);
		maxA = max(maxA, x[i] + y[i] + h);
		minB = min(minB, x[i] - y[i] - h);
		maxB = max(maxB, x[i] - y[i] + h);
	}
	
	// dist * 2
	dist2 = max(maxA - minA, maxB - minB);
	a = (maxA + minA) / 2;
	b = (maxB + minB) / 2;
	xy.first = (a + b) / 2;
	xy.second = (a - b) / 2;
	
	return dist2;
}


inline void solve()
{
	int i;
	
	// tenary search for z, find the z of minDist
	ll left = -1e18;
	ll right = 1e18;
	ll mid1, mid2;
	pll xy;
	while (right - left > 4)
	{
		mid1 = (left + left + right) / 3;
		mid2 = (left + right + right) / 3;
		
		
		// if there is case where == , ternary search may be wrong
		if (calDist(mid1, xy) < calDist(mid2, xy))
		{
			right = mid2;
		}
		else
		{
			left = mid1;
		}
	}
	
	ll bestZ, bestY, bestX, bestDist, curDist, curY, curX, initX, initY, curZ;
	bestDist = MAX;
	for (curZ  = left; curZ <= right; curZ++)
	{
		curDist = calDist(curZ, xy);
		if (curDist < bestDist)
		{
			bestDist = curDist;
			bestZ = curZ;
			initX = xy.first;
			initY = xy.second;
		}
	}
	
	bestDist = MAX;
	for (curX = initX - 1; curX <= initX + 1; curX++)
	{
		for (curY = initY - 1; curY <= initY + 1; curY++)
		{
			curDist = 0;
			for (i = 0; i < n; i++)
			{
				curDist = max(curDist, llabs(x[i] - curX) + llabs(y[i] - curY) + llabs(bestZ - z[i]));
			}
			if (curDist < bestDist)
			{
				bestDist = curDist;
				bestX = curX;
				bestY = curY;
			}
		}
	}		
	
	ansX.push_back(bestX);
	ansY.push_back(bestY);
	ansZ.push_back(bestZ);
}

int main()
{
	int t, i, k;
	scanf("%d", &t);
	for (k = 0; k < t; k++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf(LLD LLD LLD, &x[i], &y[i], &z[i]);
		}
		solve();
	}
	for (i = 0; i < t; i++)
	{
#ifdef DEBUG
		printf(LLD " " LLD " " LLD " " LLD " " LLD "\n", ansX[i], ansY[i], ansZ[i], count1[i], count2[i]);
#else
		printf(LLD " " LLD " " LLD "\n", ansX[i], ansY[i], ansZ[i]);
#endif
		
	}
}