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
	int n, i, a, b, c;
	set<int> S;
	bool ok = true;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		S.insert(a);
	}
	
	if (S.size() <= 2)
	{
	}
	else if (S.size() == 3)
	{
		set<int>::iterator iter = S.begin();
		a = *iter;
		iter++;
		b = *iter;
		iter++;
		c = *iter;
		if (a + c != 2*b)
		{
			ok = false;
		}
	}
	else
	{
		ok = false;
	}
	
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