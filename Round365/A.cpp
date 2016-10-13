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
	int n, i, a, b, ca, cb;
	ca = cb = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		if (a > b)
		{
			ca++;
		}
		else if (a < b)
		{
			cb++;
		}
		else
		{
		}
	}
	
	if (ca > cb)
	{
		printf("Mishka\n");
	}
	else if (ca < cb)
	{
		printf("Chris\n");
	}
	else
	{
		printf("Friendship is magic!^^\n");
	}
	
	return 0;
}