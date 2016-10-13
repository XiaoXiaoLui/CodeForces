#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1005;
int a[N];

int main()
{
	int i, number, maxNum = 0;
	char ch;
	do
	{
		scanf("%d", &number);
		maxNum = max(maxNum, number);
		a[number] = 1;
		ch = getchar();
	} while (ch != '\n');
	
	int left = 0;
	for (i = 1; i <= 1001; i++)
	{
		if (a[i])
		{
			if (!left)
			{
				left = i;
			}
		}
		else
		{
			if (left)
			{
				if (i - left > 1)
				{
					printf("%d-%d%c", left, i - 1, (i < maxNum) ? ',' : '\n');
				}
				else
				{
					printf("%d%c", left, (i < maxNum) ? ',' : '\n');
				}
				
				left = 0;
			}
		}
	}
	
	return 0;
}