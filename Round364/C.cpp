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

const int N = 1e5 + 5;
char s[N];
int sum[130];
int main()
{
	int n, i, j, count;
	int ans = 1e9;
	scanf("%d", &n);
	scanf("%s", s);
	for (i = 0, count = 0; i < n; i++)
	{
		sum[s[i]]++;
		if (sum[s[i]] == 1)
		{
			count++;
		}
	}
	
	fill(sum, sum + 130, 0);
	int curCount = 0;
	for (i = 0, j = -1; i < n && j < n; )
	{
		if (curCount < count)
		{
			j++;
			sum[s[j]]++;
			if (sum[s[j]] == 1)
			{
				curCount++;
			}
		}
		else
		{
			ans = min(ans, j - i + 1);
			sum[s[i]]--;
			if (sum[s[i]] == 0)
			{
				curCount--;
			}
			i++;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}