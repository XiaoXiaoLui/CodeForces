#include <cstdio>
#include <algorithm>

using namespace std;

#define LLD "%l" "ld"
//#define LLD "%I64d"

typedef long long ll;
const int N = 3005;

struct Marble
{
	ll x;
	ll c;
	bool operator < (const Marble &other) const
	{
		return x < other.x;
	}
};

Marble a[N];

ll dp[N];
ll ans[N];
int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf(LLD LLD, &a[i].x, &a[i].c);
	}
	
	sort(a, a + n);
	
	ans[0] = a[0].c;
	dp[0] = a[0].c;
	for (i = 1; i < n; i++)
	{
		ans[i] = (ll)1e18;
		dp[i] = ans[i - 1] + a[i].c;
		ans[i] = min(ans[i], dp[i]);
		for (j = 0; j < i; j++)
		{
			dp[j] = dp[j] + a[i].x - a[j].x;
			ans[i] = min(ans[i], dp[j]);
		}
	}
	printf(LLD "\n", ans[n - 1]);
}