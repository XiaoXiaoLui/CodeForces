#include <iostream>

using namespace std;

#define N 2002
int a[N];

int main()
{
	int n, d, moves, count = 0;
	
	cin >> n >> d;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 2; i <= n; i++)
	{
		if (a[i] <= a[i - 1])
		{
			moves = (a[i - 1] - a[i]) / d + 1;
			count += moves;
			a[i] += moves * d;
		}
	}
	
	cout << count << endl;
	return 0;
}