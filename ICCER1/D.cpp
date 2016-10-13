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

const int N = 5e4 + 100;

int n;
int a[N];
set<int> ans;

bool find(int maxValue)
{
	ans.clear();
	int i, tmp;
	bool ok = true;
	for (i = 0; i < n; i++)
	{	
		ok = false;
		for (tmp = a[i]; tmp; tmp /= 2)
		{
			if (tmp <= maxValue && ans.find(tmp) == ans.end())
			{
				ans.insert(tmp);
				ok = true;
				break;
			}
		}
		
		if (!ok)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	int i, left, right, mid;
	bool ok = true;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sort(a, a + n);
	
	left = 0, right = 1e9;
	while (right - left > 1)
	{
		mid = (left + right) / 2;
		if (find(mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	
	find(right);
	
	
	for (set<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");
	return 0;
}