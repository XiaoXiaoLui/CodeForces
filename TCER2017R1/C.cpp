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

const int N = 5050;

int sum[N];
int a[N];

int main()
{
	int n, i, j, c;
	
	scanf("%d", &n);

	for (i = 2; i <= n; i++)
	{
		printf("? %d %d\n", i, i - 1);
		fflush(stdout);
		scanf("%d", &sum[i]);
	}
	
	printf("? 1 3\n");
	fflush(stdout);
	scanf("%d", &c);
	
	a[1] = (sum[2] + sum[3] + c) / 2 - sum[3];
	for (i = 2; i <= n; i++)
	{
		a[i] = sum[i] - a[i - 1];
	}
	
	printf("! ");
	for (i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}