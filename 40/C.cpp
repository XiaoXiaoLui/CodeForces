#include <cstdio>
#include <algorithm>

using namespace std;

#define LLD "%l" "ld"

typedef long long ll;

ll llabs(ll a, ll b)
{
	ll res = a - b;
	return res >= 0 ? res : -res;
}

int main()
{
	ll N, M, X, Y, MR, orgN, start, end, NR;
	scanf(LLD LLD LLD LLD, &N, &X, &M, &Y);
	
	ll ans = M + 1;
	ll d = llabs(X - Y);
	
	ll left, right, r1, r2;
	for (int i = 1; i <= N; i++)
	{
		if (d - i >= M || i - d >= M)
		{
			ans++;
			continue;
		}
		
		if (d - i >= 0)
		{
			left = d - i + 1;
		}
		else
		{
			left = i - d;
			ans--;
		}
		
		r1 = d + i;
		r2 = M;
		right = min(r1, r2);
		
		ans += 2 * (right - left);
		if (r1 > r2)
		{
			ans += 2;
		}
	}
	
	
	printf(LLD "\n", ans);
	return 0;
}