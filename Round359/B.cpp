#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define mp make_pair<int, int>

const int N = 105;
int a[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				printf("%d %d\n", j, j + 1);
			}
		}
	}
	
	return 0;
}