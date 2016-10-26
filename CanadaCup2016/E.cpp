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

const int N = 2e5 + 100;
pii a[N];

int main()
{
	// USE_IOSTREAM;
	int n, wantSum, i, j, ans, cur, maxNum;
	scanf("%d%d", &wantSum, &n);
	for (i = 1, maxNum = 0; i <= n; i++)
	{
		scanf("%d", &cur);
		a[cur].first++;
		maxNum = max(maxNum, cur);
	}
	
	cur = 0;
	for (i = 1; i <= wantSum; i++)
	{
		a[i].second = cur;
		if (a[i].first)
		{
			cur = i;
		}
	}
	
	bool ok = false;
	for (ans = 1; ans < wantSum; ans++)
	{
		cur = wantSum;
		i = a[cur].first ? cur : a[cur].second;
		bool used = false;
		while (cur > 0)
		{
			if (!used && ans <= cur && ans >= i)
			{
				used = true;
				cur -= ans;
				if (cur < i)
				{
					i = a[cur].first ? cur : a[cur].second;
				}
			}
			else if (i == 0)
			{
				ok = true;
				break;
			}
			else 
			{
				cur -= min(a[i].first, cur / i) * i;
				if (cur >= i)
				{
					i = a[i].second;
				}
				else
				{
					i = a[cur].first ? cur : a[cur].second;
				}	
			}	
		}
		
		if (ok)
		{
			break;
		}
	}
	
	if (ok)
	{
		printf("%d\n", ans);
	}
	else
	{
		printf("Greed is good\n");
	}
	
	return 0;
}