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
	string str;
	int n, i;
	scanf("%d", &n);
	n--;
	str = "I hate ";
	for (i = 0; i < n; i++)
	{
		if (i & 1)
		{
			str += "that I hate ";
		}
		else
		{
			str += "that I love ";
		}
	}
	
	str += "it";
	
	printf("%s\n", str.c_str());
	return 0;
}