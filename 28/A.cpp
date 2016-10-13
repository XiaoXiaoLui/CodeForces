#include <cstdio>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

const int N = 505;

struct Rod
{
	int len;
	int index;
	
	bool operator < (const Rod &other) const
	{
		return len < other.len;
	}
};

int x[N];
int y[N];
Rod rod[N];
int segLen[N];
vector<int> ans;
multiset<Rod> S;
int m, n;


int main()
{
	int i, pre, next;
	
	scanf("%d%d", &n, &m);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &rod[i].len);
		rod[i].index = i;
	}
	
	for (i = 0; i < n; i++)
	{
		pre = (i - 1 + n) % n;
		next = (i + 1) % n;
		segLen[i] = (x[pre] == x[i] ? abs(y[i]  - y[pre]) : abs(x[i] - x[pre]));
		segLen[i] += (x[next] == x[i] ? abs(y[i] - y[next]) : abs(x[i] - x[next]));
	}
	
	bool ok1 = true;
	bool ok2 = true;
	S.insert(rod + 1, rod + 1 + m);
	multiset<Rod>::iterator iter;
	Rod tmp;
	tmp.index = 0;
	for (i = 0; i <= n - 1; i++)
	{
		if ((i & 1) == 0)
		{
			ans.push_back(-1);
			continue;
		}
		tmp.len = segLen[i];
		iter = S.find(tmp);
		if (iter == S.end())
		{
			ok1 = false;
			break;
		}
		ans.push_back(iter->index);
		S.erase(iter);
	}
	
	if (!ok1)
	{
		S.clear();
		ans.clear();
		S.insert(rod + 1, rod + 1 + m);
		for (i = 0; i <= n - 1; i++)
		{
			if (i & 1)
			{
				ans.push_back(-1);
				continue;
			}
			tmp.len = segLen[i];
			iter = S.find(tmp);
			if (iter == S.end())
			{
				ok2 = false;
				break;
			}
			ans.push_back(iter->index);
			S.erase(iter);
		}
	}
	
	if (ok1 || ok2)
	{
		printf("YES\n");
		for (i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i]);
			
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}