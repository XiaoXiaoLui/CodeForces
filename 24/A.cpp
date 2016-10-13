#include <cstdio>

using namespace std;

const int N = 105;

struct Road
{
	bool from;
	int v;
	int c;
};

Road road[N][2];
int count[N];

int main()
{
	int n, i, u, v, pre;
	int sum1 = 0;
	int sum = 0;
	int a, b, c;
	Road r;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		r.from = true;
		r.v = b;
		r.c = c;
		road[a][count[a]++] = r;
		
		r.from = false;
		r.v = a;
		r.c = c;
		road[b][count[b]++] = r;
		
		sum += c;
	}
	
	pre = 0;
	u = 1;
	do
	{
		r = road[u][0];
		if (r.v == pre)
		{
			r = road[u][1];
		}
		
		if (!r.from)
		{
			sum1 += r.c;
		}
		pre = u;
		u = r.v;
	} while (u != 1);
	
	if (sum1 > sum - sum1)
	{
		sum1 = sum - sum1;
	}
	
	printf("%d\n", sum1);
	
	return 0;
}