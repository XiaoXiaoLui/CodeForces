#include <cstdio>
#include <cmath>


const int N = 105;

int a[N];

int main()
{
	int i, n, minH = 20000, minIndex;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 0; i < n; i++)
	{
		if (std::abs(a[i] - a[(i + 1) % n]) < minH)
		{
			minH = std::abs(a[i] - a[(i + 1) %n]);
			minIndex = i;
		}
	}
	
	printf("%d %d\n", minIndex + 1, (minIndex + 1) % n + 1);
	return 0;
}