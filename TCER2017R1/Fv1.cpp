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

const int N = 800;
const int M = 2e5 + 100;

ll a[N];
ll q[M];
int srt[M];
ll minStart[N];
int ans[M];
int n, m;

bool ok(ll start, int maxCnt)
{
	multiset<ll> S;
	ll curSum = start;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		S.insert(a[i]);
		curSum += a[i];
		if (curSum < 0)
		{
			curSum -= *S.begin();
			S.erase(S.begin());
			cnt++;
		}
	}
	
	return cnt <= maxCnt;
}

bool cmp(int i, int j)
{
	return q[i] > q[j];
}

// O(n^2lognlogm + m)
int main()
{
	int i, j, left, right, mid;
	ll b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%lld", &b);
		q[i] = b;
		srt[i] = i;
	}
	q[0] = 1e18;
	srt[0] = 0;
	q[m + 1] = -1e18;
	srt[m + 1] = m + 1;
	
	sort(srt, srt + m + 1, cmp);
	
	for (i = 0; i <= n; i++)
	{
		left = 0;
		right = m + 1;
		while (right - left > 1)
		{
			mid = (left + right) / 2;
			if (ok(q[srt[mid]], i))
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
		minStart[i] = q[srt[left]];
	}
	
	for (i = 1, j = 0; i <= m && j <= n; )
	{
		if (q[srt[i]] >= minStart[j])
		{
			ans[srt[i]] = j;
			i++;
		}
		else
		{
			j++;
		}
	}

	
	for (i = 1; i <= m; i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}