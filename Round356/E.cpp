#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

const int N = 505;

int n, k;
int a[N][N];
int com[N][N];
int comSize[N*N];
int mark[N*N];

const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inRange(int row, int col)
{
	return (row >= 0 && row < n && col >= 0 && col < n);
}

void dfs(int row, int col, int comIndex)
{
	int i, j, k;
	com[row][col] = comIndex;
	comSize[comIndex]++;
	
	for (k = 0; k < 4; k++)
	{
		i = row + DIR[k][0];
		j = col + DIR[k][1];
		if (inRange(i, j) && !a[i][j] && !com[i][j])
		{
			dfs(i, j, comIndex);
		}
	}
}

void add(int i, int j, int markNum, int &curSize)
{
	if (inRange(i, j) && !a[i][j] && mark[com[i][j]] != markNum)
	{
		mark[com[i][j]] = markNum;
		curSize += comSize[com[i][j]];
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	int i, j, row, col;
	char ch;
	scanf("%c", &ch);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%c", &ch);
			if (ch == '.')
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = 1;
			}
		}
		scanf("%c", &ch);
	}
	
	int comIndex = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (!a[i][j] && !com[i][j])
			{
				dfs(i, j, comIndex);
				comIndex++;
			}
		}
	}
	
	int markNum = 1;
	int ans = 0;
	int curSize;
	for (row = 0; row + k - 1 < n; row++)
	{
		for (i = row; i < row + k; i++)
		{
			for (j = 0; j < k; j++)
			{
				comSize[com[i][j]]--;
			}
		}
		
		
		for (col = 0; col + k - 1 < n; col++)
		{
			curSize = k * k;
			
			for (j = col; j < col + k; j++)
			{
				add(row - 1, j, markNum, curSize);
				add(row + k, j, markNum, curSize);
			}
			
			for (i = row; i < row + k; i++)
			{
				add(i, col - 1, markNum, curSize);
				add(i, col + k, markNum, curSize);
			}
			
			markNum++;
			ans = max(ans, curSize);
			
			if (col + k != n)
			{
				for (i = row; i < row + k; i++)
				{
					comSize[com[i][col]]++;
					comSize[com[i][col + k]]--;
				}
			}
		}
		
		for (i = row; i < row + k; i++)
		{
			for (j = n - k; j < n; j++)
			{
				comSize[com[i][j]]++;
			}
		}
	}
	
	printf("%d\n", ans);
}