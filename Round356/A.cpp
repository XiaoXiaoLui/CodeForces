#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

int num[105];
int a[5];
int main()
{
	int i;
	int sum = 0;
	int ans = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		num[a[i]]++;
	}
	
	ans = sum;
	for (i = 1; i <= 100; i++)
	{
		if (num[i] >= 3)
		{
			ans = min(ans, sum - 3 * i);
		}
		else if (num[i] == 2)
		{
			ans = min(ans, sum - 2 * i);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}