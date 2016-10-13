#include <cstdio>


const int N = 200;

char a[N];
char b[N];

int main()
{
	int n, i, len = 0;
	
	scanf("%d%*c", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%c", &a[i]);
		b[len++] = a[i];
		if ((i & 1) && (n - 1 - i >= 2))
		{
			b[len++] = '-';
		}
	}
	
	for (i = 0; i < len; i++)
	{
		printf("%c", b[i]);
	}
	printf("\n");
	
	return 0;
}