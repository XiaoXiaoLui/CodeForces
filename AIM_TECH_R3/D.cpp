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

const int N = 1e6 + 50;

vector<int> ans;

/*
(n - 1)*n / 2 = a
*/
int fun(int a)
{
	int res = 0;
	for (res = 0; res * (res - 1) < 2 * a; res++)
	{
		
	}
	
	return res;
}

int main()
{
	int a00, a01, a10, a11, n, m, c, d, b, i;
	bool ok = true;
	
	scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
	
	if (a00 == 0 && a11 != 0)
	{
		m = fun(a11);
		if (m * (m - 1) / 2 != a11)
		{
			ok = false;
		}
		else
		{
			if (a10 + a01 == 0)
			{
				for (i = 1; i <= m; i++)
				{
					ans.push_back(1);
				}
			}
			else if (a10 + a01 == m)
			{
				for (i = 1; i <= a10; i++)
				{
					ans.push_back(1);
				}
				ans.push_back(0);
				for (i = 1; i <= a01; i++)
				{
					ans.push_back(1);
				}
			}
			else
			{
				ok = false;
			}
		}
	}
	else if (a00 != 0 && a11 == 0)
	{
		n = fun(a00);
		if (n * (n - 1) / 2 != a00)
		{
			ok = false;
		}
		else
		{
			if (a10 + a01 == 0)
			{
				for (i = 1; i <= n; i++)
				{
					ans.push_back(0);
				}
			}
			else if (a10 + a01 == n)
			{
				for (i = 1; i <= a01; i++)
				{
					ans.push_back(0);
				}
				ans.push_back(1);
				for (i = 1; i <= a10; i++)
				{
					ans.push_back(0);
				}
			}
			else
			{
				ok = false;
			}
		}
	}
	else if (a00 == 0 && a11 == 0)
	{
		if (a10 == 0 && a01 == 0)
		{
			ans.push_back(0);
		}
		else if (a10 == 1 && a01 == 0)
		{
			ans.push_back(1);
			ans.push_back(0);
		}
		else if (a10 == 0 && a01 == 1)
		{
			ans.push_back(0);
			ans.push_back(1);
		}
		else
		{
			ok = false;
		}
	}
	else
	{
		n = fun(a00);
		m = fun(a11);
		
		if (n * (n - 1) / 2 != a00 || m * (m - 1) / 2 != a11)
		{
			ok = false;
		}
		else
		{
			if (m * n != a10 + a01)
			{
				ok = false;
			}
			else
			{
				b = a01 / m;
				d = a01 % m;
				c = m - d;
				
				for (i = 1; i <= b; i++)
				{
					ans.push_back(0);
				}
				for (i = 1; i <= c; i++)
				{
					ans.push_back(1);
				}
				if (n - b > 0)
				{
					ans.push_back(0);
				}
					
				for (i = 1; i <= d; i++)
				{
					ans.push_back(1);
				}
				for (i = 1; i <= n - b - 1; i++)
				{
					ans.push_back(0);
				}
			}
		}
	}
	
	
	
	if (ok)
	{
		for (i = 0; i < ans.size(); i++)
		{
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Impossible\n");
	}
	
	return 0;
}