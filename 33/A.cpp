#include <cstdio>
#include <algorithm>

const int MAX = 1e9;
const int N = 1005;

int a[N];
int main()
{
	int n, m, k, i, row, value, sum;
	scanf("%d%d%d", &n, &m, &k);
	std::fill(a, a + m + 1, MAX);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &row, &value);
		a[row] = std::min(a[row], value);
	}
	for (sum = 0, i = 1; i <= m; i++)
	{
		sum += a[i];
	}
	
	int ans = std::min(sum, k);
	printf("%d\n", ans);
	
	return 0;
}