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

const int N = 600;
int a[N];
int b[N];

vector<pair<int, char> > ans;

bool eat(int start, int end, int offset)
{
	int i, left, right;
	bool ok;
	for (i = start; i <= end; i++)
	{
		left = i - 1;
		right = i + 1;
		int cur = a[i];
		ok = true;
		while (left >= start || right <= end)
		{
			if (left >= start && cur > a[left])
			{
				cur += a[left--];
			}
			else if (right <= end && cur > a[right])
			{
				cur += a[right++];
			}
			else
			{
				ok = false;
				break;
			}
		}
		
		if (ok)
		{
			left = i - 1;
			right = i + 1;
			int curIdx = i - start + 1 + offset;
			cur = a[i];
			while (left >= start || right <= end)
			{
				if (left >= start && cur > a[left])
				{
					ans.push_back(mp(curIdx, 'L'));
					curIdx--;
					cur += a[left--];
				}
				else if (right <= end && cur > a[right])
				{
					ans.push_back(mp(curIdx, 'R'));
			
					cur += a[right++];
				}
			}
			
			return true;
		}
	}
	
	return false;
}

int main()
{
	// USE_IOSTREAM;
	int n, m, i, j;
	
	ll sum1, sum2;
	scanf("%d",  &n);
	sum1 = sum2 = 0LL;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum1 += a[i];
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
		sum2 += b[i];
	}
	
	if (sum1 != sum2)
	{
		printf("NO\n");
		return 0;
	}
	
	int sum = 0, start, end, offset;
	bool ok = true;
	for (i = 1, j = 1; i <= m; i++)
	{
		sum = 0;
		start = j;
		offset = i - 1;
		while (j <= n && sum < b[i])
		{
			sum += a[j];
			j++;
		}
		end = j - 1;
		
		if (sum != b[i])
		{
			ok = false;
			break;
		}
		
		if (!eat(start, end, offset))
		{
			ok = false;
			break;
		}
	}
	
	if (!ok)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for (i = 0; i < ans.size(); i++)
		{
			printf("%d %c\n", ans[i].first, ans[i].second);
		}

	}
	
	return 0;
}