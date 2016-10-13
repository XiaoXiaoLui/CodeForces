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

const int N = 110;

char s[N][N];
int c[N];

int main()
{
	int n, k, i, len, minAns, maxAns, r, sum;
	
	
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%s", s[i]);
		len = strlen(s[i]);
		c[len]++;
	}
	scanf("%s", s[n + 1]);
	len = strlen(s[n + 1]);
	
	minAns = maxAns = 0;
	sum = 0;
	
	for (i = 1; i < len; i++)
	{
		sum += c[i];
	}
	
	
	minAns = sum + (sum / k) * 5 + 1;
	sum += c[len] - 1;
	maxAns = sum + (sum / k) * 5 + 1;
	
	printf("%d %d\n", minAns, maxAns);
	return 0;
}