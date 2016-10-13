#include <cstdio>
#include <cmath>

using namespace std;

int sqr(int a)
{
	return a*a;
}

bool isSquareNumber(int a)
{
	int s = (int)sqrt(a);
	if (sqr(s - 1) == a || sqr(s) == a || sqr(s + 1) == a)
	{
		return true;
	}
	return false;
}

int main()
{
	int x, y, color;
	scanf("%d%d", &x, &y);
	color = 1;
	if (x*y == 0 || isSquareNumber(sqr(x) + sqr(y)))
	{
		color = 1;
	}
	else
	{
		color = (x*y > 0) ? 1 : 0;
		int distLow = (int)sqrt(sqr(x) + sqr(y));
		color ^= distLow & 1;
	}
	
	printf("%s\n", color ? "black" : "white");
	
	return 0;
}