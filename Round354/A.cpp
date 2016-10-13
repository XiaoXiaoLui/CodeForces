#include <iostream>

using namespace std;

const int N = 105;

int a[N];

int main()
{
	int i;
	int minIndex, maxIndex, ans;
	int n;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			minIndex = i;
		}
		if (a[i] == n)
		{
			maxIndex = i;
		}
	}
	
	int index1, index2;
	index1 = min(minIndex, maxIndex);
	index2 = max(minIndex, maxIndex);
	
	ans = max(index2 - 0, n - 1 - index1);
	
	cout << ans << endl;
	
	return 0;
}