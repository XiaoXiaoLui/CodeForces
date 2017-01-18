// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

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

const int N = 1e5 + 10;
const int M = 400;

int pre[N];
int ans[N];
bool isPrime[M];
vector<int> prime;
vector<pii> split;
vector<int> divisors;


void dfsCalDivisors(int curIdx, int preProduct)
{
	if (curIdx == split.size())
	{
		divisors.push_back(preProduct);
		return;
	}
	
	int curProduct = preProduct;
	for (int i = 0; i <= split[curIdx].second; i++)
	{
		dfsCalDivisors(curIdx + 1, curProduct);
		curProduct *= split[curIdx].first;
	}
}

void solve(int idx, int x, int y)
{
	split.clear();
	divisors.clear();
	int tmp = x, i;
	for (i = 0; i < prime.size() && prime[i] * prime[i] <= tmp; i++)
	{
		if (tmp % prime[i] == 0)
		{
			pii div = {prime[i], 0};
			while (tmp % prime[i] == 0)
			{
				div.second++;
				tmp /= prime[i];
			}
			split.push_back(div);
		}
	}
	
	if (tmp > 1)
	{
		split.push_back({tmp, 1});
	}
	
	dfsCalDivisors(0, 1);
	
	// now divisors contains all divisors of x
	for (auto div : divisors)
	{
		if (pre[div] < idx - y)
		{
			ans[idx]++;
		}
		pre[div] = idx;
	}
}

int main()
{
	// USE_IOSTREAM;
	int i, j, x, y, n;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif
	
	fill_n(isPrime, M, true);
	for (i = 2; i < M; i++)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
			for (j = i + i; j < M; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		solve(i, x, y);
	}
	
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}