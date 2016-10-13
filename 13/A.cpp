#include <iostream>

using namespace std;

int getDigitSum(int n, int base)
{
	int sum = 0;
	while (n)
	{
		sum += n % base;
		n /= base;
	}
	
	return sum;
}

int gcd(int a, int b)
{
	int tmp;
	while (a % b)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	
	return b;
}

int main()
{
	int n;
	
	cin >> n;
	
	int a = 0;
	int b = n - 2;
	for (int i = 2; i < n; i++)
	{
		a += getDigitSum(n, i);
	}
	
	int g = gcd(a, b);
	
	cout << a / g << "/" << b / g << endl;
	
	return 0;
}