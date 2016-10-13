#include <cstdio>
#include <queue>
#include <algorithm>


using namespace std;

#define pii pair<int, int>
#define mp make_pair<int, int>

const int N = 55;

int n, m;
int a[N][N];
int dist[N][N];
queue<pii> Q[N];
//bool visit[N][N];
//bool pass[N][N][4];

const int DIR[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool inRange(int i, int j)
{
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

int main()
{
	int i, j, k, bestDist, row, col;
	pii bestPos;
	char ch;
	bool hasBlack = false;
	scanf("%d%d", &n, &m);
	while (getchar() != '\n');
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &ch);
			if (ch == 'B')
			{
				a[i][j] = 1;
				hasBlack = true;
			}
		}
		while (getchar() != '\n');
	}
	
	if (!hasBlack)
	{
		printf("0\n");
		return 0;
	}
	
	int curDist, maxDist;
	pii curPos;
	bestDist = N*N;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			// bfs
			fill((int*)dist, (int*)dist + N*N, -1);
			//fill((bool*)visit, (bool*)visit + N*N, false);
			
			dist[i][j] = 0;

			Q[0].push(mp(i, j));
			
			curDist = 0;
			while (!Q[curDist].empty())
			{
				curPos = Q[curDist].front();
				Q[curDist].pop();
				for (k = 0; k < 4; k++)
				{
					row = curPos.first + DIR[k][0];
					col = curPos.second + DIR[k][1];
					if (inRange(row, col) && dist[row][col] == -1)
					{
						if (a[row][col] == a[curPos.first][curPos.second])
						{
							dist[row][col] = curDist;
							Q[curDist].push(mp(row, col));
						}
						else
						{
							dist[row][col] = curDist + 1;
							Q[curDist + 1].push(mp(row, col));
						}
					}
				}
				
				if (Q[curDist].empty())
				{
					curDist++;
				}
			}
			
			maxDist = 0;
			for (row = 1; row <= n; row++)
			{
				for (col = 1; col <= m; col++)
				{
					if (a[row][col])
					{
						maxDist = max(maxDist, dist[row][col]);
					}
				}
			}
			
			if (maxDist < bestDist)
			{
				bestDist = maxDist;
				bestPos = mp(i, j);
			}
		}
	}
	
	printf("%d\n", bestDist + 1);
	
}