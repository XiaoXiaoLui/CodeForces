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

bool isVowel(char ch)
{
	switch (ch)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
		return true;
		default:
		return false;
	}
	
}

inline void nextLine()
{
	while (getchar() != '\n');
}

const int N = 105;
char s[N][N];
int p[N];

int main()
{
	int n, i, j;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}
	
	nextLine();
	for (i = 1; i <= n; i++)
	{
		gets(s[i]);
		//nextLine();
	}
	
	bool ok = true;
	int c;
	for (i = 1; i <= n; i++)
	{
		for (c = 0, j = 0; s[i][j]; j++)
		{
			if (isVowel(s[i][j]))
			{
				c++;
			}
		}
		if (c != p[i])
		{
			ok = false;
			break;
		}
	}
	
	if (ok)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}