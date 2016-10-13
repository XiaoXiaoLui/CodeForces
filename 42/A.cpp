#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 105;
int a[N];
int b[N];

int main()
{
	int n, V, i, sum;
	double x, ans;
	scanf("%d%d", &n, &V);
	for (i = 0, sum = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	
	x = (double)V / sum;
	for (i = 0; i < n; i++)
	{
		x = min(x, (double)b[i] / a[i]);
	}
	
	ans = x * sum;
	
	printf("%.8lf\n", ans);
	return 0;
}