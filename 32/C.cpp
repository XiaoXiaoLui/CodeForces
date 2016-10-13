#include <cstdio>

#define LLD "%l" "ld"
//#define LLD "%I64d"

int main()
{
	int n, m, s;
	long long a, b;
	scanf("%d%d%d", &n, &m, &s);
	a = (m % s) ? (m % s) * (m / s + 1) : m;
	b = (n % s) ? (n % s) * (n / s + 1) : n;
	
	printf(LLD "\n", a * b);
	return 0;
}