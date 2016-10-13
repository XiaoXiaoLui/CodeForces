#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;
int a[N];

int main()
{
	int n, X, i, ans;
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	
	fscanf(in, "%d%d", &n, &X);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d", &a[i]);
		a[i] = (n - i) * a[i];
	}
	sort(a, a + n);
	for (i = 0, ans = 0; i < n; i++)
	{
		if (a[i] <= X)
		{
			ans++;
			X -= a[i];
		}
		else
		{
			break;
		}
	}
	fprintf(out, "%d\n", ans);
	
	return 0;
}