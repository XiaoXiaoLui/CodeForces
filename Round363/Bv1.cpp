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

int main()
{
	int n, m, i, j;
	char ch;
	int row[2] = {0, 0};
	int col[2] = {0, 0};
	int index = 0;

	bool ok = true;
	pii ans;
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
				if (index == 0)
				{
					row[index] = i;
					col[index] = j;
					index++;
				}
				else if (index == 1)
				{
					if (i == row[0] || j == col[0])
					{
					
					}
					else
					{
						row[index] = i;
						col[index] = j;
						index++;
					}
				}
			}
		}
		nextLine();
	}
	
	if (index == 0)
	{
		ans = mp(1,1 );
	}
	else if (index == 1)
	{
		ans = mp(row[0], col[0]);
	}
	else if (index == 2)
	{
		bool ok1 = true, ok2 = true;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (a[i][j] && i != row[0] && j != col[1])
				{
					ok1 = false;
				}
				if (a[i][j] && i != row[1] && j != col[0])
				{
					ok2 = false;
				}
			}
		}
		ok = ok1 || ok2;
		if (ok1)
		{
			ans = mp(row[0], col[1]);
		}
		else if (ok2)
		{
			ans = mp(row[1], col[0]);
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