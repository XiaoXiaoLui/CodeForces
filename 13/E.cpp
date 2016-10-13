#include <cstdio>
#include <cmath>

using namespace std;

const int N = 100002;

int n;
int blockLen;
int power[N];
int next[N];
int count[N];

int getBlock(int i)
{
	return (i - 1) / blockLen;
}

int getBlockStart(int i)
{
	return ((i - 1) / blockLen) * blockLen + 1;
}


int main()
{
	int n, m, i, j, sum, start;
	
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &power[i]);
	}
	
	blockLen = (int)sqrt(n);
	
	for (i = n; i >= 1; i--)
	{
		j = i + power[i];
		
		if (j > n)
		{
			next[i] = n + 1;
			count[i] = 1;
		}
		else if (getBlock(i) != getBlock(j))
		{
			next[i] = j;
			count[i] = 1;
		}
		else
		{
			next[i] = next[j];
			count[i] = count[j] + 1;
		}
	}
	
	
	
	int type, a, b;
	for (int k = 1; k <= m; k++)
	{
		scanf("%d", &type);
		if (type == 0)
		{
			scanf("%d%d", &a, &b);
			
			power[a] = b;
			start = getBlockStart(a);
			
			for (i = a; i >= start; i--)
			{
				j = i + power[i];
				
				if (j > n)
				{
					next[i] = n + 1;
					count[i] = 1;
				}
				else if (getBlock(i) != getBlock(j))
				{
					next[i] = j;
					count[i] = 1;
				}
				else
				{
					next[i] = next[j];
					count[i] = count[j] + 1;
				}
			}
		}
		else
		{
			scanf("%d", &a);
			sum = 0;
			
			j = a;
			while (next[j] <= n)
			{
				sum += count[j];
				j = next[j];
			}
			sum += count[j];
			
			while (j + power[j] <= n)
			{
				j = j + power[j];
			}
			
			printf("%d %d\n", j, sum);
		}
	}
	
	return 0;
}