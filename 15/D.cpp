#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;


#define LLD "%I64d"

typedef long long ll;

struct Cell
{
	int x;
	int y;
	ll m;
	
	bool operator < (const Cell &other) const
	{
		return ((m < other.m) || (m == other.m && (x < other.x || (x == other.x && y < other.y))));
	}
};

const int N = 1024;
const int MAX = 1e9;

class SegTree2D
{
public:
	SegTree2D()
	{
		int i, j;
		for (i = 1; i < 2*N; i++)
		{
			for (j = 1; j < 2*N; j++)
			{
				a[i][j] = MAX;
			}
		}
	}
	
	void init(int array[][N], int n, int m)
	{
		int i, j;
		/*
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				update(i, j, array[i][j]);
			}
		}*/
		for (i = 2*N - 1; i >= 1; i--)
		{
			for (j = 2*N - 1; j >= 1; j--)
			{
				if (i >= N && j >= N)
				{
					if (i - N + 1 <= n && j - N + 1 <= m)
					{
						a[i][j] = array[i - N + 1][j - N + 1];
					}
				}
				else if (j < N)
				{
					a[i][j] = min(a[i][j + j], a[i][j + j + 1]);
				}
				else
				{
					a[i][j] = min(a[i + i][j], a[i + i + 1][j]);
				}
			}
		}
	}
	
	int query(int lx, int ly, int rx, int ry)
	{
		lx--;
		ly--;
		
		const int LY = ly + N, RY = ry + N;
		
		int ret = MAX;
		for (lx += N, rx += N; lx < rx; lx >>= 1, rx >>= 1)
		{
			if (lx & 1)
			{
				for (ly = LY, ry = RY; ly < ry; ly >>= 1, ry >>= 1)
				{
					if (ly & 1)
					{
						ret = min(ret, a[lx][ly]);
						ly++;
					}
					if (ry & 1)
					{
						ry--;
						ret = min(ret, a[lx][ry]);
					}
				}
				lx++;
			}
			
			if (rx & 1)
			{
				rx--;
				for (ly = LY, ry = RY; ly < ry; ly >>= 1, ry >>= 1)
				{
					if (ly & 1)
					{
						ret = min(ret, a[rx][ly]);
						ly++;
					}
					if (ry & 1)
					{
						ry--;
						ret = min(ret, a[rx][ry]);
					}
				}
			}
		}
		
		return ret;
	}
	
	void update(int x, int y, int val)
	{
		x--;
		y--;
		int X = x + N;
		int Y = y + N;
		a[x + N][y + N] = val;
		for (x = X; x > 1; x >>= 1)
		{
			for (y = Y; y > 1; y >>= 1)
			{
				a[x >> 1][y] = min(a[x][y], a[x ^ 1][y]);
				a[x][y >> 1] = min(a[x][y], a[x][y ^1]);
			}
			a[x >> 1][y] = min(a[x][y], a[x ^ 1][y]);
		}
	}

private:
	int a[2*N][2*N];
};


int g[N][N];
ll sum[N][N];
ll row[N][2];
ll col[N][N];

vector<Cell> cellSet;
bool rm[N][N];
vector<Cell> ans;
SegTree2D st;


int main()
{
	int n, m, a, b, i, j;
	Cell cell;
	//cin >> n >> m >> a >> b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	//srand(time(0));
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			//cin >> g[i][j];
			scanf("%d", &g[i][j]);
			//g[i][j] = rand() % MAX;
			//g[i][j] = MAX;
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= b; j++)
		{
			row[i][1] += g[i][j];
		}

	}
	
	for (j = 1; j <= m; j++)
	{
		for (i = 1; i <= a; i++)
		{
			col[1][j] += g[i][j];
		}
		
		for (i = 2; i + a - 1 <= n; i++)
		{
			col[i][j] = col[i - 1][j] + g[i + a - 1][j] - g[i - 1][j];
		}
	}
	
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= b; j++)
		{
			sum[1][1] += g[i][j];
		}
	}
	
	for (i = 1; i + a - 1 <= n; i++)
	{
		if (i != 1)
		{
			sum[i][1] = sum[i - 1][1] + row[i + a - 1][1] - row[i - 1][1];
		}
		for (j = 2; j + b - 1 <= m; j++)
		{
			sum[i][j] = sum[i][j - 1] + col[i][j + b - 1] - col[i][j - 1];
		}
	}
	
	
	// for MLE, use segment tree instead of sparse table
	
	st.init(g, n, m);
	
	ll minH;
	for (i = 1; i + a - 1 <= n; i++)
	{
		for (j = 1; j + b - 1 <= m; j++)
		{
			minH = st.query(i, j, i + a - 1, j + b - 1);
			sum[i][j] = sum[i][j] - (ll)a * b * minH;
			
			cell.x = i;
			cell.y = j;
			cell.m = sum[i][j];
			cellSet.push_back(cell);
		}
	}
	
	sort(cellSet.begin(), cellSet.end());
	
	int left, right, up, down;
	for (int k = 0; k < cellSet.size(); k++)
	{	
		if (rm[cellSet[k].x][cellSet[k].y])
		{
			continue;
		}			
		
		ans.push_back(cellSet[k]);
		up = cellSet[k].x - a + 1;
		down = cellSet[k].x + a - 1;
		left = cellSet[k].y - b + 1;
		right = cellSet[k].y + b - 1;
		
		for (i = up; i <= down; i++)
		{
			for (j = left; j <= right; j++)
			{
				if (i < 1 || j < 1)
				{
					continue;
				}
				rm[i][j] = true;
			}
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d %d " LLD "\n", ans[i].x, ans[i].y, ans[i].m);
	}

	
	return 0;
}

