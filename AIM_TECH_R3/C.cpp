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

const int N = 1e5 + 50;
char s[N];

int main()
{
	int i, start;
	scanf("%s", s);
	
	for (i = 0; s[i] == 'a'; i++);
	
	if (s[i] != '\0')
	{
		for (; s[i] != '\0' && s[i] != 'a'; i++)
		{
			s[i] = (char)(s[i] - 1);
		}
	}
	else
	{
		s[i - 1] = 'z';
	}
	
	printf("%s\n", s);
	return 0;
}