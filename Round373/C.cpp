#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 2e5 + 100;

char init[N];
char s[N];

int main()
{
	int n, t, i, j, pos,  start;
	scanf("%d%d", &n, &t);
	scanf("%s", init);
	for (i = 0; init[i] != '.'; i++);
	pos = i;
	
	
	for (i = 0, j = 0; i < n; i++)
	{
		if (init[i] != '.')
		{
			s[j++] = init[i];
		}
	}
	s[j] = '\0';
	
	for (i = pos; i < n - 1 && s[i] < '5'; i++);
	
	if (i == n - 1)
	{
		printf("%s\n", init);
		return 0;
	}
	start = i;
	
	for (i = n; i > start; i--)
	{
		s[i] = '0';
	}
	
	bool flag = false;
	for (i = start; i >= pos && t; i--)
	{
		if (s[i] <= '4')
		{
			continue;
		}
		
		t--;
		s[i] = '0';
		while (s[i - 1] == '9')
		{
			if (i > 1)
			{
				s[--i] = '0';
			}
			else
			{
				flag = true;
				break;
			}
		}	
		
		if (flag)
		{
			break;
		}
		s[i - 1] += 1;
		
	}
	
	
	if (flag)
	{
		init[0] = '1';
		for (i = 1; i <= pos; i++)
		{
			init[i] = '0';
		}
		init[i] = '\0';
		printf("%s\n", init);
		return 0;
	}
	
	for (i = 0, j = 0; s[i] != '\0'; i++)
	{
		if (i == pos)
		{
			init[j++] = '.';
		}
		
		init[j++] = s[i];
	
	}
	
	init[j] = '\0';
	
	for (j--; j > pos && init[j] == '0'; j--)
	{
		init[j] = '\0';
	}
	
	if (j == pos)
	{
		init[pos] = '\0';
	}
	
	printf("%s\n", init);
	return 0;
}