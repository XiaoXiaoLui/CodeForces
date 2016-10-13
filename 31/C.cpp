#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
	int left;
	int right;
	int index;
	bool operator < (const Interval &other) const
	{
		return left < other.left;
	}
};

const int N = 5005;
Interval a[N];
vector<int> ans;

int main()
{
	int n, i, j, index, right;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].left, &a[i].right);
		a[i].index = i + 1;
	}
	sort(a, a + n);
	for (index = 1; index <= n; index++)
	{
		bool ok = true;
		right = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i].index == index)
			{
				continue;
			}
			if (a[i].left < right)
			{
				ok = false;
				break;
			}
			right = a[i].right;
		}
		if (ok)
		{
			ans.push_back(index);
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
	
	return 0;
}