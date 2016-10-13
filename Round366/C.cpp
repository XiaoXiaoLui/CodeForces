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

const int N = 3e5 + 50;
int ans[N];
int q[N];


int main()
{
	int n, m, i, type, x, t, j;
	int left = 0;
	scanf("%d%d", &n, &m);
	set<pii> S;
	set<pii>::iterator iter1, iter2;
	
	int num = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d", &x);
			S.insert(mp(x, num));
			q[num++] = x;
			ans[i] = S.size();
		}
		else if (type == 2)
		{
			scanf("%d", &x);
			iter1 = S.upper_bound(mp(x - 1, 1e9));
			iter2 = iter1;
			for (; iter2 != S.end() && iter2->first == x; iter2++);
			S.erase(iter1, iter2);
			ans[i] = S.size();
		}
		else
		{
			scanf("%d", &t);
			for (j = left; j < t; j++)
			{
				S.erase(mp(q[j], j));
			}
			left = max(left, t);
			
			ans[i] = S.size();
		}
	}
	
	for (i = 0; i < m; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}