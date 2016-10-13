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

const int N = 1e5 + 5;
char s[N];

int main()
{
	int len, i;
	scanf("%s", s);
	len = strlen(s);
	
	printf("%s", s);
	for (i = 0; i < len / 2; i++)
	{
		swap(s[i], s[len - 1 - i]);
	}
	printf("%s\n", s);
	return 0;
}