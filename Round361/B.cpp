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

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 200005;
int a[N];
int d[N];

int main()
{
	int n, i, j, pos;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	fill(d, d + N, -1);
	d[1] = 0;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty())
	{
		pos = Q.front();
		Q.pop();
		if (pos + 1 <= n && d[pos + 1] == -1)
		{
			d[pos + 1] = d[pos] + 1;
			Q.push(pos + 1);
		}
		
		if (pos - 1 > 1 && d[pos - 1] == -1)
		{
			d[pos - 1] = d[pos] + 1;
			Q.push(pos - 1);
		}
		
		if (d[a[pos]] == -1)
		{
			d[a[pos]] = d[pos] + 1;
			Q.push(a[pos]);
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		printf("%d ", d[i]);
	}
	
	printf("\n");
	return 0;
}