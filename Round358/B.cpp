#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int N = 1e5 + 5;
int a[N];
int main()
{
	int n, ans;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		
	}
	sort(a, a + n);
	
	int i, j;
	for (i = 1, j = 0; i <= n + 1; i++)
	{
		while (j < n && a[j] < i)
		{
			j++;
		}
		if (j >= n)
		{
			ans = i;
			break;
		}
		j++;
	}
	
	printf("%d\n", ans);
	return 0;
}