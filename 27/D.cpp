#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;

#define mp make_pair<int, int>
#define pi pair<int, int>

const int N = 105;
pi e[N];
int index[2 * N];
bool visit[2 * N];
vector<int> graph[2 * N];
stack<int> S;
char ans[N];

void dfs1(int u)
{
	visit[u] = true;
	int v;
	for (int i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (!visit[v])
		{
			dfs1(v);
		}
	}
	S.push(u);
}

void dfs2(int u, int count)
{
	visit[u] = true;
	int v;
	for (int i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (!visit[v])
		{
			dfs2(v, count);
		}
	}
	index[u] = count;
}

bool conflict(const pi &a, const pi &b)
{
	bool ret = false;
	if ((b.first > a.first && b.first < a.second && b.second > a.second) 
		|| (a.first > b.first && a.first < b.second && a.second > b.second))
	{
		ret = true;
	}
	
	return ret;
}

int main()
{
	int n, m, i, j, a, b, u;
	scanf("%d%d", &n, &m);
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		if (a > b)
		{
			swap(a, b);
		}
		e[i] = mp(a, b);
	}
	
	for (i = 1; i < m; i++)
	{
		for (j = i + 1; j <= m; j++)
		{
			if (conflict(e[i], e[j]))
			{
				graph[2*i].push_back(2*j + 1);
				graph[2*j + 1].push_back(2*i);
				
				graph[2*j].push_back(2*i + 1);
				graph[2*i + 1].push_back(2*j);

			}
		}
	}
	
	for (i = 1; i <= m; i++)
	{
		if (!visit[2*i])
		{
			dfs1(2*i);
		}
		if (!visit[2*i + 1])
		{
			dfs1(2*i + 1);
		}
	}
	
	for (i = 1; i <= m; i++)
	{
		visit[2*i] = false;
		visit[2*i + 1] = false;
	}
	
	int count = 0;
	while (!S.empty())
	{
		u = S.top();
		S.pop();
		if (!visit[u])
		{
			count++;
			dfs2(u, count);
		}
	}
	
	bool ok = true;
	ans[m] = '\0';
	for (i = 1; i <= m; i++)
	{
		if (index[2*i] == index[2*i + 1])
		{
			ok = false;
			break;
		}
		else if (index[2*i] < index[2*i + 1])
		{
			ans[i - 1] = 'o';
		}
		else
		{
			ans[i - 1] = 'i';
		}
	}
	
	if (ok)
	{
		printf("%s\n", ans);
	}
	else
	{
		printf("Impossible\n");
	}
	return 0;
}

