#include <cstdio>


const int N = 105;
struct Dsu
{
public:
	Dsu(){}
	Dsu(int num)
	{
		n = num;
		for (int i = 1; i <= n; i++)
		{
			root[i] = -1;
		}
	}
	
	void combine(int i, int j)
	{
		int ri = find(i);
		int rj = find(j);
		if (ri == rj)
		{
			return;
		}
		if (root[ri] <= root[rj])
		{
			root[ri] += root[rj];
			root[rj] = ri;
		}
		else
		{
			root[rj] += root[ri];
			root[ri] = rj;
		}
	}
	
	int find(int i)
	{
		int r = i;
		while (root[r] > 0)
		{
			r = root[r];
		}
		
		int j = i;
		int tmp;
		while (j != r)
		{
			tmp = root[j];
			root[j] = r;
			j = tmp;
		}
		return r;
	}
	
private:
	int n;
	int root[N];
};

int d[N];
int pm[N];


int main()
{
	int n, i, j;
	scanf("%d", &n);
	Dsu dsu(n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &pm[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= d[i]; j++)
		{
			if (i - d[i] >= 1)
			{
				dsu.combine(i, i - d[i]);
			}
			if (i + d[i] <= n)
			{
				dsu.combine(i, i + d[i]);
			}
		}
	}
	
	bool ok = true;
	for (i = 1; i <= n; i++)
	{
		if (dsu.find(i) != dsu.find(pm[i]))
		{
			ok = false;
		}
	}
	
	if (ok)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}