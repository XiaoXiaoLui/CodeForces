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
set<pii> S;
pii ans[N];
bool used[N];

int main()
{
	int n, i, sum, j;
	scanf("%d", &n);
	for (i = 1, sum = 0; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		S.insert(mp(a[i], i));
	}
	
	sum /= n / 2;
	pii cur;
	set<pii>::iterator iter;
	for (i = 1, j = 0; i <= n; i++)
	{
		if (!used[i])
		{
			S.erase(mp(a[i], i));
			cur.first = i;
			iter = S.lower_bound(mp(sum - a[i], 0));
			cur.second = iter->second;
			ans[j++] = cur;
			S.erase(iter);
			used[cur.second] = true;
		}
	}
	
	for (i = 0; i < n / 2; i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	
	printf("\n");
	return 0;
}