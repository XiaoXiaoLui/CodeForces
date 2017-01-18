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

const int N = 4005;
const int M = 100;
const int UNCAL = 2e9;

int a[N];
int sum[N];
int dp[2300][2*M][M];
int n;

// diff = (n - right) - (left - 1)
void dfs(int left, int diff, int k)
{
	if (dp[left][diff + M][k] != UNCAL)
	{
		return;
	}
	
	int right = n - (diff + (left - 1));
	int ans = -UNCAL;
	int len = right - left + 1;
	if (len < k)
	{
		ans = 0;
	}
	else if (len == k)
	{
		ans = sum[right] - sum[left - 1];
	}
	else
	{
		int l, r, d, tmpAns;
		// try k
		l = left;
		r = right;
		l += k;
		len = r - l + 1;
		tmpAns = sum[l - 1] - sum[left - 1];
		if (len >= k)
		{
			d = (n - r + k) - (l - 1);
			dfs(l, d, k);
			tmpAns = sum[l - 1] - sum[left - 1] + dp[l][d + M][k] - (sum[r] - sum[r - k]);
		}
		if (len >= k + 1)
		{
			d = (n - r + k + 1) - (l - 1);
			dfs(l, d, k + 1);
			tmpAns = min(tmpAns, sum[l - 1] - sum[left - 1] + dp[l][d + M][k + 1] - (sum[r] - sum[r - k - 1]));
		}
		
		ans = tmpAns;
		
		// try k + 1
		l = left;
		r = right;
		l += k + 1;
		len = r - l + 1;
		tmpAns = sum[l - 1] - sum[left - 1];
		if (len >= k + 1)
		{
			d = (n - r + k + 1) - (l - 1);
			dfs(l, d, k + 1);
			tmpAns = sum[l - 1] - sum[left - 1] + dp[l][d + M][k + 1] - (sum[r] - sum[r - k - 1]);
		}
		if (len >= k + 2)
		{
			d = (n - r + k + 2) - (l - 1);
			dfs(l, d, k + 2);
			tmpAns = min(tmpAns, sum[l - 1] - sum[left - 1] + dp[l][d + M][k + 2] - (sum[r] - sum[r - k - 2]));
		}
		
		ans = max(ans, tmpAns);
	}
	
	
	dp[left][diff + M][k] = ans;
}

int main()
{
	// USE_IOSTREAM;
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}

	fill_n((int*)dp, 2*2300*M*M, UNCAL);
	
	
	dfs(1, 0, 1);
	printf("%d\n", dp[1][M][1]);
	
	return 0;
}