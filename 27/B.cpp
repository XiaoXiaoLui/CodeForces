#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 55;
int before[N];
int after[N];

int main()
{
	int n, i, x, y;
	
	scanf("%d", &n);
	for (i = 0; i < n * (n - 1) / 2 - 1; i++)
	{
		scanf("%d%d", &x, &y);
		before[y]++;
		after[x]++;
	}
	
	x = 0;
	y = 0;
	for (i = 1; i <= n; i++)
	{
		if (before[i] + after[i] != n - 1)
		{
			if (!x)
			{
				x = i;
			}
			else
			{
				y = i;
			}
		}
	}
	
	if (before[x] > before[y])
	{
		swap(x, y);
	}
	
	printf("%d %d\n", x, y);
	
	return 0;
}