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

const int N = 1e5 + 50;
//int a[N];
int ans[N];

int main()
{
	int n, i, a;
	scanf("%d", &n);
	int xorSum = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		a--;
		xorSum ^= a;
		if (xorSum & 1)
		{
			ans[i] = 1;
		}
		else
		{
			ans[i] = 2;
		}
	}
	
	for (i = 0; i < n; i++)
	{
		printf("%d\n", ans[i]);
	}

	return 0;
}

/*
0 0
1 0
2 1
3 2
*/