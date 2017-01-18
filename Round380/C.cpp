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
int c[N];
int v[N];
int state[N];
int n, stateNum, s, t;

bool ok(int cap)
{
	int i;
	ll sumTime = 0, curLen;
	for (i = 1; i <= stateNum; i++)
	{
		curLen = state[i] - state[i - 1];
		if (curLen * 2 < cap)
		{
			sumTime += curLen;
		}
		else if (curLen > cap)
		{
			return false;
		}
		else
		{
			sumTime += 3 * curLen - cap;
		}
	}
	
	return sumTime <= t;
}

int main()
{
	// USE_IOSTREAM;
	int n, i, left, right, mid;
	
	scanf("%d%d%d%d", &n, &stateNum, &s, &t);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &c[i], &v[i]);
	}
	
	for (i = 1; i <= stateNum; i++)
	{
		scanf("%d", &state[i]);
	}
	
	if (s > t)
	{
		printf("-1\n");
		return 0;
	}
	
	state[0] = 0;
	state[++stateNum] = s;
	sort(state, state + stateNum + 1);
	
	right = 1e9;
	left = 0;
	
	if (!ok(right))
	{
		printf("-1\n");
		return 0;
	}
	
	while (right - left > 1)
	{
		mid = (right + left) / 2;
		if (ok(mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	
	int ans = -1;
	for (i = 1; i <= n; i++)
	{
		if (v[i] >= right && (ans == -1 || c[i] < ans))
		{
			ans = c[i];
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}