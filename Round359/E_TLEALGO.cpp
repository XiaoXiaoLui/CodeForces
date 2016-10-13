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
const ll INF = 4e18;
const ll MAX = 1e18;
const ll MIN = -1e18;
const ll DIR[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

int n;
ll x[N];
ll y[N];
ll z[N];
vector<ll> ansX;
vector<ll> ansY;
vector<ll> ansZ;
vector<ll> count1;
vector<ll> count2;
vector<int> errorCase;


ll minX, maxX, minY, maxY, minZ, maxZ;

inline ll llabs(const ll &a, const ll &b)
{
	ll res = a - b;
	return res >= 0 ? res : -res;
}

inline ll calFun(const ll &X, const ll &Y, const ll &Z)
{
	ll maxDist = 0;
	
	double tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = (double)llabs(x[i] - X) + llabs(y[i] - Y) + llabs(z[i] - Z);
		if (tmp > INF)
		{
			maxDist = INF;
		}
		else
		{
			maxDist = max(maxDist, (ll)tmp);
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		maxDist = max(maxDist, llabs(x[i] - X) + llabs(y[i] - Y) + llabs(z[i] - Z));
	}*/
	return maxDist;
}

inline void solve(int id, const ll &initX, const ll &initY, const ll &initZ)
{
	ll curX, curY, curZ, nextX, nextY, nextZ, curDist, nextDist;
	ll d = MAX;
	bool needModify;
	curX = initX;
	curY = initY;
	curZ = initZ;
	curDist = calFun(curX, curY, curZ);
	ll c1 = 0, c2 = 0;;
	while (d >= 1)
	{
		c1++;
		needModify = true;
		for (int k = 0; k < 6; k++)
		{
			c2++;
			nextX = curX + DIR[k][0]*d;
			nextY = curY + DIR[k][1]*d;
			nextZ = curZ + DIR[k][2]*d;
			
			nextDist = calFun(nextX, nextY, nextZ);
			if (nextDist < curDist)
			{
				curDist = nextDist;
				needModify = false;
				curX = nextX;
				curY = nextY;
				curZ = nextZ;
				break;
			}
		}
		if (needModify)
		{
			if (d == 1)
			{
				break;
			}
			d = d * 2 / 3;
		}
#ifdef DEBUG
		if (c2 > 2000)
		{
			errorCase.push_back(id);
			break;
		}
#endif
	}
	ansX.push_back(curX);
	ansY.push_back(curY);
	ansZ.push_back(curZ);
#ifdef DEBUG
	count1.push_back(c1);
	count2.push_back(c2);
#endif
}

int main()
{
	int t, i, k;
	double initX, initY, initZ;
	scanf("%d", &t);
	
#ifdef DEBUG
	if (t == 33333)
	{
		ll a, b, c;
		for (k = 0; k < t; k++)
		{
			scanf("%d", &n);
			//printf("%d\n", n);
			for (i = 0; i < n; i++)
			{
				scanf(LLD LLD LLD, &a, &b, &c);
				if (k == 147 || k == 163)
				{
					printf(LLD " " LLD " " LLD "\n", a, b, c);
				}
			}
		}
		return 0;
	}
#endif
	for (k = 0; k < t; k++)
	{
		scanf("%d", &n);
		minX = minY = minZ = MAX;
		maxX = maxY = maxZ = MIN;
		initX = initY = initZ = 0; 
		for (i = 0; i < n; i++)
		{
			scanf(LLD LLD LLD, &x[i], &y[i], &z[i]);
			initX += x[i];
			initY += y[i];
			initZ += z[i];
			minX = min(minX, x[i]);
			maxX = max(maxX, x[i]);
			minY = min(minY, y[i]);
			maxY = max(maxY, y[i]);
			minZ = min(minZ, z[i]);
			maxZ = max(maxZ, z[i]);
			
		}
		initX /= n;
		initY /= n;
		initZ /= n;
		solve(k, (ll)initX, (ll)initY, (ll)initZ);
	}
#ifndef DEBUG
	for (i = 0; i < errorCase.size(); i++)
	{
		printf("%d ", errorCase[i]);
	}
	printf("\n");
#endif
	
	for (i = 0; i < t; i++)
	{
#ifdef DEBUG
		printf(LLD " " LLD " " LLD " " LLD " " LLD "\n", ansX[i], ansY[i], ansZ[i], count1[i], count2[i]);
#else
		printf(LLD " " LLD " " LLD "\n", ansX[i], ansY[i], ansZ[i]);
#endif
		
	}
	

	return 0;
}
