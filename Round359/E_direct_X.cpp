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

const int N = 1e5 + 5;
const ll MAX = 8e18;
const ll MIN = -8e18;
//const ll DIR[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

/* for 4 inequation 
a x + y + z
b -x + y + z
c x + -y + z
d x + y + -z

x = (d + c) / 2
y = (b + d) / 2
z = (b + c) / 2
*/
const int DIR[4][3] = {{1, 1, 1}, {-1, 1, 1}, {1, -1, 1}, {1, 1, -1}};
ll range[4][2];


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

inline void solve()
{
	int i, k, j, l;
	ll tmp, A, B, C, D, bestX, bestY, bestZ, curX, curY, curZ, bestDist, curDist, midX, midY, midZ;
	for (k = 0; k < 4; k++)
	{
		range[k][0] = MAX;
		range[k][1] = MIN;
	}
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < 4; k++)
		{
			tmp = x[i] * DIR[k][0] + y[i] * DIR[k][1] + z[i] * DIR[k][2];
			range[k][0] = min(range[k][0], tmp);
			range[k][1] = max(range[k][1], tmp);
		}
	}
	A = (range[0][0] + range[0][1]) / 2;
	B = (range[1][0] + range[1][1]) / 2;
	C = (range[2][0] + range[2][1]) / 2;
	D = (range[3][0] + range[3][1]) / 2;
	
	midX = (D + C) / 2;
	midY = (B + D) / 2;
	midZ = (B + C) / 2;
	
	int cx, cy, cz;
	bestDist = MAX;
	for (cx = -1; cx <= 1; cx++)
	{
		for (cy = -1; cy <= 1; cy++)
		{
			for (cz = -1; cz <= 1; cz++)
			{
				curX = midX + cx;
				curY = midY + cy;
				curZ = midZ + cz;
				curDist = 0;
				for (i = 0; i < n; i++)
				{
					tmp = llabs(x[i] - curX) + llabs(y[i] - curY) + llabs(z[i] - curZ);
					curDist = max(curDist, tmp);
				}
				if (curDist < bestDist)
				{
					bestDist = curDist;
					bestX = curX;
					bestY = curY;
					bestZ = curZ;
				}
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