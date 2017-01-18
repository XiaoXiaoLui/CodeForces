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

const int N = 1e5 + 100;

int t[N];
int k[N];
int d[N];

int start[200];
int ans[N];

int main()
{
	USE_IOSTREAM;
	
	int n, qNum, i, j;
	cin >> n >> qNum;
	for (i = 1; i <= qNum; i++)
	{
		cin >> t[i] >> k[i] >> d[i];
	}
	
	for (i = 1; i <= qNum; i++)
	{
		int num = 0;
		int sum = 0;
		for (j = 1; j <= n && num < k[i]; j++)
		{
			if (t[i] >= start[j])
			{
				num++;
				sum += j;
			}
		}
		
		if (num == k[i])
		{
			ans[i] = sum;
			num = 0;
			for (j = 1; j <= n && num < k[i]; j++)
			{
				if (t[i] >= start[j])
				{
					start[j] = t[i] + d[i];
					num++;
				}
			}
		}
		else
		{
			ans[i] = -1;
		}
	}
	
	for (i = 1; i <= qNum; i++)
	{
		cout << ans[i] << endl;
	}
	
	
	return 0;
}