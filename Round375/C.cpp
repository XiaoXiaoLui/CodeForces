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

const int N = 2050;
int a[N];
int b[N];
int c[N];

int main()
{
	int n, m, i, q, r, idx;
	int changeNum = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
		if (a[i] <= m)
		{
			c[a[i]]++;
		}
	}
	
	q = n / m;
	r = n % m;
	set<int> S1;
	set<int> S2;
	//set<int> S3;
	
	for (i = 1; i <= m; i++)
	{
		if (c[i] < q)
		{
			S1.insert(i);
		}
		else if (c[i] > q)
		{
			S2.insert(i);
		}
	}
	
	set<int>::iterator iter;
	for (i = 1; i <= n && !S1.empty(); i++)
	{
		if (a[i] > m)
		{
			changeNum++;
			iter = S1.begin();			
			b[i] = *iter;
			c[*iter]++;
			if (c[*iter] == q)
			{
				S1.erase(iter);
			}

		}
		else if (S2.find(a[i]) != S2.end())
		{
			changeNum++;
			idx = a[i];
			c[idx]--;
			if (c[idx] == q)
			{
				S2.erase(idx);
			}
			
			iter = S1.begin();			
			b[i] = *iter;
			c[*iter]++;
			if (c[*iter] == q)
			{
				S1.erase(iter);
			}
			
		}
	}
	
	
	printf("%d %d\n", q, changeNum);
	
	for (i = 1; i <= n; i++)
	{
		printf("%d ", b[i]);
	}
	
	printf("\n");
	return 0;
}