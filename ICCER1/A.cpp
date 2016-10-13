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



int main()
{
	int type;
	char s[10];
	
	scanf("%d%s", &type, s);
	
	if (type == 12)
	{
		if (s[0] == '0')
		{
			if (s[1] == '0')
			{
				s[1] = '1';
			}
		}
		else if (s[0] == '1')
		{
			if (s[1] > '2')
			{
				s[1] = '0';
			}
		}
		else
		{
			if (s[1] == '0')
			{
				s[0] = '1';
			}
			else
			{
				s[0] = '0';
			}
		}
		
		// for 3 and 4
		if (s[3] > '5')
		{
			s[3] = '0';
		}
	}
	else
	{
		if (s[0] <= '1')
		{
			
		}
		else if (s[0] == '2')
		{
			if (s[1] > '3')
			{
				s[0] = '0';
			}
		}
		else
		{
			s[0] = '0';
		}
		
		// for 3 and 4
		if (s[3] > '5')
		{
			s[3] = '0';
		}
	}
	
	printf("%s\n", s);
	return 0;
}