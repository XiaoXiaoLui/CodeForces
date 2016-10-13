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

int a[10];

int main()
{
	int n = 3, i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + 3);
	
	printf("%d\n", a[2] - a[0]);
	return 0;
}