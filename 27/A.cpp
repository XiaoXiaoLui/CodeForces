#include <cstdio>


int a[3050];

int main()
{
	int n;
	scanf("%d", &n);
	
	int i;
	int index;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &index);
		a[index] = 1;
	}
	
	for (i = 1; a[i] ; i++);
	
	printf("%d\n", i);
	return 0;
}