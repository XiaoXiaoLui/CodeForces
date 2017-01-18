#include<bits/stdc++.h>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 1000;

ll f[N];

int main()
{
	// USE_IOSTREAM;
	int i;
	ll n;
	scanf("%lld", &n);
	f[1] = 1;
	for (i = 2; true; i++)
	{
		f[i] = f[i - 1] + f[i - 2] + 1;
		if (f[i] >= n)
		{
			break;
		}
	}	
	
	printf("%d\n", i - 1);
	
	return 0;
}