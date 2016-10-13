#include <cstdio>


using namespace std;

//#define CYGWIN

#ifdef CYGWIN
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef long long ll;
const int N = 100005;

ll Ax[N], Ay[N];
ll Mx, My;
int n;
ll index;
ll ansX, ansY;

int main()
{
	int i;
	scanf("%d" LLD, &n, &index);
	
	scanf(LLD LLD, &Mx, &My);
	for (i = 0; i < n; i++)
	{
		scanf(LLD LLD, &Ax[i], &Ay[i]);
	}
	
	index %= 2*n;
	ansX = Mx;
	ansY = My;
	for (i = 1; i <= index; i++)
	{
		ansX = 2 * Ax[(i - 1) % n] - ansX;
		ansY = 2 * Ay[(i - 1) % n] - ansY;
	}
	
	printf(LLD " " LLD "\n", ansX, ansY);
	
	return 0;
}

/*
x  m0
(2x0 - x) m1
2x1 - (2x0 - x) = 2x1 - 2x0 + x m2
2x2 - (2x1 - (2x0 - x)) = 2x2 - 2x1 + 2x0 - x m3
2x0 - (2x2 - (2x1 - (2x0 - x))) = 2x0 - 2x2 + 2x1 - 2x0 + x = -2x2 + 2x1 + x m4
2x2 - x m5
x*/
