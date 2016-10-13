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

inline void nextLine()
{
	while (getchar() != '\n')
	{
	}
}

const int N = 1005;
int a[N][N];
int row[N];
int col[N];

int main()
{
	int n, m, i, j, total;
	total = 0;
	char ch;
	
	scanf("%d%d", &n, &m);
	nextLine();
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &ch);
			if (ch == '*')
			{
				a[i][j] = 1;
				row[i]++;
				col[j]++;
				total++;
			}
		}
		nextLine();
	}
	
	int delCount;
	bool ok = false;
	pii ans;
	for (i = 1; i <= n && !ok; i++)
	{
		for (j = 1; j <= m; j++)
		{
			delCount = row[i] + col[j];
			if (a[i][j])
			{
				delCount--;
			}
			if (delCount == total)
			{
				ok = true;
				ans = mp(i, j);
				break;
			}
		}
	}
	
	if (ok)
	{
		printf("YES\n");
		printf("%d %d\n", ans.first, ans.second);
	}
	else
	{
		printf("NO\n");
	}
	
	printf("\n");
	return 0;
}