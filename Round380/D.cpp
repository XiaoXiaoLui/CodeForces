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

pii seg[N];
char s[N];
vector<int> ans;

int main()
{
	// USE_IOSTREAM;
	int n, shipNum, shipLen, m, k, i, j, pre, tot, ansNum, curNum;
	scanf("%d%d%d%d", &n, &shipNum, &shipLen, &k);
	scanf("%s", s + 1);
	s[n + 1] = '1';
	pre = 0;
	m = tot = 0;
	for (i = 1; i <= n + 1; i++)
	{
		if (s[i] == '1')
		{
			if (i - pre - 1 >= shipLen)
			{
				seg[m++] = mp(i - pre - 1, pre);
			}
			pre = i;
		}
	}
	
	for (i = 0, tot = 0; i < m; i++)
	{
		tot += seg[i].first / shipLen;
	}
	
	ansNum = tot - shipNum + 1;
	for (i = 0, curNum = 0; i < m && curNum < ansNum; i++)
	{
		pre = seg[i].second;
		for (j = shipLen; j <= seg[i].first && curNum < ansNum; j += shipLen, curNum++)
		{
			ans.push_back(pre + j);
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}