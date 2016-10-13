#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

struct Position
{
	Position(){}
	Position(int row, int col) : x(row), y(col)
	{
	}
	int x;
	int y;
};

vector<Position> ans;

int main()
{
	int n, m, i, j;
	
	scanf("%d%d", &n, &m);
	
	
	if (n * m == 2)
	{
		ans.push_back(Position(1, 1));
		if (n == 1)
		{
			ans.push_back(Position(1, 2));
		}
		else
		{
			ans.push_back(Position(2, 1));
		}
		ans.push_back(Position(1, 1));
		printf("0\n");
	}
	else if (n == 1)
	{
		for (j = 1; j <= m; j++)
		{
			ans.push_back(Position(1, j));
		}
		ans.push_back(Position(1, 1));
		printf("1\n");
		printf("%d %d %d %d\n", 1, m, 1, 1);
	}
	else if (m == 1)
	{
		for (i = 1; i <= n; i++)
		{
			ans.push_back(Position(i, 1));
		}
		ans.push_back(Position(1, 1));
		printf("1\n");
		printf("%d %d %d %d\n", n, 1, 1, 1);
	}
	else if ((n & 1) == 0)
	{
		for (i = 1; i <= n; i++)
		{
			ans.push_back(Position(i, 1));
		}
		
		for (i = n; i >= 1; i--)
		{
			if (i & 1)
			{
				for (j = m; j >= 2; j--)
				{
					ans.push_back(Position(i, j));
				}
			}
			else
			{
				for (j = 2; j <= m; j++)
				{
					ans.push_back(Position(i, j));
				}
			}
		}
		ans.push_back(Position(1, 1));
		printf("0\n");
	}
	else if ((m & 1) == 0)
	{
		for (j = 1; j <= m; j++)
		{
			ans.push_back(Position(1, j));
		}
		for (j = m; j >= 1; j--)
		{
			if (j & 1)
			{
				for (i = n; i >= 2; i--)
				{
					ans.push_back(Position(i, j));
				}
			}
			else
			{
				for (i = 2; i <= n; i++)
				{
					ans.push_back(Position(i, j));
				}
			}
		}
		ans.push_back(Position(1, 1));
		printf("0\n");
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			ans.push_back(Position(i, 1));
		}
		
		for (i = n; i >= 1; i--)
		{
			if ((i & 1) == 0)
			{
				for (j = m; j >= 2; j--)
				{
					ans.push_back(Position(i, j));
				}
			}
			else
			{
				for (j = 2; j <= m; j++)
				{
					ans.push_back(Position(i, j));
				}
			}
		}
		ans.push_back(Position(1, 1));
		printf("1\n");
		printf("%d %d %d %d\n", 1, m, 1, 1);
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i].x, ans[i].y);
	}
	
	printf("\n");
	return 0;
}