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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1e6 + 100;

//vector<int> mat[N];
vector<int> a[N];
int ft[N];
int n, c, m;

inline void addSeg(int l, int r)
{
	ft[l]++;
	ft[r + 1]--;
}

int main()
{
	// USE_IOSTREAM;
	int len, i, j, w;
	scanf("%d%d", &n, &c);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &len);

		for (j = 1; j <= len; j++)
		{
			scanf("%d", &w);
			a[i].push_back(w);
		}
	}

	bool ok = true, bFind;
	
	for (i = 2; i <= n && ok; i++)
	{
		bFind = false;
		for (j = 0; j < a[i].size() && j < a[i - 1].size(); j++)
		{
			if (a[i][j] != a[i - 1][j])
			{
				bFind = true;
				break;
			}
		}
		
		if (!bFind)
		{
			if (a[i].size() < a[i - 1].size())
			{
				ok = false;
			}
		}
		else
		{
			if (a[i - 1][j] < a[i][j])
			{
				addSeg(c + 1 - a[i][j], c - a[i - 1][j]);
			}
			else
			{
				addSeg(0, c - a[i - 1][j]);
				addSeg(c + 1 - a[i][j], c - 1);
			}
		}
	}
	
	int ans;
	if (!ok)
	{
		ans = -1;
	}
	else
	{
		ans = -1;
		ll sum = 0;
		for (i = 0; i < c; i++)
		{
			sum += ft[i];
			if (sum == 0)
			{
				ans = i;
				break;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}