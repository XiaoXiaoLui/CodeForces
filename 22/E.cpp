#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Instruction
{
	int x;
	int y;
};


const int N = 100005;

int next[N];
bool hasPre[N];
int end[N];
vector<Instruction> ans;
vector<int> ds[N];
bool hasDs[N];
int visit[N];

void dfs(int u, int c)
{
	visit[u] = c;
	
	int v = next[u];
	if (!visit[v])
	{
		dfs(v, c);
		end[u] = end[v];
	}
	else if (visit[v] == c)
	{
		end[u] = v;
	}
	else
	{
		end[u] = end[v];
	}
	
}

int main()
{
	int n, c, i, x, y, j;
	Instruction inst;
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> next[i];
		hasPre[next[i]] = true;
	}
	
	for (i = 1, c = 0; i <= n; i++)
	{
		if (visit[i])
		{
			continue;
		}
		
		c++;
		
		dfs(i, c);
		if (!hasDs[end[i]])
		{
			hasDs[end[i]] = true;
		}
		if (!hasPre[i])
		{
			ds[end[i]].push_back(i);
		}
	}
	
	int count = 1;
	int pre, cur, first, last;
	for (pre = 1; pre <= n && !hasDs[pre]; pre++);
	first = last = pre;

	for (cur = pre + 1; cur <= n; cur++)
	{
		if (!hasDs[cur])
		{
			continue;
		}
		
		if (ds[cur].size() > 0)
		{
			x = pre;
			y = ds[cur].back();
			ds[cur].pop_back();
		}
		else
		{
			x = pre;
			y = cur;
		}	
		
		inst.x = x;
		inst.y = y;
		ans.push_back(inst);
		
		last = pre = cur;
	}
	
	if (first != last)
	{
		inst.x = last;
		
		if (ds[first].size() > 0)
		{
			inst.y = ds[first].back();
			ds[first].pop_back();
		}
		else
		{
			inst.y = first;
		}
		ans.push_back(inst);
	}
	
	for (i = first; i <= last; i++)
	{
		if (ds[i].size() > 0)
		{
			for (j = 0; j < ds[i].size(); j++)
			{
				inst.x = i;
				inst.y = ds[i][j];
				ans.push_back(inst);
			}
		}
	}
	
	cout << ans.size() << endl;
	
	for (i = 0; i < ans.size(); i++)
	{
		cout << ans[i].x << " " << ans[i].y << endl;
	}
	
	return 0;
}