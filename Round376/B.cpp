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

const int N = 2e5 + 100;
int a[N];

int main()
{
	// USE_IOSTREAM;
	int n, i;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	bool ok = true;
	for (i = 1; i <= n && ok; i++)
	{
		if (a[i] < 0)
		{
			ok = false;
			break;
		}
		
		if (a[i] & 1)
		{
			if (i == n)
			{
				ok = false;
				break;
			}
			a[i + 1]--;
		}
	}
	
	if (ok)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}