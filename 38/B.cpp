#include <cstdio>


bool a[10][10];

void rook(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		a[x][i] = true;
		a[i][y] = true;
	}
}

const int DIR[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

bool inRange(int x, int y)
{
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}
void knight(int x, int y)
{
	int i, j, k;
	for (k = 0; k < 8; k++)
	{
		i = x + DIR[k][0];
		j = y + DIR[k][1];
		if (inRange(i, j))
		{
			a[i][j] = true;
		}
	}
}

int main()
{
	int ans = 0;
	int x1, y1, x2, y2;
	char str[5];
	scanf("%s", str);
	x1 = str[0] - 'a' + 1;
	y1 = str[1] - '0';
	scanf("%s", str);
	x2 = str[0] - 'a' + 1;
	y2 = str[1] - '0';
	
	a[x1][y1] = true;
	a[x2][y2] = true;
	rook(x1, y1);
	knight(x2, y2);
	knight(x1, y1);
	
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (!a[i][j])
			{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}