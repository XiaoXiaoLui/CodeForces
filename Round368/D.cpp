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

const int N = 1005;
const int M = 1e5 + 50;

bool a[N][N];
bool rev[N];
int rowNum[N];
int totalNum;
int n, m;

bool add(int i, int j)
{
	if (!(rev[i] ^ a[i][j]))
	{
		rowNum[i]++;
		totalNum++;
		a[i][j] = !a[i][j];
		
		return true;
	}
	
	return false;
}

bool remove(int i, int j)
{
	if (rev[i] ^ a[i][j])
	{
		rowNum[i]--;
		totalNum--;
		a[i][j] = !a[i][j];
		
		return true;
	}
	return false;
}

void reverse(int i)
{
	rev[i] = !rev[i];
	totalNum -= rowNum[i];
	rowNum[i] = m - rowNum[i];
	totalNum += rowNum[i];
}

struct Edge
{
	Edge(){}
	Edge(int t, int r, int c, int vv) : type(t), row(r), col(c), v(vv)
	{
		
	}
	
	int type;
	int row;
	int col;
	int v;
};

vector<Edge> graph[M];
int state[M];
int stateCount;


int ans[M];

void dfs(int u)
{
	ans[u] = totalNum;
	
	int i;
	bool changed;
	for (i = 0; i < graph[u].size(); i++)
	{
		Edge e = graph[u][i];
		if (e.type == 1)
		{
			changed = add(e.row, e.col);
			dfs(e.v);
			if (changed)
			{
				remove(e.row, e.col);
			}
		}
		else if (e.type == 2)
		{
			changed = remove(e.row, e.col);
			dfs(e.v);
			if (changed)
			{
				add(e.row, e.col);
			}
		}
		else
		{
			reverse(e.row);
			dfs(e.v);
			reverse(e.row);
		}
	}
}

int main()
{
	int qNum, i, k, type, row, col, j, curState;
	scanf("%d%d%d", &n, &m, &qNum);
	
	state[0] = 0;
	curState = 0;
	for (i = 1; i <= qNum; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d%d", &row, &col);
			++stateCount;
			state[i] = stateCount;
			graph[curState].push_back(Edge(type, row, col, stateCount));
		}
		else if (type == 2)
		{
			scanf("%d%d", &row, &col);
			++stateCount;
			state[i] = stateCount;
			graph[curState].push_back(Edge(type, row, col, stateCount));
			
		}
		else if (type == 3)
		{
			scanf("%d", &row);
			++stateCount;
			state[i] = stateCount;
			graph[curState].push_back(Edge(type, row, col, stateCount));
			
		}
		else
		{
			scanf("%d", &k);	
			state[i] = state[k];
		}
		
		curState = state[i];
	}
	
	dfs(0);
	
	for (i = 1; i <= qNum; i++)
	{
		printf("%d\n", ans[state[i]]);
	}

	
	printf("\n");
	return 0;
}