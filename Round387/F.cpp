#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

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


const int N = 20;

ll comb[N][N];
ll dp[N][N];
int rest[N];
int ans[N];

ll calNum(int len)
{
	int i, j, k;
	for (i = 0; i <= 16; i++)
	{
		for (j = 0; j <= len; j++)
		{
			dp[i][j] = 0;
		}
	}
	
	// dp[i][j], number of valid integer with length j && max digit < i
	
	// null integer, base of dp
	dp[0][0] = 1;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j <= rest[i] && j <= len; j++)
		{
			for (k = 0; k + j <= len; k++)
			{
				dp[i + 1][j + k] += dp[i][k] * comb[j + k][j];
			}
		}
	}
	
	return dp[16][len];
}

int main()
{
	USE_IOSTREAM;
	int n, k, i, j;
	cin >> n >> k;
	
	for (i = 0; i < N; i++)
	{
		comb[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
	
	for (i = 0; i < 16; i++)
	{
		rest[i] = k;
	}
	
	int len;
	ll tot;
	rest[0]--;
	for (len = 1; true; len++)
	{		
		tot = calNum(len - 1) * 15;
		
		if (n <= tot)
		{
			break;
		}
		
		n -= tot;
	}
	rest[0]++;
	
	int startLen = len;
	while (len)
	{
		i = (startLen == len) ? 1 : 0;
		for (; i < 16; i++)
		{
			if (!rest[i])
			{
				continue;
			}
			rest[i]--;
			tot = calNum(len - 1);
			if (n <= tot)
			{
				ans[len] = i;
				break;
			}
			
			n -= tot;
			rest[i]++;
		}
		len--;
	}
	
	for (i = startLen; i >= 1; i--)
	{
		char ch = ans[i] > 9 ? (char)(ans[i] - 10 + 'a') : (char)(ans[i] + '0');
		cout << ch;
	}
	cout << endl;
	
	return 0;
}