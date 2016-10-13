#include <cstdio>

const int N = 305;
int a[N][N];
int n, m;

const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inRange(int i, int j)
{
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

inline int solve(int i, int j, int r)
{
	int res = a[i][j];
	
	int k, x,y;
	for (k = 0; k < 4; k++)
	{
		x = i + r * DIR[k][0];
		y = j + r * DIR[k][1];
		if (!inRange(x, y))
		{
			res = 0;
			break;
		}
		res *= a[x][y];
	}
	
	
	
	
	return res;
}

int main()
{
	int k, i, j, r, count;
	scanf("%d%d%d", &n, &m, &k);
	char ch;
	do
	{
		scanf("%c", &ch);
	} while (ch != '\n');
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &ch);
			if (ch == '*')
			{
				a[i][j] = 1;
			}
		}
		scanf("%*c");
	}
	
	count = 0;
	for (r = 1; r < 150; r++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				count += solve(i, j, r);
				if (count == k)
				{
					break;
				}
			}
			if (count == k)
			{
				break;
			}
		}
		if (count == k)
		{
			break;
		}
	}
	
	int x, y, l;
	if (count == k)
	{
		printf("%d %d\n", i, j);
		for (l = 0; l < 4; l++)
		{
			x = i + r * DIR[l][0];
			y = j + r * DIR[l][1];
			printf("%d %d\n", x, y);
		}
	}
	else
	{
		printf("-1\n");
	}
	
	return 0;
}