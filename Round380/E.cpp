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

int a[N];

void justForResubmit()
{
	
}

int main()
{
	// USE_IOSTREAM;
	int n, s, i, j, ans, curRange;
	scanf("%d%d", &n, &s);
	
	ans = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (i == s && a[i])
		{
			ans++;
			a[i] = 0;
		}
	}
	
	curRange = 1;
	for (i = 1; i <= n; i++)
	{
		if (i != s && !a[i])
		{
			a[i] = N;
		}
	}
	sort(a + 1, a + 1 + n);
	/*
	for (i = 2; i <= n && a[i] == 0; i++)
	{
		ans++;
		curRange++;
	}*/
	
	for (i = 2, j = n; i <= j; )
	{
		if (a[i] > curRange)
		{
			ans++;
			curRange++;
			j--;
		}
		else if (a[i] == curRange)
		{
			curRange++;
			i++;
		}
		else
		{
			i++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}