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
	
	ll ans = 0LL;
	ll d = llabs(X - Y);
	ll offset;
	
	if (d >= N)
	{
		swap(N, M);
	}
	
	MR = M - min(d, M);
	M = min(d, M);
	orgN = N;

	ans = M + 1;
	
	offset = min(N, d - M);
	ans += offset;
	N -= offset;
		
	offset = min(N, M);
	ans += offset * (offset + 1);
	N -= offset;
		
	offset = min(N, M);
	// 2*M - 1 + 2*(M-1) - 1 + 2*(M-offset+1) - 1
	ans += (2*M - offset) * offset;
	N -= offset;
		
	ans += N;
	
	
	N = max(0LL, orgN - 2*d);
	offset = min(MR, N);
	
	ans += (4*M - 1) * offset;
	MR -= offset;
	NR = orgN - offset;
	
	start = min(4*M - 1, 2*orgN - 1);
	offset = min(MR, NR);
	// start + start - 2 + start - (2*offset) + 2
	// (2*start-2*offset+2)*offset/2
	
	ans += (start - offset + 1)*offset;
	MR -= offset;
	ans += MR;
	
	printf(LLD "\n", ans);
	return 0;
}