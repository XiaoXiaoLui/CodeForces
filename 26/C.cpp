#include <cstdio>


const int N = 105;
char matrix[N][N];

void solve(int i, int j, int type)
{
	char c = 'a';
	switch (type)
	{
	case 0:
		while (1)
		{
			if (matrix[i - 1][j] == c || matrix[i - 1][j + 1] == c || matrix[i + 1][j] == c || matrix[i + 1][j + 1] == c 
				|| matrix[i][j - 1] == c || matrix[i][j + 2] == c)
			{
				c = (char)(c + 1);
			}
			else
			{
				break;
			}
		}
		matrix[i][j] = matrix[i][j + 1] = c;
		break;
	case 1:
		while (1)
		{
			if (matrix[i - 1][j] == c  || matrix[i + 2][j] == c 
				|| matrix[i][j - 1] == c || matrix[i + 1][j - 1] == c || matrix[i][j + 1] == c || matrix[i + 1][j + 1] == c)
			{
				c = (char)(c + 1);
			}
			else
			{
				break;
			}
		}
		matrix[i][j] = matrix[i + 1][j] = c;
		break;
	case 2:
		while (1)
		{
			if (matrix[i - 1][j] == c || matrix[i - 1][j + 1] == c || matrix[i + 1][j] == c || matrix[i + 1][j + 1] == c 
				|| matrix[i][j - 1] == c || matrix[i + 1][j - 1] == c || matrix[i][j + 2] == c || matrix[i + 1][j + 2] == c)
			{
				c = (char)(c + 1);
			}
			else
			{
				break;
			}
		}
		matrix[i][j] = matrix[i + 1][j] = matrix[i][j + 1] = matrix[i + 1][j + 1] = c;
		break;
	}
}

int main()
{
	int n, m, a, b, c, i, j;
	bool ok = true;

	scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	
	if (n & 1 && m & 1)
	{
		ok = false;
	}
	else if (n & 1)
	{
		for (i = 1; i <= n - 1 && ok; i += 2)
		{
			for (j = 1; j <= m && ok; j += 2)
			{
				if (c)
				{
					solve(i, j, 2);
					c--;
				}
				else if (b >= 2)
				{
					solve(i, j, 1);
					solve(i, j + 1, 1);
					b -= 2;
				}
				else if (a >= 2)
				{
					solve(i, j, 0);
					solve(i + 1, j, 0);
					a -= 2;
				}
				else
				{
					ok = false;
				}
			}
		}
		
		for (j = 1; j <= m && ok; j += 2)
		{
			if (a)
			{
				solve(i, j, 0);
				a--;
			}
			else
			{
				ok = false;
			}
		}
	}
	else if (m & 1)
	{
		for (i = 1; i <= n && ok; i += 2)
		{
			for (j = 1; j <= m - 1 && ok; j += 2)
			{
				if (c)
				{
					solve(i, j, 2);
					c--;
				}
				else if (a >= 2)
				{
					solve(i, j, 0);
					solve(i + 1, j, 0);
					a -= 2;
				}
				else if (b >= 2)
				{
					solve(i, j, 1);
					solve(i, j + 1, 1);
					b -= 2;
				}
				else
				{
					ok = false;
				}
			}
		}
		
		for (i = 1; i <= n && ok; i += 2)
		{
			if (b)
			{
				solve(i, j, 1);
				b--;
			}
			else
			{
				ok = false;
			}
		}
	}
	else
	{
		for (i = 1; i <= n && ok; i += 2)
		{
			for (j = 1; j <= m && ok; j += 2)
			{
				if (c)
				{
					solve(i, j, 2);
					c--;
				}
				else if (a >= 2)
				{
					solve(i, j, 0);
					solve(i + 1, j, 0);
					a -= 2;
				}
				else if (b >= 2)
				{
					solve(i, j, 1);
					solve(i, j + 1, 1);
					b -= 2;
				}
				else
				{
					ok = false;
				}
			}
		}
	}
	
	
	if (ok)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				printf("%c", matrix[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("IMPOSSIBLE\n");
	}
	
	return 0;
}