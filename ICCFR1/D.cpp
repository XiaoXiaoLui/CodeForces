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

const int N = 1e5 + 100;

char s[N];
char ans[N];
set<int> S;

int main()
{
	int m, n, i, j, idx;
	scanf("%d", &m);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	char ch = 'a';
	
	bool ok = false;
	
	set<int>::iterator iter1, iter2;
	S.clear();
	S.insert(0);
	S.insert(n + 1);
	//set<int> ansSet;
	
	while (ch <= 'z' && !ok)
	{
		for (i = 1; i <= n; i++)
		{
			if (s[i] == ch)
			{
				S.insert(i);
			}
		}
		
		
		ok = true;
		iter1 = iter2 = S.begin();
		for (iter2++; iter2 != S.end(); iter1++, iter2++)
		{
			if (*iter2 - *iter1 > m)
			{
				ok = false;
			}
		}
		if (ok)
		{
			break;
		}
		ch++;
	}
	
	for (i = 1; i <= n; i++)
	{
		if (s[i] == ch)
		{
			
			iter2 = S.upper_bound(i);
			iter1 = iter2;
			iter1--;
			iter1--;
			if (*iter2 - *iter1 <= m)
			{
				S.erase(i);
			}
		}
	}
	
	
	int len = 0;
	for (i = 1; i <= n; i++)
	{
		if (S.find(i) != S.end())
		{
			ans[len++] = s[i];
		}
	}
	sort(ans, ans + len);
	ans[len] = '\0';
	printf("%s\n", ans);
	return 0;
}