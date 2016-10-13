#include <iostream>

using namespace std;

int calDigits(int k)
{
	int count = 0;
	while (k)
	{
		count++;
		k /= 10;
	}
	
	return count;
}

int getN(int a, int k)
{
	int num = calDigits(a) - k;
	for (int i = 0; i < num; i++)
	{
		a /= 10;
	}
	
	return a % 10;
}

int main()
{
	int n, i;
	
	int preTotal = 0;
	int total = 0;
	cin >> n;
	for (i = 1; total < n; i++)
	{
		preTotal = total;
		total += calDigits(i);
		if (total >= n)
		{
			break;
		}
	}
	
	if (total == n)
	{
		cout << i % 10 << endl;
	}
	else
	{
		int num = n - preTotal;
		cout << getN(i, num) << endl;
	}
	
	return 0;
}