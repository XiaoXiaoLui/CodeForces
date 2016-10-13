//#include <iostream>
#include <cstdio>

#define M 127
#define N 5000005

char str[N];
int degree[N];

using namespace std;

int main()
{
	int sum = 0;
	int p = 1;
	int a = 0;
	int b = 0;
	degree[0] = 0;
	
	gets(str);
	
	for (int i = 0; str[i]; i++)
	{
		a = a * M + str[i];
		b = b + str[i] * p;
		p *= M;
		
		if (a == b)
		{
			degree[i + 1] = degree[(i + 1) / 2] + 1;
		}
		else
		{
			degree[i + 1] = 0;
		}
		
		sum += degree[i + 1];
	}
	
	//cout << sum << endl;
	printf("%d\n", sum);
	
	return 0;
}