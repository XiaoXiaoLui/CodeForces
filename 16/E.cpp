#include <iostream>

using namespace std;

const int N = 18;
const int M = 1 << 18;


double a[N][N];
double dp[M][N];


int main()
{
	int n, i, j, count, first, k, l;
	double sum;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	int end = 1 << n;
	for (i = 1; i < end; i++)
	{
		first = -1;
		for (j = 0, count = 0; j < n; j++)
		{
			if ((1 << j) & i)
			{
				count++;
				if (first == -1)
				{
					first = j;
				}
			}
		}
		
		if (count == 1)
		{
			dp[i][first] = 1.0;
			continue;
		}
		
		for (j = first; j < n; j++)
		{
			if ((1 << j) & i == 0)
			{
				continue;
			}
			
		
			for (k = first; k < n; k++)
			{
				if (((1 << k) & i) && k != j)
				{
					sum = 0;
					for (l = first; l < n; l++)
					{
						if (((1 << l) & i) && l != k)
						{
							sum += a[l][k];
						}
					}
					dp[i][j] += sum * 2 / (count * (count - 1)) * dp[i & ~(1 << k)][j];
				}
			}
		}
	}
	
	cout.setf(ios::fixed);
	cout.precision(8);
	for (j = 0; j < n; j++)
	{
		cout << dp[end - 1][j] << " ";
	}
	
	cout << endl;
}