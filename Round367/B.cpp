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

const int N = 1e5 + 100;
int x[N];
int q[N];
int ans[N];

int main()
{
	int n, m, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &q[i]);
	}
	
	for (i = 0; i < m; i++)
	{
		ans[i] = upper_bound(x, x + n, q[i]) - x;
	}
	
	for (i = 0; i < m; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}