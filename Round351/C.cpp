#include <iostream>
#include <cstring>

using namespace std;

const int N = 5002;

int a[N];
int count[N];
int b[N];

int main()
{
	int n, i, j;
	cin >> n;
	
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int max = 0;
	int maxIndex = 0;
	for (i = 1; i <= n; i++)
	{
		max = 0;
		maxIndex = 0;
		memset(count, 0, sizeof(count));
		for (j = i; j <= n; j++)
		{
			count[a[j]]++;
			if (count[a[j]] > max || (count[a[j]] == max && a[j] < maxIndex))
			{
				max = count[a[j]];
				maxIndex = a[j];
			}
			b[maxIndex]++;
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	
	return 0;
}