#include <cstdio>
#include <vector>


using namespace std;

#define MP make_pair<int, int>
#define PII pair<int, int>

const int N = 305;

int order[N];
vector<int> graph[N];
vector<int> ans;

bool dfs(int u, vector<int> &result, PII &range, int pre)
{
	int v, i, j;
	bool ok = true;
	result.push_back(u);
	vector<int> res[N];
	PII rng[N];
	int used[N];
	int len = 0;
	

	for (i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (v == pre)
		{
			continue;
		}
		if (!dfs(v, res[len], rng[len], u))
		{
			ok = false;
			break;
		}
		len++;
	}
	
	fill(used, used + len, 0);
	range = MP(-1, -1);
	PII tmp;
	int tmpIndex;
	for (i = 0; i < len && ok; i++)
	{
		tmp = MP(500, 500);
		for (j = 0; j < len; j++)
		{
			if (used[j])
			{
				continue;
			}
			if (rng[j].second < tmp.first)
			{
				tmp = rng[j];
				tmpIndex = j;
			}
			else if (tmp.second < rng[j].first)
			{
				
			}
			else
			{
				ok = false;
				break;
			}
		}
		
		if (!ok)
		{
			break;
		}
		
		used[tmpIndex] = 1;
		result.insert(result.end(), res[tmpIndex].begin(), res[tmpIndex].end());
		result.push_back(u);
		range.second = tmp.second;
		if (range.first == -1)
		{
			range.first = tmp.first;
		}
	}
	
	if (graph[u].size() == 1 && u != 1)
	{
		range = MP(order[u], order[u]);
	}

	
	return ok;
}

int main()
{
	bool ok = true;
	int n, m, i, u, v;
	PII range;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (i = 2, m = 0; i <= n; i++)
	{
		if (graph[i].size() == 1)
		{
			m++;
		}
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &u);
		order[u] = i;
	}
	
	ok = dfs(1, ans, range, 0);
	if (ok)
	{
		for (i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	
	
	return 0;
}