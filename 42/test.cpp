#include <cstdio>


int start = 1;
int end = 20;

/*
inline int fun(int i, int j)
{
	return (i*i + j*j)*40 + i + j;
}*/
int f[20];

int main()
{
	int i, j, k, l,sum, t;
	
	f[0] = 1;
	f[1] = 2;
	f[2] = 3;
	t = 3;
	for (i = 3; i < end; i++)
	{
		for (t++; t <= 1000; t++)
		{
			bool ok = true;
			for (j = 0; j < i && ok; j++)
			{
				for (k = j + 1; k < i && ok; k++)
				{
					for (l = 0; l < i; l++)
					{
						if (l == j || l == k)
						{
							continue;
						}
						
						if (f[j] + f[k] == t + f[l])
						{
							ok = false;
							break;
						}
					}
				}
			}
			if (ok)
			{
				f[i] = t;
				break;
			}
		}
	}
	
	for (i = 0; i < end; i++)
	{
		printf("%d, ", f[i]);
	}
	printf("\n");
	return 0;
}