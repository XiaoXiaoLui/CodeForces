#include <cstdio>
#include <algorithm>

using namespace std;

int a[4];

int main()
{
	int i, index1, index2;
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	fscanf(in, "%d", &index1);
	a[index1] = 1;
	for (i = 0; i < 3; i++)
	{
		fscanf(in, "%d%d", &index1, &index2);
		swap(a[index1], a[index2]);
	}
	
	for (i = 1; i <= 3; i++)
	{
		if (a[i])
		{
			fprintf(out, "%d\n", i);
			break;
		}
	}
	
	return 0;
}