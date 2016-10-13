#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int A, B, n, X, p,q;
	scanf("%d%d%d", &A, &B, &n);
	bool ok = true;
	
	if (A == 0 && B != 0)
	{
		printf("No solution\n");
		return 0;
	}
	else if (A == 0 && B == 0)
	{
		printf("1\n");
		return 0;
	}
	else if (B == 0)
	{
		printf("0\n");
		return 0;
	}
	p = B / A;
	q = B % A;
	if (q)
	{
		ok = false;
	}
	
	int i;
	if (ok)
	{
		ok = false;
		for (X = -abs(p); X <= abs(p); X++)
		{
			int tmp = 1;
			for (i = 1; i <= n && abs(tmp) <= abs(p); i++)
			{
				tmp = tmp * X;
			}
			if (i == (n + 1) && tmp == p)
			{
				ok = true;
				break;
			}
		}
	}
	
	if (ok)
	{
		printf("%d\n", X);
	}
	else
	{
		printf("No solution\n");
	}
	
	return 0;
}