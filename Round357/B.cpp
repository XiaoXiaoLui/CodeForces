#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
	int n, a, b, c;
	bool ok = false;
	scanf("%d", &n);
	
	int rest1;
	int rest2;
	for (a = 0; a <= n / 1234567 && !ok; a++)
	{
		rest1 = n - a*1234567;
		for (b = 0; b <= rest1 / 123456 && !ok; b++)
		{
			rest2 = rest1 - b * 123456;
			if ((rest2 % 1234) == 0)
			{
				c = rest2 / 1234;
				ok = true;
				break;
			}
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