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


vector<int> ans;

void nextLine()
{
	while (getchar() != '\n');
}

ll numToPat(ll a)
{
	ll res = 0;
	ll tmp = 1;
	while (a)
	{
		if (a & 1)
		{
			res += tmp;
		}
		a /= 10;
		tmp *= 10;
	}
	
	return res;
}

struct Query
{
	char type;
	ll a;
};

Query q[N];

int main()
{
	int n, i, j;
	ll a;
	ll pat;
	char type;
	map<ll, int> record;
	
	scanf("%d", &n);
	nextLine();
	/*
	for (i = 0; i < n; i++)
	{
		scanf("%c", &type);
		q[i].type = type;
		if (type == '+')
		{
			scanf("%lld", &a);
			q[i].a = a;
		}
		else if (type == '-')
		{
			scanf("%lld", &a);
			q[i].a = a;
		}
		else
		{
			scanf("%lld", &pat);
			q[i].a = pat;
		}
		nextLine();
	}*/
	
	for (i = 0; i < n; i++)
	{
		scanf("%c", &type);
		if (type == '+')
		{
			scanf("%lld", &a);
			pat = numToPat(a);
			record[pat]++;
		}
		else if (type == '-')
		{
			scanf("%lld", &a);
			pat = numToPat(a);
			record[pat]--;
		}
		else
		{
			scanf("%lld", &pat);
			ans.push_back(record[pat]);
		}
		
		nextLine();
	}
		
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}