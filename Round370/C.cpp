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

int main()
{
	int x, y, a, b, c, oldA, oldB, oldC;
	scanf("%d%d", &x, &y);
	if (x > y)
	{
		swap(x, y);
	}
	a = b = c = x;
	
	int ans = 0;
	while (a < y)
	{
		oldA = a;
		oldB = b;
		oldC = c;
		a = min(y, b + c - 1);
		c = a;
		a = oldB;
		b = oldC;
		ans++;
	}
	
	printf("%d\n", ans);
	return 0;
}