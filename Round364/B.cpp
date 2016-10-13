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
int n, m;
ll ans[N];

int rowCount, colCount;
bool row[N];
bool col[N];

int main()
{
	int i, x, y;
	scanf("%d%d", &n, &m);
	ll cur = (ll)n * n;
	
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		if (!row[x])
		{
			cur -= n - colCount;
			rowCount++;
		}
		
		if (!col[y])
		{
			cur -= n - rowCount;
			colCount++;
		}
		
		ans[i] = cur;
		row[x] = true;
		col[y] = true;
	}
	
	for (i = 0; i < m; i++)
	{
		printf("%lld ", ans[i]);
	}
	printf("\n");
	
	
	printf("\n");
	return 0;
}