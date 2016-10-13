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

char day[7][20] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

int main()
{
	int d1, d2, i;
	char str1[20], str2[20];
	scanf("%s%s", str1, str2);
	for (i = 0; i < 7; i++)
	{
		if (!strcmp(str1, day[i]))
		{
			d1 = i;
		}
		
		if (!strcmp(str2, day[i]))
		{
			d2 = i;
		}
	}
	
	int offset = (d2 - d1 + 7) % 7;
	if (offset == 0 || offset == 2 || offset == 3)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	
	return 0;
}