#include <cstdio>
#include <algorithm>

using namespace std;

int a[105];


int main()
{
	int n, m, i, ans;
	scanf("%d%d", &n, &m);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sort(a, a + n);
	for (i = 0, ans = 0; i < min(n, m); i++)
	{
		if (a[i] >= 0)
		{
			break;
		}
		ans += a[i];
	}
	
	printf("%d\n", -ans);
	
	return 0;
}