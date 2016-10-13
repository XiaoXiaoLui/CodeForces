#include <iostream>

using namespace std;

#define N 10

int count(int a[], int len)
{
	if (len == 0)
	{
		return 1;
	}
	
	if (a[len - 1] > 1)
	{
		return (1 << len);
	}
	else if (a[len - 1] == 1)
	{
		return (1 << len - 1) + count(a, len - 1);
	}
	else
	{
		return count(a, len - 1);
	}
}

int main()
{
	int n;
	int a[N];
	int len = 0;
	
	cin >> n;
	
	while (n)
	{
		a[len++] = n % 10;
		
		n /= 10;
	}
	
	int num = count(a, len) - 1;
	
	cout << num << endl;
	
	return 0;
}