#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N =105;
char ans[N];
char name[N];
char posStr[N];
int main()
{
	int n, K, i, j, len;
	scanf("%d%d", &n, &K);
	scanf("%s", name);
	scanf("%s", posStr);
	
	len = strlen(name);
	fill(ans, ans + N, '*');
	bool ok = true;
	for (i = 0; i < n - len + 1 && ok; i++)
	{
		if (posStr[i] == '1')
		{
			for (j = 0; j < len; j++)
			{
				if (ans[i + j] == '*')
				{
					ans[i + j] = name[j];
				}
				else if (ans[i + j] != name[j])
				{
					ok = false;
					break;
				}
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		if (ans[i] == '*')
		{
			ans[i] = 'a';
		}
	}
	ans[n] = '\0';
	
	if (ok)
	{
		printf("%s\n", ans);
	}
	else
	{
		printf("No solution\n");
	}
	return 0;
}