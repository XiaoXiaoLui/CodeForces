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


vector<int> ans;
int main()
{
	int a, b, c;
	scanf("%d%d", &a, &b);
	ans.push_back(b);
	bool ok = true;
	while (b > a)
	{
		if (b % 10 == 1)
		{
			b /= 10;
		}
		else if (b % 2 == 0)
		{
			b >>= 1;
		}
		else
		{
			ok = false;
			break;
		}
		ans.push_back(b);
	}
	
	if (b != a)
	{
		ok = false;
	}
	
	if (ok)
	{
		printf("YES\n%d\n", ans.size());
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}