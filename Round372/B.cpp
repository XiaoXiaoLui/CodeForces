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

const int N = 5e5 + 100;

char s[N];

int main()
{
	int n, i, j;
	char c;
	bool ok = false;
	scanf("%s", s);
	n = strlen(s);
	set<char> S;
	for (i = 0; i <= n - 26; i++)
	{
		bool partOk = true;
		S.clear();
		for (j = i; j < i + 26; j++)
		{
			if (s[j] != '?')
			{
				if (S.find(s[j]) != S.end())
				{
					partOk = false;
					break;
				}
				else
				{
					S.insert(s[j]);
				}
			}
		}
		
		if (partOk)
		{
			ok = true;
			break;
		}
	}
	
	if (ok)
	{
		for (j = i; j < i + 26; j++)
		{
			if (s[j] == '?')
			{
				for (c = 'A'; c <= 'Z' && S.find(c) != S.end(); c++)
				{
				}
				S.insert(c);
				s[j] = c;
			}
			
		}
		for (i = 0; i < n; i++)
		{
			if (s[i] == '?')
			{
				s[i] = 'A';
			}
		}
		printf("%s\n", s);
	}
	else
	{
		printf("-1\n");
	}
	
	
	return 0;
}