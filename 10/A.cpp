#include <iostream>


using namespace std;

#define N 102

int main()
{
	int n, p1, p2, p3, t1, t2, i;
	int a[N][2];
	int interval;
	int sum = 0;
	
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1];
		sum += (a[i][1] - a[i][0]) * p1;
	}
	
	for (i = 1; i < n; i++)
	{
		interval = a[i][0] - a[i - 1][1];
		
		if (interval <= t1)
		{
			sum += interval * p1;
		}
		else if (interval <= t1 + t2)
		{
			sum += t1 * p1;
			sum += (interval - t1) * p2;
		}
		else
		{
			sum += t1 * p1;
			sum += t2 * p2;
			sum += (interval - t1 - t2) * p3;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}