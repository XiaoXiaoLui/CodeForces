#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

const int N = 1005;

char str1[N];
char str2[N];
string s1;
string s2;

int n, m;
int f[N][N][12];
int l[N][N];
pair<int, int> route[N][N][12];

int find(int i, int j, int k)
{
	if (f[i][j][k] != -1)
	{
		return f[i][j][k];
	}
	
	if ((i >= n || j >= m) || k == 0)
	{
		return f[i][j][k] = 0;
	}
	
	if (l[i][j])
	{
		//f[i][j][k] = max(f[i][j][k], l[i][j] + find(i + l[i][j], j + l[i][j], k - 1));
		if (l[i][j] + find(i + l[i][j], j + l[i][j], k - 1) > f[i][j][k])
		{
			f[i][j][k] = l[i][j] + find(i + l[i][j], j + l[i][j], k - 1);
			route[i][j][k] = make_pair<int, int>(i, j);
		}
	}
	
	if (find(i + 1, j, k) > f[i][j][k])
	{
		f[i][j][k] = find(i + 1, j, k);
		route[i][j][k] = make_pair<int, int>(i + 1, j);
	}
	if (find(i, j + 1, k) > f[i][j][k])
	{
		f[i][j][k] = find(i, j + 1, k);
		route[i][j][k] = make_pair<int, int>(i, j + 1);
	}
	
	//f[i][j][k] = max(f[i][j][k], find(i + 1, j, k));
	//f[i][j][k] = max(f[i][j][k], find(i, j + 1, k));
	
	
	
	return f[i][j][k];
}

int main()
{
	int k, i, j, num, len;
	scanf("%d%d%d", &n, &m, &num);
	scanf("%s%s", str1, str2);
	s1 = str1;
	s2 = str2;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			l[i][j] = -1;
			for (k = 0; k <= 10; k++)
			{
				f[i][j][k] = -1;
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (l[i][j] != -1)
			{
				continue;
			}
			for (len = 0; len < min(n - i, m - j) && s1[i + len] == s2[j + len]; len++);
			l[i][j] = len;
			for (k = 1; k < len; k++)
			{
				l[i + k][j + k] = len - k;
			}
		}
	}

	
	find(0, 0, num);
	
	printf("%d\n", f[0][0][num]);
	return 0;
}