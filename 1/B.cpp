#include <cstdlib>
#include <cstdio>
#include <cctype>

#define N 20

bool isRxcy(char *str)
{
	char *p = str;
	bool ret = true;
	char *posR = str, *posC = str, *posEnd = str; 
	
	if (*p != 'R')
	{
		//ret = false;
		return false;
	}
	p++;
	
	for (; isdigit(*p); p++);
	posC = p;
	if (*p != 'C' || posC - posR < 2)
	{
		return false;
	}
	
	p++;
	for (; isdigit(*p); p++);
	
	if (*p != '\0' || p - posC < 2)
	{
		return false;
	}
	
	
	return true;
}

bool excel2Rxcy(char *org, char *dest)
{
	int col = 0;
	unsigned int base = 0;
	unsigned int exp26n = 1;
	char *p = org;

	for (p = org; isalpha(*p); p++)
	{
		col = col * 26 + ((int)*p - 'A'); // base 26
		
		base += exp26n;   // 1 + 26 + 26^2 + ... 
		exp26n *= 26;
	}
	col += base;
	
	sprintf(dest, "%R%sC%d", p, col);
	
	return true;
	
}

bool rxcy2Excel(char *org, char *dest)
{
	unsigned int row = 0;
	unsigned int col = 0;
	char colStr[N];
	
	char *p = org + 1;
	for (; isdigit(*p); p++)
	{
		row = row * 10 + ((int)*p - '0');
	}
	p++;
	for (; *p != '\0'; p++)
	{
		col = col * 10 + ((int)*p - '0');
	}
	
	// convert the col
	unsigned int base = 0;
	unsigned int lastBase = 0;
	unsigned int exp26n = 26;
	int len = 0;
	
	//col -= 1; // from 0 instead of 1
	while (base < col)
	{
		lastBase = base;
		base += exp26n;
		exp26n *= 26;
		len++;
	}
	
	int num = col - lastBase - 1; // base on 0 instead of 1
	
	
	//base 10 to base 26
	p = colStr + len;
	*p = '\0';
	p--;
	
	int remain = 0;
	char ch = 'A';
	while (num)
	{
		remain = num % 26;
		ch = (char)('A' + remain);
		*p-- = ch;
		num = num / 26;
	}
	
	for (; p >= colStr; p--)
	{
		*p = 'A';
	}
	
	sprintf(dest, "%s%d", colStr, row);
	
	return true;
}

int main()
{
	unsigned int n = 0;
	char org[N];
	char dest[N];
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", org);
		
		if (isRxcy(org))
		{
			rxcy2Excel(org, dest);
		}
		else
		{
			excel2Rxcy(org, dest);
		}
		
		printf("%s\n", dest);
	}
	
	return 0;
}