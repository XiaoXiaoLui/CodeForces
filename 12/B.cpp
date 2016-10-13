#include <iostream>
#include <cstring>

using namespace std;

int toNumber(char *s)
{
	int num = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		num = num * 10 + (s[i] - '0');
	}
	return num;
}

int main()
{
	int n, m, i, j;
	char strM[12];
	int sum[10];
	int num = 0;
	
	cin >> n >> strM;
	m = toNumber(strM);
	
	memset(sum, 0, sizeof(sum));
	
	while (n)
	{
		sum[n%10]++;
		n /= 10;
	}
	
	int min;
	
	for (min = 1; min <= 9 && sum[min] == 0; min++);
	
	
	if (min <= 9)
	{
		num = min;
		sum[min]--;
	}
	else
	{
		num = 0;
		sum[0]--;
	}
	
	
	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j < sum[i]; j++)
		{
			num = num * 10 + i;
		}
	}
	

	if (num != m || (strM[0] == '0' && strM[1] != '\0'))
	{
		cout << "WRONG_ANSWER" << endl;
	}
	else
	{
		cout << "OK" << endl;
	}
	
	
	
	return 0;
}