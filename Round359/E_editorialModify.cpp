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

#define pll pair<ll, ll>
#define mpl make_pair<ll, ll>

const int N = 1e5 + 5;
const ll INF = (((unsigned long long)1) << 63) - 2;
const ll MAX = 8e18;
const ll MIN = -8e18;


struct Solution
{
	Solution(){}
	Solution(ll a, ll b, ll c) : x(a), y(b), z(c)
	{
	}
	ll x;
	ll y;
	ll z;
};

/* for 4 inequation 
S x+y+z
A -x+y+z
B x-y+z
C x+y-z

x = (B+C)/2
y = (A+C)/2
z = (A+B)/2

*/
struct Space
{
	Space()
	{
		S = mpl(MIN, MAX);
		A = mpl(MIN, MAX);
		B = mpl(MIN, MAX);
		C = mpl(MIN, MAX);
	}
	
	void intersect(const Space &s2)
	{
		Space &s1 = *this;
		S = mpl(max(s1.S.first, s2.S.first), min(s1.S.second, s2.S.second));
		A = mpl(max(s1.A.first, s2.A.first), min(s1.A.second, s2.A.second));
		B = mpl(max(s1.B.first, s2.B.first), min(s1.B.second, s2.B.second));
		C = mpl(max(s1.C.first, s2.C.first), min(s1.C.second, s2.C.second));
		
	}
	
	bool containPoint(const Solution &sol) const
	{
		ll a, b, c, s;
		s = sol.x + sol.y + sol.z;
		a = -sol.x + sol.y + sol.z;
		b = sol.x - sol.y + sol.z;
		c = sol.x + sol.y - sol.z;
		
		return (s >= S.first && s <= S.second && a >= A.first && a <= A.second && b >= B.first && b <= B.second && c >= C.first && c <= C.second);
	}
	
	
	// overflow?
	bool findSolution(Solution &sol) const
	{
		if (S.first > S.second || A.first > A.second || B.first > B.second || C.first > C.second)
		{
			return false;;
		}
		else if (A.first + B.first + C.first > S.second || A.second + B.second + C.second < S.first)
		{
			return false;
		}
		
		ll a, b, c, s, offset;
		
		s = S.first;
		a = A.first;
		b = B.first;
		c = C.first;
		
		// may have overflow problem ?
		offset = max((ll)0, S.first - a - b - c);
		a += min(offset, A.second - A.first);
		offset -= min(offset, A.second - A.first);
		
		b += min(offset, B.second - B.first);
		offset -= min(offset, B.second - B.first);
		
		c += min(offset, C.second - C.first);
		offset -= min(offset, C.second - C.first);
		
		
		// now offset should be zero
		ll initX, initY, initZ, curX, curY, curZ;
		
		initX = (b + c) / 2;
		initY = (a + c) / 2;
		initZ = (a + b) / 2;
		
		for (curX = initX - 1; curX <= initX + 1; curX++)
		{
			for (curY = initY - 1; curY <= initY + 1; curY++)
			{
				for (curZ = initZ - 1; curZ <= initZ + 1; curZ++)
				{
					Solution tmp(curX, curY, curZ);
					if (containPoint(tmp))
					{
						sol = tmp;
						return true;
					}
				}
			}
		}
		
		return false;
	}
	
	pll S;
	pll A;
	pll B;
	pll C;
	
};




int n;
ll x[N];
ll y[N];
ll z[N];
vector<ll> ansX;
vector<ll> ansY;
vector<ll> ansZ;


bool findAns(const ll &maxDist, Solution &sol)
{
	int i, j, k;
	bool res = true;
	ll midX, midY, midZ, curX, curY, curZ;
	
	Space curSpace;
	Space tmp;
	for (i = 0; i < n; i++)
	{
		tmp.S = mpl(x[i] + y[i] + z[i] - maxDist, x[i] + y[i] + z[i] + maxDist);
		tmp.A = mpl(-x[i] + y[i] + z[i] - maxDist, -x[i] + y[i] + z[i] + maxDist);
		tmp.B = mpl(x[i] - y[i] + z[i] - maxDist, x[i] - y[i] + z[i] + maxDist);
		tmp.C = mpl(x[i] + y[i] - z[i] - maxDist, x[i] + y[i] - z[i] + maxDist);
		
		curSpace.intersect(tmp);
	}
	
	return curSpace.findSolution(sol);
}


inline void solve()
{
	ll left ,right, mid;
	left = -1;
	right = (ll)3e18 + 1;
	
	Solution sol;
	while (right - left > 1)
	{
		mid = (right + left) / 2;
		if (findAns(mid, sol))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	
	ansX.push_back(sol.x);
	ansY.push_back(sol.y);
	ansZ.push_back(sol.z);
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