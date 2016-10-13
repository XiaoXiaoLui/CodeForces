#define LLD "%I64d"


#include <cstdio>

typedef long long ll;

const int N = 305;

struct Road
{
	int u;
	int v;
	int w;
};

ll graph[N][N];
Road road[N];


int main()
{
	int n, k, i, j, l;
	ll sum = 0;;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf(LLD, &graph[i][j]);
		}
	}
	
	scanf("%d", &k);
	
	for (i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &road[i].u, &road[i].v, &road[i].w);
	}
	
	int u, v, w;
	for (l = 1; l <= k; l++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				u = road[l].u;
				v = road[l].v;
				w = road[l].w;
				
				if (graph[i][u] + w + graph[v][j] < graph[i][j])
				{
					graph[i][j] = graph[i][u] + w + graph[v][j];
				}
				
				if (graph[i][v] + w + graph[u][j] < graph[i][j])
				{
					graph[i][j] = graph[i][v] + w + graph[u][j];
				}
			}
		}
		
		sum = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (j > i)
				{
					sum += graph[i][j];
				}
			}
		}
		printf(LLD " ", sum);
	}
	
	printf("\n");
	
	return 0;
}