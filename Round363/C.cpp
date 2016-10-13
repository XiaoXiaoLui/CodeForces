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

const int N = 105;
int a[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	int last  = 0;
	int ans = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (i != 0)
		{
			if (last == 1)
			{
				if (a[i] & 2)
				{
					last = 2;
				}
				else
				{
					last = 0;
					ans++;
				}
			}
			else if (last == 2)
			{
				if (a[i] & 1)
				{
					last = 1;
				}
				else
				{
					last = 0;
					ans++;
				}
			}
			else
			{
				if (!a[i])
				{
					ans++;
				}
				last = a[i];
			}
		}
		else
		{
			if (!a[i])
			{
				ans++;
			}
			last = a[i];
		}
	}
	
	printf("%d\n", ans);
	return 0;
}