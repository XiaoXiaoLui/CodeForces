#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 105;

const int DIR[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool f[N][N][4];
int mark[N][N];
int area[N];
int w, h, n;

bool inRange(int x, int y)
{
	return (x >= 0 && x < w && y >= 0 && y < h);
}

void dfs(int x, int y, int ma)
{
	mark[x][y] = ma;
	int x1, y1;
	for (int k = 0; k < 4; k++)
	{
		if (f[x][y][k])
		{
			continue;
		}
		
		x1 = x + DIR[k][0];
		y1 = y + DIR[k][1];
		if (inRange(x1, y1) && !mark[x1][y1])
		{
			dfs(x1, y1, ma);
		}
	}
}

void addLine(int x1, int y1, int x2, int y2)
{
	int x, y;
	if (x1 == x2)
	{
		for (y = y1; y < y2; y++)
		{
			f[x1 - 1][y][2] = true;
			f[x1][y][0] = true;
		}
	}
	else
	{
		for (x = x1; x < x2; x++)
		{
			f[x][y1 - 1][1] = 1;
			f[x][y1][3] = 1;
		}
	}
}

int main()
{
	int i, x1, y1, x2, y2, x, y;
	scanf("%d%d%d", &w, &h, &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		addLine(x1, y1, x2, y2);
	}
	
	int ma = 1;
	for (x = 0; x < w; x++)
	{
		for (y = 0; y < h; y++)
		{
			if (!mark[x][y])
			{
				dfs(x, y, ma);
				ma++;
			}
			area[mark[x][y]]++;
		}
	}
	sort(area + 1, area + 1 + n + 1);
	
	for (i = 1; i <= n + 1; i++)
	{
		printf("%d ", area[i]);
	}
	printf("\n");
	return 0;
}