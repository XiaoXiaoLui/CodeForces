#include <cstdio>

using namespace std;

int a[101];

int main()
{
	int count1 = 0;
	int count2 = 0;
	int index1, index2;
	
	int i, n, ans;
	
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		
		if (a[i] & 1)
		{
			count1++;
			index1 = i;
		}
		else
		{
			count2++;
			index2 = i;
		}
	}
	
	if (count1 == 1)
	{
		printf("%d", index1);
	}
	else
	{
		printf("%d", index2);
	}
	
	return 0;
}