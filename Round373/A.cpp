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


const int N = 100;
int a[N];

int main()
{

	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	if (n == 1)
	{
		if (a[1] == 15)
		{
			printf("DOWN\n");
		}
		else if (a[1] == 0)
		{
			printf("UP\n");
		}
		else
		{
			printf("-1\n");
		}
		
		return 0;
	}
	
	int ans = 0;
	
	if (a[n] == 15)
	{
		ans = -1;
	}
	else if (a[n] == 0)
	{
		ans = 1;
	}
	else if (a[n] > a[n - 1])
	{
		ans = 1;
	}
	else
	{
		ans = -1;
	}
	
	if (ans == -1)
	{
		printf("DOWN\n");
	}
	else if (ans == 1)
	{
		printf("UP\n");
	}
	else
	{
		printf("-1\n");
	}
	
	return 0;
}