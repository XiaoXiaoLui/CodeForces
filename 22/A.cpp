#include <iostream>
#include <algorithm>

using namespace std;
int a[105];

int main()
{
	int n, i;
	int *p;
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	sort(a, a+n);
	p = upper_bound(a, a + n, a[0]);
	
	if (p < a + n)
	{
		cout << *p << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}