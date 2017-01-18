#include<bits/stdc++.h>
#include <assert.h>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair
#define ASSERT assert

typedef long long ll;
const int INF = 1e9;

const char RED = 'R';
const char BLUE = 'B';
const int N = 17;
int dp[(1 << 16)][2][N * N];
pii rbNum[(1 << 16) + 2];

char c[N];
int r[N];
int b[N];

void update(int &cur, int value)
{
	cur = min(cur, value);
}

int main()
{
	USE_IOSTREAM;
	int n, i, j, k, bit;
	int ans;
	cin >> n;
	char ch;
	for (i = 0; i < n; i++)
	{
		cin >> c[i] >> r[i] >> b[i];
	}
	
	for (i = 0; i < 1 << n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				if (c[j] == RED)
				{
					rbNum[i].first++;
				}
				else
				{
					rbNum[i].second++;
				}
			}
		}
	}
	
	
	// count the number of color necessary from tokens
	int restRed, restBlack, needToken, cr, cb;
	cr = cb = 0;
	for (i = 0; i < n; i++)
	{
		cr += max(0, r[i] - n);
		cb += max(0, b[i] - n);
		
		r[i] = min(r[i], n);
		b[i] = min(b[i], n);
	}
	
	// dp[mask][restcolor][restNum]
	fill_n((int*)dp, (1 << 16) * 2 * N * N, INF);
	needToken = max(cr, cb);
	restRed = needToken - cr;
	restBlack = needToken - cb;
	int restColor = restRed >= restBlack ? 0 : 1; // 0: rest is red 1: rest is black
	int restNum = min(n*n, max(restRed, restBlack));
	dp[0][restColor][restNum] = max(cb, cr);
	//ans = max(cb, cr) + n; // base operation
	
	for (i = 0; i < 1 << n; i++)		
	for (j = 0; j < 2; j++)	
	for (k = 0; k <= n * n; k++)
	{
		if (dp[i][j][k] == INF)
		{
			continue;
		}
		for (bit = 0; bit < n; bit++)
		{
			if (i >> bit & 1)
			{
				continue;
			}
			int nextMask = i | (1 << bit);	
			if (j == 0)
			{
				cr = max(0, r[bit] - rbNum[i].first - k);
				cb = max(0, b[bit] - rbNum[i].second);
				needToken = max(cr, cb);
				restRed = needToken + k + min(0, rbNum[i].first - r[bit]);
				restBlack = needToken + min(0, rbNum[i].second - b[bit]);
			}
			else
			{
				cr = max(0, r[bit] - rbNum[i].first);
				cb = max(0, b[bit] - rbNum[i].second - k);
				needToken = max(cr, cb);
				restRed = needToken + min(0, rbNum[i].first - r[bit]);
				restBlack = needToken + k + min(0, rbNum[i].second - b[bit]);
			}
			
			//ASSERT(restRed == 0 || restBlack == 0);
			restColor = restRed >= restBlack ? 0 : 1;
			restNum = min(max(restRed, restBlack), n*n);
			update(dp[nextMask][restColor][restNum], dp[i][j][k] + needToken);
		}
	}
	
	
	
	ans = INF;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j <= n*n; j++)
		{
			update(ans, dp[(1 << n) - 1][i][j]);
		}
	}
	
	ans += n;
	cout << ans << endl;
	
	return 0;
}