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

ll divs[MAX_DIV_COUNT];
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

void getDivisors(ll k)
{
	int i;
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
	
	int curExp[MAX_PRIME_COUNT];
	fill(curExp, curExp + MAX_PRIME_COUNT, 0);
	ll product;
	
	divs[0] = 1;
	hash[1] = 0;
	while (1)
	{
		i = 1;
		curExp[i]++;
		
		while (i <= primeCount && curExp[i] > prime[i].second)
		{
			curExp[i] = 0;
			++i;
			curExp[i]++;
		}
		
		if (i > primeCount)
		{
			break;
		}
		
		++divCount;
		for (product = 1, i = 1; i <= primeCount; i++)
		{
			for (int j = curExp[i]; j > 0; j--)
			{
				product *= prime[i].first;
			}
		}
		divs[divCount] = product;
		hash[product] = divCount;
	}
	
	
}

inline ll gcd(ll a, ll b)
{
	ll c;
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	
	return a;
}

int main()
{
	int n, i, j, idx;
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
		
		printf("1\n%lld\n", minIndex);
		return 0;
	}
	
	getDivisors(k);
	
	for (i = 1; i <= divCount; i++)
	{
		dp[0][i] = DpInfo(INF, 0, 0);
	}
	dp[0][0] = DpInfo(0, 0, 0);
	
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= divCount; j++)
		{
			ll tmp = gcd(divs[j], a[i]);
			idx = hash[divs[j] / tmp];
			
			DpInfo info = dp[i - 1][idx];
			info.cnt++;
			info.sum += a[i];
			info.chosen = 1;
			
			if (info < dp[i - 1][j])
			{
				dp[i][j] = info;
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
				dp[i][j].chosen = 0;
			}
		}
	}
	
	//idx = hash[k];
	if (dp[n][divCount].cnt == INF)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", dp[n][divCount].cnt);
		
		idx = divCount;
		for (i = n; i >= 1 && k != 1; i--)
		{
			if (dp[i][idx].chosen)
			{
				printf("%d ", i);
				k /= gcd(k, a[i]);
				idx = hash[k];
			}
		}
		
		printf("\n");
	}
	
	
	return 0;
}