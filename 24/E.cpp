#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 500005;
const double ERR = 1e-10;

int x[N];
int v[N];

int main()
{
	int n, i, start;
	double ans;
	bool bMeet = true;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &v[i]);
	}
	
	for (start = 0; start < n && v[start] < 0; start++);
	
	if (start >= n)
	{
		bMeet = false;
	}
	else
	{
		for (i = start + 1; i < n && v[i] > 0; i++);
		if (i >= n)
		{
			bMeet = false;
		}
	}
	
	if (bMeet)
	{
		double right, left;
		double a = 0.0, b = 1e9, mid;
		
		while (b - a > ERR)
		{
			mid = (a + b) / 2;
			bMeet = false;
			right = -1e9;
			for (i = start; i < n; i++)
			{
				if (v[i] > 0)
				{
					right = max(right, v[i]*mid + x[i]);
				}
				else
				{
					left = v[i]*mid + x[i];
					if (left < right)
					{
						bMeet = true;
						break;
					}
				}
			}
			
			if (bMeet)
			{
				b = mid;
			}
			else
			{
				a = mid;
			}
		}
		
		printf("%.10lf\n", b);
	}
	else
	{
		printf("%d\n", -1);
	}
	
	return 0;
}