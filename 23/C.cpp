#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 200005;


struct Box
{
	int a;
	int o;
	int index;
};


Box b[N];


bool cmpA(const Box &b1, const Box &b2)
{
	return b1.a < b2.a;
}



int main()
{
	int t, n, i, j, k;
	long long sumA, sumO, hA, hO, sumOdd, sumEven;
	
	scanf("%d", &t);
	
	for (i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		
		sumA = 0;
		sumO = 0;
		for (j = 1; j <= 2*n - 1; j++)
		{
			scanf("%d%d", &b[j].a, &b[j].o);
			b[j].index = j;
			sumA += b[j].a;
			sumO += b[j].o;
		}
		
		hA = (sumA + 1) / 2;
		hO = (sumO + 1) / 2;
		sort(b + 1, b + 2*n, cmpA);
		
		sumOdd = 0;
		sumEven = 0;
		for (j = 1; j <= 2*n - 1; j++)
		{
			if (j % 2)
			{
				sumOdd += b[j].o;
			}
			else
			{
				sumEven += b[j].o;
			}
		}
		
		if (sumOdd >= hO)
		{
			printf("YES\n");
			for (j = 1; j <= 2*n - 1; j += 2)
			{
				printf("%d ", b[j].index);
			}
			printf("\n");
		}
		else
		{
			printf("YES\n");
			for (j = 2; j < 2*n - 1; j += 2)
			{
				printf("%d ", b[j].index);
			}
			printf("%d\n", b[2*n - 1].index);
		}
		
	}
	
};