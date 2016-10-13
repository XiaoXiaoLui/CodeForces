#include <iostream>

using namespace std;

#define N 1000002

char a[N];
char b[N];

int c1[N];
int c2[N];

int sum[10];


int digitCount(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	
	return count;
}

void print(int digit, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << digit;
	}
}

int main()
{
	int n, i, digit, j, mid;
	int len1 = 0;
	int len2 = 0;
	bool less;
	
	cin >> a;
	cin >> b;
	
	for (i = 0; a[i] != '\0'; i++)
	{
		digit = a[i] - '0';
		sum[digit]++;
	}
	len1 = i;
	
	for (i = 0; b[i] != '\0'; i++)
	{
		digit = b[i] - '0';
		sum[digit]--;
	}
	len2 = i;
	
	
	for (i = len1 - 8; i < len1; i++)
	{
		if (i + digitCount(i) == len1)
		{
			break;
		}
	}
	
	int k = i;
	while (k)
	{
		sum[k % 10]--;
		k /= 10;
	}
	
	for (i = 1; i <= 9 && sum[i] == 0; i++)
	{
	}
	
	if (i > 9)
	{
		cout << b;
		print(0, sum[0]);
		cout << endl;
		goto END;
	}
	
	mid = b[0] - '0';
	if (i < mid || mid == 0)
	{
		cout << i;
		sum[i]--;
		for (i = 0; i < mid; i++)
		{
			print(i, sum[i]);
		}
		
		less = true;
		for (i = 1; i < len2 ; i++)
		{
			if (mid < b[i] - '0')
			{
				less = true;
				break;
			}
			else if (mid > b[i] - '0')
			{
				less = false;
				break;
			}
		}
		
		if (less)
		{
			print(mid, sum[mid]);
			cout << b;
		}
		else
		{
			cout << b;
			print(mid, sum[mid]);
		}
		
		for (i = mid + 1; i <= 9; i++)
		{
			print(i, sum[i]);
		}
	}
	else if (i > b[0]  - '0')
	{
		cout << b;
		for (i = 0; i <= 9; i++)
		{
			print(i, sum[i]);
		}
	}
	else
	{
		less = true;
		
		c1[0] = mid;
		for (i = 1; i < sum[0] + 1; i++)
		{
			c1[i] = 0;
		}
		for (i = sum[0] + 1, j = 0; i < sum[0] + 1 + len2; i++, j++)
		{
			c1[i] = b[j] - '0';
		}
		
		for (i = 0; i < len2; i++)
		{
			c2[i] = b[i] - '0';
		}
		c2[len2] = mid;
		for (i = len2 + 1; i < sum[0] + 1 + len2; i++)
		{
			c2[i] = 0;
		}
		
		for (i = 0; i < sum[0] + 1 + len2 && c1[i] == c2[i]; i++);
		
		if (i == sum[0] + 1 + len2)
		{
			less = false;
		}
		else if (c1[i] < c2[i])
		{
			less = true;
		}
		else
		{
			less = false;
		}

		if (less)
		{
			cout << mid;
			sum[mid]--;
			for (i = 0; i < mid; i++)
			{
				print(i, sum[i]);
			}
			
			less = true;
			for (i = 1; i < len2 ; i++)
			{
				if (mid < b[i] - '0')
				{
					less = true;
					break;
				}
				else if (mid > b[i] - '0')
				{
					less = false;
					break;
				}
			}
			
			if (less)
			{
				print(mid, sum[mid]);
				cout << b;
			}
			else
			{
				cout << b;
				print(mid, sum[mid]);
			}
			
			for (i = mid + 1; i <= 9; i++)
			{
				print(i, sum[i]);
			}
		}
		else
		{
			cout << b;
			for (i = 0; i <= 9; i++)
			{
				print(i, sum[i]);
			}
		}
	}
	cout << endl;
	
END:
	return 0;
}