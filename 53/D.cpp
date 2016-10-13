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

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 300;

int a[N];
int b[N];

map<int, deque<int> > h;
vector<int> ans;

int main()
{
	int n, i, tmp, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		h[a[i]].push_back(i);
	}
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		b[i] = h[tmp].front();
		h[tmp].pop_front();
	}
	
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (b[j] > b[j + 1])
			{
				swap(b[j], b[j + 1]);
				ans.push_back(j + 1);
			}
		}
	}
	
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i], ans[i] + 1);
	}
	return 0;
}