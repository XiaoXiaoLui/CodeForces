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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;



int main()
{
	// USE_IOSTREAM;
	int r, k, i, ans;
	scanf("%d%d", &k, &r);
	
	for (i = 1; k*i % 10 != r && k*i % 10 != 0; i++);
	
	printf("%d\n", i);
	
	return 0;
}