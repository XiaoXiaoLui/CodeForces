#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Truck
{
	int v;
	int c;
	int l;
	int r;
	int index;
	int getSum() const 
	{
		return c + l + r;
	}
	
	bool operator < (const Truck &other) const
	{
		int sum1 = this->getSum();
		int sum2 = other.getSum();
		return (sum1 < sum2 || sum1 == sum2 && index < other.index);
	}
};

const int N = 1e5 + 5;
Truck t[N];
int f[2 * N];
int g[2 * N];
int pre[N];
vector<int> ans;

void update(int index, int r, int v)
{
	if (v > f[r])
	{
		f[r] = v;
		g[r] = index;
	}
}

int main()
{
	int n, i, j, best, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &t[i].v, &t[i].c, &t[i].l, &t[i].r);
		t[i].index = i + 1;
	}
	
	sort(t, t + n);
	
	i = 0;
	j = 0;
	best = 0;
	fill(pre, pre + n, -1);
	
	while (i < n)
	{
		for (j = i; j < n && (j == i || t[j - 1].getSum() == t[j].getSum()); j++)
		{
			if (t[j].l == 0)
			{
				update(j, t[j].r, t[j].v);
			}
			else if (f[t[j].r + t[j].c] > 0)
			{
				pre[j] = g[t[j].r + t[j].c];
				update(j, t[j].r, t[j].v + f[t[j].r + t[j].c]);
			}
		}
		
		if (f[0] > best)
		{
			best = f[0];
			ans.clear();
			for (k = g[0]; k != -1; k = pre[k])
			{
				ans.push_back(t[k].index);
			}
		}
		for (k = i; k < j; k++)
		{
			f[t[k].r] = 0;
		}
		
		i = j;
	}
	
	printf("%d\n", ans.size());
	for (i = ans.size() - 1; i >= 0; i--)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}