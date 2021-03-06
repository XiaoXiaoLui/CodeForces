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

int a[30][30];

int f[20] = {1, 2, 3, 5, 8, 13, 21, 30, 39, 53, 74, 95, 128, 152, 182, 212, 258, 316, 374, 413};

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			a[i][j] = a[j][i] = f[i] + f[j];
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	return 0;
}