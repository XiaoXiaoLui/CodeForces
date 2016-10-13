#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 250;
int n;
char model[5][5];
char ans[N][N];
int expN[10];


void paint(int row, int col, int k)
{
	if (k == 0)
	{
		return;
	}
	
	int i, j, x, y;
	int m = expN[k - 1];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (model[i][j] == '*')
			{
				for (x = row + i * m; x < row + i * m + m; x++)
				{
					for (y = col + j * m; y < col + j * m + m; y++)
					{
						ans[x][y] = '*';
					}
				}
			}
			else
			{
				x = row + i*m;
				y = col + j*m;
				paint(x, y, k - 1);
			}
		}
	}
}

int main()
{
	int k, i, j;
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	
	fscanf(in, "%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%s", model[i]);
	}
	
	expN[0] = 1;
	for (i = 1; i <= k; i++)
	{
		expN[i] = expN[i - 1] * n;
	}

	fill((char*)ans, (char*)ans + N*N, '.');
	
	paint(0, 0, k);
	
	for (i = 0; i < expN[k]; i++)
	{
		for (j = 0; j < expN[k]; j++)
		{
			fprintf(out, "%c", ans[i][j]);
		}
		fprintf(out, "\n");
	}
	
	
	return 0;
}