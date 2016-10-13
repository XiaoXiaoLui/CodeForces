#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1005; 

int main()
{
	int n, i, count, a;
	ll x;
	char ch;
	scanf("%d%d", &n, &a);
	x = a;
	count = 0;
	
	for (i = 0; i < n; i++)
	{
		while (getchar() != '\n');
		scanf("%c", &ch);
		scanf("%d", &a);
		if (ch == '+')
		{
			x += a;
		}
		else
		{
			if (x >= a)
			{
				x -= a;
			}
			else
			{
				count++;
			}
		}
	}
	
	printf("%I64d %d\n", x, count);
	return 0;
}