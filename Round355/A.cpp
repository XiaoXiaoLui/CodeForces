#include <cstdio>


using namespace std;


int main()
{
	int n, h;
	
	scanf("%d%d", &n, &h);
	
	int a;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a > h)
		{
			ans += 2;
		}
		else
		{
			ans += 1;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}