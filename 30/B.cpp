#include <cstdio>
#include <algorithm>

using namespace std;


int a[3];
int b[3];
int index[3];

void parse(char *str, int *array)
{
	array[0] = (str[0] - '0') * 10 + (str[1] - '0');
	array[1] = (str[3] - '0') * 10 + (str[4] - '0');
	array[2] = (str[6] - '0') * 10 + (str[7] - '0');
}

bool check()
{
	int day = index[0], mon = index[1], year = index[2];
	if (b[mon] < 1 || b[mon] > 12)
	{
		return false;
	}
	bool isLeap = !(b[year] % 4);
	
	int mn;
	if (b[mon] == 2)
	{
		mn = isLeap ? 29 : 28;
		if (b[day] < 1 || b[day] > mn)
		{
			return false;
		}
	}
	else if (b[mon] <= 7)
	{
		mn = (b[mon] % 2) ? 31 : 30;
		if (b[day] < 1 || b[day] > mn)
		{
			return false;
		}
	}
	else if (b[mon] >= 8)
	{
		mn = (b[mon] % 2) ? 30 : 31;
		if (b[day] < 1 || b[day] > mn)
		{
			return false;
		}
	}
	
	if (a[2] - b[year] < 18)
	{
		return false;
	}
	else if (a[2] - b[year] > 18)
	{
		return true;
	}
	else
	{
		if (b[mon] > a[1])
		{
			return false;
		}
		else if (b[mon] < a[1])
		{
			return true;
		}
		else
		{
			return b[day] <= a[0];
		}
	}
}

int main()
{
	char str1[20], str2[20];
	scanf("%s%s", str1, str2);
	parse(str1, a);
	parse(str2, b);
	
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		index[i] = i;
	}
	
	bool ok = false;
	do
	{
		ok = check();
	} while (!ok && next_permutation(index, index + 3));
	
	if (ok)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}