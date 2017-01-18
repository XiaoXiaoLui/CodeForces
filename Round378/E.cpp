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

const int N = 1e6 + 100;

char s[N];
ll lsumU[N];
ll rsumU[N];
ll lsumD[N];
ll rsumD[N];
int lcntU[N];
int rcntU[N];
int lcntD[N];
int rcntD[N];
ll ans[N];

int main()
{
	// USE_IOSTREAM;
	int n, i;
	scanf("%d", &n);
	scanf("%s", s + 1);
	
	for (i = 1; i <= n; i++)
	{
		lsumU[i] = lsumU[i - 1];
		lsumD[i] = lsumD[i - 1];
		lcntU[i] = lcntU[i - 1];
		lcntD[i] = lcntD[i - 1];
		
		if (s[i] == 'U')
		{
			lsumU[i] += i;
			lcntU[i]++;
		}
		else
		{
			lsumD[i] += i;
			lcntD[i]++;
		}
	}
	
	for (i = n; i >= 1; i--)
	{
		rsumU[i] = rsumU[i + 1];
		rsumD[i] = rsumD[i + 1];
		rcntU[i] = rcntU[i + 1];
		rcntD[i] = rcntD[i + 1];
		if (s[i] == 'U')
		{
			rsumU[i] += n + 1 - i;
			rcntU[i]++;
		}
		else
		{
			rsumD[i] += n + 1 - i;
			rcntD[i]++;
		}
	}
	
	ll tmp;
	for (i = 1; i <= n; i++)
	{
		if (s[i] == 'U')
		{
			if (rcntD[i + 1] <= lcntU[i - 1])
			{
				int pos = lower_bound(lcntU, lcntU + i, lcntU[i - 1] - rcntD[i + 1]) - lcntU;
				tmp = 2 * ((ll)rcntD[i + 1] * i - (lsumU[i - 1] - lsumU[pos]));
				tmp += 2 * ((ll)rcntD[i + 1] * (n + 1 - i) - rsumD[i + 1]) + n + 1 - i;
			}
			else
			{
				int pos = upper_bound(rcntD + i + 1, rcntD + n + 1, rcntD[i + 1] - lcntU[i - 1], greater<int>()) - rcntD;
				tmp = 2 * ((ll)lcntU[i - 1] * i - lsumU[i - 1]);
				tmp += 2 * ((ll)(n + 1 - i) * (lcntU[i - 1] + 1) - (rsumD[i + 1] - rsumD[pos])) + i;
			}
		}
		else
		{
			if (lcntU[i - 1] <= rcntD[i + 1])
			{
				int pos = upper_bound(rcntD + i + 1, rcntD + n + 1, rcntD[i + 1] - lcntU[i - 1] + 1, greater<int>()) - rcntD;
				tmp = 2 * ((ll)lcntU[i - 1] * i - lsumU[i - 1]);
				tmp += 2 * ((ll)(n + 1 - i) * lcntU[i - 1] - (rsumD[i + 1] - rsumD[pos])) + i;
			}
			else
			{
				int pos = lower_bound(lcntU, lcntU + i, lcntU[i - 1] - rcntD[i + 1] - 1) - lcntU;
				tmp = 2 * ((ll)(rcntD[i + 1] + 1) * i - (lsumU[i - 1] - lsumU[pos]));
				tmp += 2 * ((ll)rcntD[i + 1] * (n + 1 - i) - rsumD[i + 1]) + n + 1 - i;
			}
		}
		ans[i] = tmp;
	}
	
	for (i = 1; i <= n; i++)
	{
		printf("%lld ", ans[i]);
	}
	printf("\n");
	
	return 0;
}