#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

//#define LLD "%l" "ld"
#define LLD "%I64d"

typedef long long ll;


pair<int, ll> ans;

inline ll cube(ll a)
{
	return a*a*a;
}

void find(ll m, int steps, ll sum)
{
	if (!m)
	{
		ans = max(ans, make_pair(steps, sum));
		return;
	}
	
	//ll a = (int)pow(m, 1.0 / 3);
	ll a = 1;
	while (cube(a + 1) <= m)
	{
		a++;
	}
	
	find(m - cube(a), steps + 1, sum + cube(a));
	if (a - 1 >= 1)
	{
		find(cube(a) - 1 - cube(a - 1), steps + 1, sum + cube(a - 1));
	}
}

int main()
{
	ll m;
	scanf(LLD, &m);
	find(m, 0, 0);
	printf("%d " LLD " \n", ans.first, ans.second);
	
	return 0;
}