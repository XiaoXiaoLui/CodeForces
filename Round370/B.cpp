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
char s[N];


int main()
{
	int n, i, dh, dv;
	scanf("%s", s);
	n = strlen(s);
	
	if (n % 2)
	{
		printf("-1\n");
		return 0;
	}
	
	for (i = 0, dh = 0, dv = 0; i < n; i++)
	{
		switch (s[i])
		{
		case 'L':
			dh++;
			break;
		case 'R':
			dh--;
			break;
		case 'U':
			dv++;
			break;
		case 'D':
			dv--;
			break;
		default:
			break;
		}
	}
	dh = abs(dh);
	dv = abs(dv);
	if (dh < dv)
	{
		swap(dh, dv);
	}
	int ans = dv + (dh - dv) / 2;
	printf("%d\n", ans);

	return 0;
}