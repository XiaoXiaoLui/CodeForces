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

const int N = 110;
char s[N];
vector<int> ans;

int main()
{
	int n, i;
	scanf("%d", &n);
	scanf("%s", s + 1);
	s[0] = 'B';
	s[n + 1] = 'W';
	
	int cur = 0;
	for (i = 1; i <= n + 1; i++)
	{
		if (s[i] == 'B')
		{
			cur++;
		}
		else
		{
			if (cur)
			{
				ans.push_back(cur);
			}
			cur = 0;
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
	
	
	printf("\n");
	return 0;
}