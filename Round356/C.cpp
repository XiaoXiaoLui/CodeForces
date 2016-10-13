#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>


using namespace std;

bool isPrime[105];
int sqrNum[4] = {4, 9, 25, 49};

int main()
{
	int c, i, j, p;
	char str[10];
	
	for (i = 2; i <= 100; i++)
	{
		isPrime[i] = true;
	}
	
	for (i = 2; i <= 100; i++)
	{
		if (!isPrime[i])
		{
			continue;
		}
		for (j = i + i; j <= 100; j += i)
		{
			isPrime[j] = false;
		}
	}
	
	c = 0;
	p = 2;
	i = 1;
	bool ok = true;
	while(i <= 15 && c < 2 && p <= 100)
	{
		if (!isPrime[p])
		{
			p++;
			continue;
		}
		printf("%d\n", p);
		fflush(stdout);
		scanf("%s", str);
		
		if (!strcmp(str, "yes"))
		{
			c++;
		}
		i++;
		p++;
	}
	
	if (c == 2)
	{
		ok = false;
	}
	else if (c == 1)
	{
		for (i = 0; i < 4; i++)
		{
			printf("%d\n", sqrNum[i]);
			fflush(stdout);
			scanf("%s", str);
			
			if (!strcmp(str, "yes"))
			{
				ok = false;
				break;
			}
		}
	}
	
	if (ok)
	{
		printf("prime\n");
		fflush(stdout);
	}
	else
	{
		printf("composite\n");
		fflush(stdout);
	}
	
	return 0;
}