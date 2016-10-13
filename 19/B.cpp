#include <iostream>


using namespace std;

typedef long long ll;

const int N = 2009;
const ll LMAX = ((ll)1) << 60;

int t[N];
int c[N];
ll dp[N][N];
int n;
ll tsum, csum;


ll lmin(ll a, ll b)
{
	return (a <= b) ? a : b;
}

int main()
{
	int i, j;
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> t[i] >> c[i];
		
		csum += c[i];
		t[i]++;
	}
	
	
	for (j = 1; j <= t[0]; j++)
	{
		dp[0][j] = c[0];
	}
	for (j = t[0] + 1; j <= n; j++)
	{
		dp[0][j] = LMAX;
	}
	
	
	for (i = 1; i < n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (t[i] <= j)
			{
				dp[i][j] = lmin(dp[i - 1][j], dp[i - 1][j - t[i]] + c[i]);
			}
			else
			{
				dp[i][j] = lmin(dp[i - 1][j], c[i]);
			}
		}
	}
	
	cout << dp[n - 1][n] << endl;
	
	return 0;
}