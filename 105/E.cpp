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

const int N = 3;

int pm[10];
int pos[N];
int lifting[N];
int lifted[N];
int range[N][2];
int ans;

bool valid()
{
	int i, p, act;
	bool res = true;
	for (i = 0; i < 9; i++)
	{
		p = pm[i] / N;
		act = pm[i] % N;
		if (act == 1)
		{
			lifting[p] = 1;
		}
		else if (act == 2)
		{
			if (lifting[p] == -1)
			{
				res = false;
				break;
			}
		}
	}
	fill(lifting, lifting + N, -1);
	
	return res;
}

void dfs(int idx)
{
	if (idx == 9)
	{
		return;
	}
	
	int p = pm[idx] / 3;
	int act = pm[idx] % 3;
	int i, j, oldPos, nextPos, p2, p3, start, end;
	if (act == 0) // walk
	{
		if (lifting[p] != -1 || lifted[p] != -1)
		{
			return;
		}
		if (idx == 8)
		{
			ans = max(ans, pos[p] + range[p][0]);
			return;
		}
		
		
		p2 = (p + 1) % N;
		p3 = (p + 2) % N;
		start = min(pos[p2], pos[p3]) - 1;
		start = max(start, pos[p] - range[p][0]);
		end = range[p][0] + pos[p];
		
		oldPos = pos[p];
		for (i = start; i <= end; i++, pos[p] = oldPos)
		{
			 pos[p] = i;
			 
			if (abs(pos[p] - oldPos) > range[p][0] || pos[p] <= 0 || pos[p] == pos[p2] || pos[p] == pos[p3])
			{
				continue;
			}
			
			ans = max(ans, pos[p]);
			dfs(idx + 1);
		}
	}
	else if (act == 1) // lift
	{
		if (lifting[p] != -1 || lifted[p] != -1)
		{
			return;
		}
		if (idx == 8)
		{
			ans = max(ans, pos[p] + range[p][1]);
			return;
		}
		
		int adj[2];
		adj[0] = max(1, pos[p] - 1);
		adj[1] = pos[p] + 1;
		
		
		for (j = 0; j < 2; j++)
		{
			for (i = 1; i <= 2; i++)
			{
				p2 = (p + 1) % N;
				p3 = (p + 2) % N;
				if (i == 2)
				{
					swap(p2, p3);
				}
				
				if (pos[p2] == adj[j] && lifted[p2] == -1)
				{
					if (lifting[p2] == -1)
					{
						pos[p2] = pos[p];
						lifting[p] = p2;
						lifted[p2] = p;
						dfs(idx + 1);
						lifting[p] = lifted[p2] = -1;
						pos[p2] = adj[j];
					}
					else
					{
						pos[p2] = pos[p3] = pos[p];
						lifting[p] = p2;
						lifted[p2] = p;
						dfs(idx + 1);
						lifting[p] = lifted[p2] = -1;
						pos[p2] = pos[p3] = adj[j];
					}
				}
			}	
		}
	}
	else
	{
		if (lifting[p] == -1 || lifted[p] != -1)
		{
			return;
		}
		
		p2 = lifting[p];
		for (i = 0; i < N; i++)
		{
			if (i != p && i != p2)
			{
				p3 = i;
				break;
			}
		}
		start = pos[p3] - 1;
		start = max(start, pos[p] - range[p][1]);
		end = range[p][1] + pos[p];
		
		for (i = start; i <= end; i++)
		{
			nextPos = i;
			if (nextPos <= 0 || nextPos == pos[p3] || nextPos == pos[p])
			{
				continue;
			}
			
			ans = max(ans, nextPos);
			if (lifting[p2] == p3)
			{
				pos[p2] = pos[p3] = nextPos;
				lifting[p] = lifted[p2] = -1;
				dfs(idx + 1);
				lifting[p] = p2;
				lifted[p2] = p;
				pos[p2] = pos[p3] = pos[p];
			}
			else
			{
				pos[p2] = nextPos;
				lifting[p] = lifted[p2] = -1;
				dfs(idx + 1);
				lifting[p] = p2;
				lifted[p2] = p;
				pos[p2] = pos[p];
			}
		}
	}
}

int main()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		scanf("%d%d%d", &pos[i], &range[i][0], &range[i][1]);
		ans = max(ans, pos[i]);
	}
	
	for (i = 0; i < 9; i++)
	{
		pm[i] = i;
	}
	
	fill(lifting, lifting + N, -1);
	fill(lifted, lifted + N, -1);
	
	do
	{
		if (valid())
		{
			dfs(0);
		}
	} while (next_permutation(pm, pm + 9));
	
	printf("%d\n", ans);
	return 0;
}