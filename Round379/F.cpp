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

const int N = 2e5 + 100;
const int M = 31;

ll a[N];
ll b[N];
ll c[N];
ll d[N];
int cnt[60];

int main()
{
	// USE_IOSTREAM;
	int n, i, j;
	ll sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &b[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &c[i]);
	}
	for (i = 1; i <= n; i++)
	{
		d[i] = b[i] + c[i];
		sum += d[i];
	}
	
	sum /= 2*n;
	
	for (i = 1; i <= n; i++)
	{
		a[i] = (d[i] - sum) / n;
		if (a[i] < 0)
		{
			printf("-1\n");
			return 0;
		}
		
		for (j = 0; j < M; j++)
		{
			cnt[j] += (a[i] >> j) & 1;
		}
	}
	
	bool ok = true;
	ll curB, curC;
	for (i = 1; i <= n; i++)
	{
		curB = curC = 0;
		for (j = 0; j < M; j++)
		{
			sum = ((a[i] >> j) & 1) ? cnt[j] : 0;
			curB += sum << j;
			
			sum = ((a[i] >> j) & 1) ? n : cnt[j];
			curC += sum << j;
		}
		
		if (curB != b[i] || curC != c[i])
		{
			ok = false;
			break;
		}
	}
	
	if (!ok)
	{
		printf("-1\n");
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			printf("%lld ", a[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}