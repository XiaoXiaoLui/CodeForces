#include <iostream>
#include <climits>
#include <algorithm>


using namespace std;
typedef long long ll;

const ll BIG_NUMBER = 1e18;
const int N = 5002;

ll a[N];
int srt[N];
//int dp[N][N];
//int mn[N][N];
ll mn[N];

bool cmp(const int &idx1, const int &idx2)
{
	return a[idx1] < a[idx2];
}

ll myabs(const ll &a)
{
	if (a < 0)
	{
		return -a;
	}
	else
	{
		return a;
	}
}

int main()
{
	int n, i, j, idx;
	ll minSum;
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		srt[i] = i;
	}
	
	sort(srt, srt + n, cmp);
	
	minSum = BIG_NUMBER;
	for (i = 0; i < n; i++)
	{
		idx = srt[i];
		//dp[0][idx] = abs(a[0] - a[idx]);
		minSum = min(minSum, myabs(a[0] - a[idx]));
		mn[idx] = minSum;
	}
	
	for (i = 1; i < n; i++)
	{
		minSum = BIG_NUMBER;
		for (j = 0; j < n; j++)
		{
			idx = srt[j];
			//dp[i][idx] = abs(a[i] - a[idx]) + mn[i - 1][idx];
			//minSum = min(minSum, abs(a[i] - a[idx]) + mn[i - 1][idx]);
			minSum = min(minSum, myabs(a[i] - a[idx]) + mn[idx]);
			mn[idx] = minSum;
		}
	}
	
	idx = srt[n - 1];
	cout << mn[idx] << endl;;
	
	return 0;
}