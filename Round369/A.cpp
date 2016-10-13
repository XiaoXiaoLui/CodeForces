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

const int N = 1005;

char s[N][8];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	
	bool ok = false;
	for (i = 0; i < n && !ok; i++)
	{
		if (s[i][0] == 'O' && s[i][1] == 'O')
		{
			ok = true;
			s[i][0] = '+';
			s[i][1] = '+';
		}
		else if (s[i][3] == 'O' && s[i][4] == 'O')
		{
			ok = true;
			s[i][3] = s[i][4] = '+';
		}
	}
	
	if (ok)
	{
		printf("YES\n");
		for (i = 0; i < n; i++)
		{
			printf("%s\n", s[i]);
		}
	}
	else
	{
		printf("NO\n");
	}
	
	printf("\n");
	return 0;
}