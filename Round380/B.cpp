#include<bits/stdc++.h>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 1005;
int a[N][N];
bool row[N];
bool col[N];

int main()
{
	// USE_IOSTREAM;
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	int ans = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j])
			{
				row[i] = col[j] = true;
				continue;
			}
			
			if (row[i])
			{
				ans++;
			}
			if (col[j])
			{
				ans++;
			}
		}
	}
	
	fill(row, row + N, false);
	fill(col, col + N, false);
	for (i = n; i >= 1; i--)
	{
		for (j = m; j >= 1; j--)
		{
			if (a[i][j])
			{
				row[i] = col[j] = true;
				continue;
			}
			
			if (row[i])
			{
				ans++;
			}
			if (col[j])
			{
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}