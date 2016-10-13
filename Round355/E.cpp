#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;


struct Cross
{
	int d;
	int count[4];
};

const int N = 1010;
const int M = 1e9 + 7;
const double LG3 = 1.584962500721156181453;

int n;
int a[N][N];
Cross f[N][N];
Cross g[N][N];
vector<int> row[N];
vector<int> col[N];
vector<int> dn1[2*N];
vector<int> dn2[2*N];
int rowCount[N][N][4];
int colCount[N][N][4];
int dn1Count[2*N][N][4];
int dn2Count[2*N][N][4];

bool greater(const Cross &c1, const Cross &c2)
{
	if (c1.count[0])
	{
		return false;
	}
	else if (c2.count[0])
	{
		return true;
	}
	else if (c1.count[2] > c2.count[2] && c1.count[3] > c2.count[3])
	{
		return true;
	}
	else if (c1.count[2] <= c2.count[2] && c1.count[3] <= c2.count[3])
	{
		return false;
	}
	else if (c1.count[2] > c2.count[2] && c1.count[3] <= c2.count[3])
	{
		double a, b;
		a = c1.count[2] - c2.count[2];
		b = c2.count[3] - c1.count[3];
		
		return a > LG3 * b;
	}
	else
	{
		double a, b;
		a = c2.count[2] - c1.count[2];
		b = c1.count[3] - c2.count[3];
		
		return LG3 * b > a;
	}
}

void calF(int i, int j)
{
	vector<int>::iterator iter;
	int index1, index2, d;
	if (!a[i][j])
	{
		f[i][j].d =  1;
		f[i][j].count[a[i][j]] = 1;
	}
	else
	{
		iter = upper_bound(row[i].begin(), row[i].end(), j);
		index2 = *iter;
		iter--;
		index1 = *iter;
		
		d = min(index2 - j, j - index1);
		
		iter = upper_bound(col[j].begin(), col[j].end(), i);
		index2 = *iter;
		iter--;
		index1 = *iter;
		d = min(d, min(index2 - i, i - index1));
		
		f[i][j].d = d;
		
		for (int k = 1; k < 4; k++)
		{
			f[i][j].count[k] = rowCount[i][j + d - 1][k] - rowCount[i][j - d][k] + colCount[i + d - 1][j][k] - colCount[i - d][j][k];
		}
		f[i][j].count[a[i][j]]--;
	}
}

void calG(int i, int j)
{
	vector<int>::iterator iter;
	int index1, index2, d;
	if (!a[i][j])
	{
		g[i][j].d = 1;
		g[i][j].count[a[i][j]] = 1;
	}
	else
	{
		iter = upper_bound(dn1[i - j + n].begin(), dn1[i - j + n].end(), i);
		index2 = *iter;
		iter--;
		index1 = *iter;
		
		d = min(index2 - i, i - index1);
		
		iter = upper_bound(dn2[i + j].begin(), dn2[i + j].end(), i);
		index2 = *iter;
		iter--;
		index1 = *iter;
		d = min(d, min(index2 - i, i - index1));
		
		g[i][j].d = d;
		
		for (int k = 1; k < 4; k++)
		{
			g[i][j].count[k] = dn1Count[i - j + n][i + d - 1][k] - dn1Count[i - j + n][i - d][k] + dn2Count[i + j][i + d - 1][k] - dn2Count[i + j][i - d][k];
		}
		g[i][j].count[a[i][j]]--;
	}
}

int main()
{
	int i, j, k, d;
	char ch;
	scanf("%d%*c", &n);
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%c", &ch);
			a[i][j] = ch - '0';
			for (k = 0; k < 4; k++)
			{
				rowCount[i][j][k] = rowCount[i][j - 1][k];
				colCount[i][j][k] = colCount[i - 1][j][k];
				dn1Count[i - j + n][i][k] = dn1Count[i - j + n][i - 1][k];
				dn2Count[i + j][i][k] = dn2Count[i + j][i - 1][k];
			}
			rowCount[i][j][a[i][j]]++;
			colCount[i][j][a[i][j]]++;
			dn1Count[i - j + n][i][a[i][j]]++;
			dn2Count[i + j][i][a[i][j]]++;
		}
		scanf("%*c");
	}
	
	for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= n + 1; j++)
		{
			if (a[i][j] == 0)
			{
				row[i].push_back(j);
				col[j].push_back(i);
				dn1[i - j + n].push_back(i);
				dn2[i + j].push_back(i);
			}
		}
	}
	
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			calF(i, j);
			calG(i, j);
		}
	}
	
	Cross best = f[1][1];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (greater(f[i][j], best))
			{
				best = f[i][j];
			}
			if (greater(g[i][j], best))
			{
				best = g[i][j];
			}
		}
	}
	
	int ans;
	if (best.count[0])
	{
		ans = 0;
	}
	else
	{
		ans = 1;
		while (best.count[2])
		{
			ans = ((long long)ans * 2) % M;
			best.count[2]--;
		}
		while (best.count[3])
		{
			ans = ((long long)ans * 3) % M;
			best.count[3]--;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}