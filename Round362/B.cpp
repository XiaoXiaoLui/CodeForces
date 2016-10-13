#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 500;
int ans[N];
char str[N];

int main()
{
	int i, exp, pos, len, start, end;
	
	scanf("%s", &str);
	for (i = 0, len = 0; str[i] != 'e'; i++)
	{
		if (str[i] == '.')
		{
			pos = i;
		}
		else
		{
			ans[len++] = str[i] - '0';
		}
	}
	
	for (exp = 0, i++; str[i]; i++)
	{
		exp = 10*exp + (str[i] - '0');
	}
	pos += exp;
	len = max(len, pos);
	
	for (start = 0; start < pos - 1 && !ans[start]; start++);
	for (end = len - 1; end >= pos && !ans[end]; end--);
	
	
	for (i = start; i < pos; i++)
	{
		printf("%d", ans[i]);
	}
	if (end >= pos)
	{
		printf(".");
		for (i = pos; i <= end; i++)
		{
			printf("%d", ans[i]);
		}
	}
	
	return 0;
}