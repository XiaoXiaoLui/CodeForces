#include <vector>
#include <cstdio>

using namespace std;

#define pii pair<int, int>
#define mp make_pair<int, int>

int a[105];
int main()
{
	int n, i, j, k;
	vector<pii> ans;
	
	scanf("%d", &n);
	k = n / 2;
	
	for (i = 1; i <= k; i++)
	{
		for (j = k + 1; j <= n; j++)
		{
			ans.push_back(mp(i, j));
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	
	return 0;
}