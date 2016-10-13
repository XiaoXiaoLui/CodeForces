#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1005;
const int MAX_DIV_COUNT = 7000;
const int MAX_PRIME_COUNT = 20;
const int INF = 1e9;

ll a[N];
map<ll, int> hash;

pair<ll, int> prime[MAX_PRIME_COUNT];
int primeCount;

int pre[N][MAX_DIV_COUNT];
int decmp[N][MAX_PRIME_COUNT];
int mul[N];

int divCount;

struct DpInfo
{
	DpInfo(){}
	DpInfo(int c, ll s, int chs) : cnt(c), sum(s), chosen(chs)
	{
	}
	
	bool operator < (const DpInfo &other) const
	{
		if (cnt != other.cnt)
		{
			return cnt < other.cnt;
		}
		
		if (sum != other.sum)
		{
			return sum < other.sum;
		}
		
		return false;
	}
	
	int cnt;
	ll sum;
	int chosen;
};

DpInfo dp[N][MAX_DIV_COUNT];

void getDivisors(int n, ll k)
{
	int i, j;
	for (i = 2; (ll)i * i <= k; i++)
	{
		if (k % i == 0)
		{
			++primeCount;
			prime[primeCount] = make_pair<ll, int>(i, 0);
			while (k % i == 0)
			{
				prime[primeCount].second++;
				k /= i;
			}
		}
	}
	
	if (k != 1)
	{
		++primeCount;
		prime[primeCount] = make_pair<ll, int>(k, 1);
	}
	
	// decmp for gcd for each a[i]
	for (i = 1; i <= n; i++)
	{
		ll x = a[i];
		for (j = 1; j <= primeCount; j++)
		{
			while (x % prime[j].first == 0)
			{
				decmp[i][j]++;
				x /= prime[j].first;
			}
		}
	}
	
	divCount = 1;
	for (i = 1; i <= primeCount; i++)
	{
		divCount *= prime[i].second + 1;
	}
	
	mul[1] = 1;
	for (i = 2; i <= primeCount; i++)
	{
		mul[i] = mul[i - 1] * (1 + prime[i - 1].second);
	}
	
}


int main()
{
	int n, i, j, idx, last, x;
	ll k;
	scanf("%d%lld", &n, &k);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	
	if (k == 1)
	{
		int minIndex = 1;
		for (i = 2; i <= n; i++)
		{
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
		}
		
		printf("1\n%d\n", minIndex);
		return 0;
	}
	
	getDivisors(n, k);
	
	for (i = 1; i < divCount; i++)
	{
		dp[0][i] = DpInfo(INF, 0, 0);
	}
	dp[0][0] = DpInfo(0, 0, 0);
	
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < divCount; j++)
		{
			x = j;
			last = 0;
			for (int l = primeCount; l >= 1; l--)
			{
				last += mul[l] * max(0, x / mul[l] - decmp[i][l]);
				x %= mul[l];
			}
			
			
			DpInfo info = dp[i - 1][last];
			info.cnt++;
			info.sum += a[i];
			info.chosen = 1;
			
			if (info < dp[i - 1][j])
			{
				dp[i][j] = info;
				pre[i][j] = last;
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
				dp[i][j].chosen = 0;
				pre[i][j] = j;
			}
		}
	}
	
	//idx = hash[k];
	if (dp[n][divCount - 1].cnt == INF)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", dp[n][divCount - 1].cnt);
		
		idx = divCount - 1;
		for (i = n; i >= 1; i--)
		{
			if (dp[i][idx].chosen)
			{
				printf("%d ", i);
			}
			idx = pre[i][idx];
		}
		
		printf("\n");
	}
	
	
	return 0;
}