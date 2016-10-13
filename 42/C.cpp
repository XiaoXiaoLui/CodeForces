#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;



struct Operation
{
	Operation(){}
	Operation(char ch, int i) : op(ch), index(i)
	{
	}
	char op;
	int index;
};

int a[4];
vector<Operation> ans;


int main()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &a[i]);
	}
	
	int pre, next, mid;
	for (i = 0; i < 4; i++)
	{
		pre = (i - 1 + 4) % 4;
		next = (i + 1) % 4;
		mid = (i + 2) % 4;
		while (a[i] != 1)
		{
			if (a[i] & 1)
			{
				if (a[pre] & 1)
				{
					a[i] = (a[i] + 1) / 2;
					a[pre] = (a[pre] + 1) / 2;
					ans.push_back(Operation('+', pre));
					ans.push_back(Operation('/', pre));
				}
				else if (a[next] & 1)
				{
					a[i] = (a[i] + 1) / 2;
					a[next] = (a[next] + 1) / 2;
					ans.push_back(Operation('+', i));
					ans.push_back(Operation('/', i));
				}
				else 
				{
					if (a[mid] & 1)
					{
						a[i] = (a[i] + 1) / 2;
						a[mid] = (a[mid] + 1) / 2;
						a[pre] /= 2;
						a[next] = (a[next] + 2) / 2;
						ans.push_back(Operation('+', i));
						ans.push_back(Operation('+', next));
						ans.push_back(Operation('/', i));
						ans.push_back(Operation('/', mid));
					}
					else
					{
						a[pre] /= 2;
						a[mid] /= 2;
						ans.push_back(Operation('/', mid));
					}
				}
			}
			else
			{
				if ((a[pre] & 1) == 0)
				{
					a[i] /= 2;
					a[pre] /= 2;
					ans.push_back(Operation('/', pre));
				}
				else if ((a[next] & 1) == 0)
				{
					a[i] /= 2;
					a[next] /= 2;
					ans.push_back(Operation('/', i));
				}
				else
				{
					a[i] = (a[i] + 2) / 2;
					a[pre]++;
					a[next] = (a[next] + 1) / 2;
					ans.push_back(Operation('+', pre));
					ans.push_back(Operation('+', i));
					ans.push_back(Operation('/', i));
				}
			}
		}
	}
	

	for (i = 0; i < ans.size(); i++)
	{
		printf("%c%d\n", ans[i].op, ans[i].index + 1);
	}

	
	printf("\n");
	return 0;
}