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

int c[3];

inline int cal(int a)
{
	int sum = 0;
	while (a)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum % 3;
}

int main()
{
	int n, i, a;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		c[cal(a)]++;
	}
	
	
	
	printf("%d\n", c[0] / 2 + min(c[1], c[2]));
	return 0;
}