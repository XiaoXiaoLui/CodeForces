#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1e6 + 2;
int len;
char ans[N][25];

int main()
{
	char op[20];
	int i, n, a;
	priority_queue<int, vector<int>, greater<int> > Q;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", op);
		if (!strcmp(op, "insert"))
		{
			scanf("%d", &a);
			Q.push(a);
			sprintf(ans[len++], "insert %d\n", a);
		}
		else if (!strcmp(op, "getMin"))
		{
			scanf("%d", &a);
			if (Q.empty())
			{
				Q.push(a);
				sprintf(ans[len++], "insert %d\n", a);
			}
			else if (Q.top() != a)
			{
				while (!Q.empty() && Q.top() < a)
				{
					Q.pop();
					sprintf(ans[len++], "removeMin\n");
				}
				if (Q.empty() || Q.top() > a)
				{
					Q.push(a);
					sprintf(ans[len++], "insert %d\n", a);
				}
			}
			
			sprintf(ans[len++], "getMin %d\n", a);
		}
		else
		{
			if (Q.empty())
			{
				Q.push(1);
				sprintf(ans[len++], "insert 1\n");
			}
			Q.pop();
			sprintf(ans[len++], "removeMin\n");
		}
	}
	
	printf("%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%s", ans[i]);
	}
	
	
	return 0;
}