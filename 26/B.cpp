#include <cstdio>

const int N = 1000005;

char seq[N];

int main()
{
	int i, c1 = 0, c2 = 0;
	
	scanf("%s", seq);
	
	for (i = 0; seq[i]; i++)
	{
		if (seq[i] == '(')
		{
			c1++;
		}
		else
		{
			if (c1 > c2)
			{
				c2++;
			}
		}
	}
	
	printf("%d\n", 2 * c2);
	
	return 0;
}