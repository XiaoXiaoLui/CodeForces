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



int main()
{
	int n, k, l, num, v1, v2;
	double t1, t2, ans;
	scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
	
	num = (n + k - 1) / k;
	num--;
	t1 = (double)l / (v2 + 2.0*v1*v2*num / (v1 + v2));
	t2 = 2.0 * v2 * t1 / (v1 + v2);
	ans = t1 + num * t2;
	
	
	printf("%.9lf\n", ans);
	return 0;
}