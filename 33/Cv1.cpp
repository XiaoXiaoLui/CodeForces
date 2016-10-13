#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
struct FenwickTree
{
	FenwickTree(int n)
	{
		this->n = n;
		for (int i = 1; i <= n; i++)
		{
			a[i] = MIN;
		}
	}
	
	int query(int i)
	{
		if (i == 0)
		{
			return 0;
		}
		int res = MIN;
		while (i > 0)
		{
			res = max(res, a[i]);
			i -= lowbit(i);
		}
		return res;
	}
	
	void update(int i, int value)
	{
		while (i <= n)
		{
			a[i] = max(a[i], value);
			i += lowbit(i);
		}
	}
	
	int lowbit(int k)
	{
		return k & (-k);
	}
	
	const static int MIN = -1e9;
	int a[N];
	int n;
};

int a[N];

int main()
{
	int n, i, j, sum, ans;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	// for prefix
	FenwickTree preTree(n);
	for (sum = 0, i = 1; i <= n; i++)
	{
		sum -= 2 * a[i];
		preTree.update(i, sum);
	}
	
	
	// for suffix
	FenwickTree sufTree(n);
	for (sum = 0, i = n; i >= 1; i--)
	{
		sum -= 2 * a[i];
		sufTree.update(n - i + 1, sum);
	}
	
	for (sum = 0, i = 1; i <= n; i++)
	{
		sum += a[i];
	}
	
	ans = sum;
	for (i = 0; i <= n; i++)
	{
		ans = max(ans, sum + preTree.query(i) + sufTree.query(n - i));
	}
	
	printf("%d\n", ans);
	
	return 0;
}