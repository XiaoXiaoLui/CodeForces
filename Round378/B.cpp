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

const int N = 1e5 + 100;
int l[N];
int r[N];


int main()
{
	// USE_IOSTREAM;
	int n, i, diff;
	scanf("%d", &n);
	diff = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		diff += l[i] - r[i];
	}
	
	int ans = 0;
	int oldDiff = diff;
	for (i = 1; i <= n; i++)
	{
		if (abs(diff) < abs(oldDiff - 2* (l[i] - r[i])))
		{
			ans = i;
			diff = oldDiff - 2* (l[i] - r[i]);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}