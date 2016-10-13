#include <vector>
#include <cstdio>

using namespace std;

#define pii pair<int, int>
#define mp make_pair<int, int>

int a[105];
int main()
{
	int n, i, j, c0, c1;
	vector<pii> ans;
	
	scanf("%d", &n);
	
	a[1] = 0;
	c0 = 1;
	c1 = 0;
	for (i = 2; i <= n; i++)
	{
		if (c0 >= c1)
		{
			a[i] = 1;
			c1++;
		}
		else
		{
			a[i] = 0;
			c0++;
		}
		
		for (j = 1; j < i; j++)
		{
			if (a[j] != a[i])
			{
				ans.push_back(mp(j, i));
			}
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	
	return 0;
}