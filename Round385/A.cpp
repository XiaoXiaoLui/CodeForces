#include<bits/stdc++.h>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 1005;
const int M = 1e5 + 100;

int a[N];
int com[N];
int comSize[N];
int comEdgeNum[N];
bool special[N];
vector<int> graph[N];

void dfs(int u, int c)
{
	com[u] = c;
	comSize[c]++;
	
	for (auto v : graph[u])
	{
		if (!com[v])
		{
			dfs(v, c);
		}
	}
}

int main()
{
	// USE_IOSTREAM;
	int n, m, kNum, u, v, i;
	scanf("%d%d%d", &n, &m, &kNum);
	for (i = 1; i <= kNum; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		//edge[i] = {u, v};
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int comNum = 0;
	for (u = 1; u <= n; u++)
	{
		if (!com[u])
		{
			dfs(u, ++comNum);
		}
	}
	
	int res = 0;
	for (i = 1; i <= comNum; i++)
	{
		res += comSize[i] * (comSize[i] - 1) / 2;
	}
	res -= m;
	
	for (i = 1; i <= kNum; i++)
	{
		special[com[a[i]]] = true;
	}
	
	int maxSize = 0;
	for (i = 1; i <= comNum; i++)
	{
		if (special[i])
		{
			maxSize = max(maxSize, comSize[i]);
		}
	}
	
	int sum = 0;
	for (i = 1; i <= comNum; i++)
	{
		if (!special[i])
		{
			res += sum * comSize[i];
			sum += comSize[i];
		}
	}
	
	res += maxSize * sum;
	
	printf("%d\n", res);
	
	return 0;
}