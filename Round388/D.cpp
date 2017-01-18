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

int a[N];
int b[N];
vector<int> vec[N];

pii ans[N];

int main()
{
	// USE_IOSTREAM;
	//freopen("1.txt", "r", stdin);
	int n, i, kNum, j, qNum;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
		vec[a[i]].push_back(i);
	}
	
	set<int, greater<int> > S;
	for (i = 1; i <= n; i++)
	{
		if (!vec[i].empty())
		{
			S.insert(vec[i].back());
		}
	}
	
	scanf("%d", &qNum);
	for (i = 1; i <= qNum; i++)
	{
		scanf("%d", &kNum);
		vector<int> eraseVec;
		while (kNum--)
		{
			scanf("%d", &j);
			if (!vec[j].empty())
			{
				S.erase(vec[j].back());
				eraseVec.push_back(vec[j].back());
			}
		}
		
		if (S.empty())
		{
			ans[i] = {0, 0};
			for (auto tmp : eraseVec)
			{
				S.insert(tmp);
			}
			continue;
		}
		
		auto iter = S.begin();
		j = a[*iter];
		int best;
		best = b[*iter];
		iter++;
		if (iter != S.end())
		{
			int curMax = *iter;
			auto bestIter = upper_bound(vec[j].begin(), vec[j].end(), curMax);
			best = b[*bestIter];
		}
		else
		{
			best = b[vec[j][0]];
		}
		
		
		ans[i] = {j, best};
		
		for (auto tmp : eraseVec)
		{
			S.insert(tmp);
		}
	}
	
	
	for (i = 1; i <= qNum; i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}