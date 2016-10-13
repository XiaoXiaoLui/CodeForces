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

void nextLine()
{
	while (getchar() != '\n');
}

int main()
{
	int n, m, i, j;
	bool colored = false;
	char ch;
	scanf("%d%d", &n, &m);
	nextLine();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%c%*c", &ch);
			if (ch != 'B' && ch != 'W' && ch != 'G')
			{
				colored = true;
			}
		}
		
	}
	
	if (colored)
	{
		printf("#Color\n");
	}
	else
	{
		printf("#Black&White\n");
	}
	
	
	return 0;
}