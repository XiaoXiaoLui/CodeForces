#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 2005;
const int MAX_QNUM = 1e6 + 5;


struct FenwickTree2D
{
	FenwickTree2D()
	{
		fill((ll*)a, (ll*)a + N*N, 0);
	}
	
	void init(int n, int m)
	{
		this->n = n;
		this->m = m;
	}
	
	void update(int x, int y, ll w)
	{
		int i, j;
		for (i = x; i <= n; i += lowbit(i))
		{
			for (j = y; j <= m; j += lowbit(j))
			{
				a[i][j] += w;
			}
		}
	}
	
	ll query(int x, int y)
	{
		ll res = 0;
		int i, j;
		for (i = x; i; i -= lowbit(i))
		{
			for (j = y; j; j -= lowbit(j))
			{
				res += a[i][j];
			}
		}
		
		return res;
	}
	
	int lowbit(int i)
	{
		return i & (-i);
	}
	
	int m, n;
	ll a[N][N];
} tr;

struct Lamp
{
	Lamp() : row(0), col(0), w(0)
	{
	}
	Lamp(int ii, int jj, int ww) : row(ii), col(jj), w(ww)
	{
		
	}
	
	int row;
	int col;
	int w;
};


Lamp lamp[N][N];
int garLen[N];
bool on[N];


vector<ll> ans;

int op[MAX_QNUM];
int idx[MAX_QNUM];
int X1[N], X2[N], Y1[N], Y2[N];

ll cont[N][N];

int main()
{
	int n, m, k, i, j, row, col, w, qNum, askNum;
	ll sum;
	char type[20];
	scanf("%d%d%d", &n, &m, &k);
	
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &garLen[i]);
		
		for (j = 1; j <= garLen[i]; j++)
		{
			scanf("%d%d%d", &row, &col, &w);
			lamp[i][j] = Lamp(row, col, w);
		}
	}
	
	scanf("%d", &qNum);
	askNum = 0;
	for (i = 1; i <= qNum; i++)
	{
		scanf("%s", type);
		if (type[0] == 'S')
		{
			op[i] = 0;
			scanf("%d", &idx[i]);
		}
		else
		{
			op[i] = 1;
			askNum++;
			scanf("%d%d%d%d", &X1[askNum], &Y1[askNum], &X2[askNum], &Y2[askNum]);
		}
	}
	
	tr.init(n, m);
	
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= garLen[i]; j++)
		{
			tr.update(lamp[i][j].row, lamp[i][j].col, lamp[i][j].w);
		}
		
		for (j = 1; j <= askNum; j++)
		{
			cont[j][i] = tr.query(X2[j], Y2[j]) - tr.query(X2[j], Y1[j] - 1) - tr.query(X1[j] - 1, Y2[j]) + tr.query(X1[j] - 1, Y1[j] - 1);
		}
		
		// back
		for (j = 1; j <= garLen[i]; j++)
		{
			tr.update(lamp[i][j].row, lamp[i][j].col, -lamp[i][j].w);
		}
	}
	
	fill(on, on + N, true);
	for (askNum = 0, i = 1; i <= qNum; i++)
	{
		if (op[i] == 0)
		{
			on[idx[i]] = !on[idx[i]];
		}
		else
		{
			++askNum;
			sum = 0;
			for (j = 1; j <= k; j++)
			{
				if (on[j])
				{
					sum += cont[askNum][j];
				}
			}
			ans.push_back(sum);
		}
	}
	
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%lld\n", ans[i]);
	}
	return 0;
}