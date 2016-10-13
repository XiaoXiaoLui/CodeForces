#include <cstdio>
#include <algorithm>

using namespace std;

/*
0 2k 	-
0 2k+1 	+
1 k		+
2 2k+1	+
2 2k	-
3 k 	+
4 2k+1  +
4 2k    -

- if and only if a and b are even

nk + a  mk + b 

a  b  (a+b)%2
k+a k+b min(a,b) >= 1  (a+b)%2 + 1
k+a k+b min(a,b) == 0 1
2k+a 2k+b min(a,b) >= 2 (a+b)%2
		  min(a,b) == 1 1 
		  min(a,b) == 0 (a+b)%2 + 1
3k+a 3k+b min(a,b) >= 3 (a+b)%2 + 1
		  min(a,b) == 2 (a+b)%2 + 1
		  min(a,b) == 1
		  min(a,b) == 0 (a+b)%2

*/

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n, m, t, k;
	
	scanf("%d%d", &t, &k);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &n, &m);
		
		if (k == 1)
		{
			if (n % 2 && m % 2)
			{
				printf("-\n");
			}
			else
			{
				printf("+\n");
			}
		}
		else
		{
			if (n > m)
			{
				swap(n, m);
			}
			if (n % (k + 1) == 0)
			{
				printf("+\n");
			}
			else if ((n / (k + 1)) % 2 == 0)
			{
				printf("%c\n", (m - n) % 2 ? '+' : '-');
			}
			else
			{
				printf("%c\n", (m - n) % 2 ? '-' : '+');
			}
		}
	}
	
	return 0;
}