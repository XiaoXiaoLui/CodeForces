#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
	char name[20];
	int a, b, n, i;
	bool ok = false;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s%d%d", name, &a, &b);
		if (a >= 2400 && b > a)
		{
			ok = true;
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