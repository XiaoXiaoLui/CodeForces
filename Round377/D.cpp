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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1e5 + 100;

int a[N];
int d[N];
bool visit[N];
int n, m, i, j;
ll tot;

bool ok(int end)
{
	int i;
	ll curSum = tot;
	memset(visit, 0, sizeof(visit));
	for (i = end; i >= 1; i--)
	{
		if (curSum > i)
		{
			return false;
		}
		
		if (d[i] != 0 && !visit[d[i]])
		{
			visit[d[i]] = true;
			curSum -= a[d[i]] + 1;
		}
	}
	
	return curSum == 0;
}

int main()
{
	USE_IOSTREAM;
	
	cin >> n >> m;
	
	for (i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	
	tot = 0;
	for (i = 1; i <= m; i++)
	{
		cin >> a[i];
		tot += a[i];
	}
	
	tot += m;
	if (tot > n || !ok(n))
	{
		cout << -1 << endl;
		return 0;
	}
	
	int left = tot - 1, right = n, mid; 
	while (right - left > 1)
	{
		mid = (left + right) / 2;
		if (ok(mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	
	cout << right << endl;
	return 0;
}