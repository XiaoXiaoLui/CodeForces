#include <cstdio>
#include <queue>

using namespace std;

#define pii pair<int, int> 
#define mp make_pair<int, int>

const int N = 2005;

int n, m;
int dist[N][N];

bool inRange(int i, int j)
{
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
	int i, j, k, num, maxDist;
	queue<pii> Q;
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	
	fscanf(in, "%d%d%d", &n, &m, &num);
	fill((int*)dist, (int*)dist + N*N, -1);
	for (k = 1; k <= num; k++)
	{
		fscanf(in, "%d%d", &i, &j);
		dist[i][j] = 0;
		Q.push(mp(i, j));
	}
	
	pii curPos, nextPos, maxPos;
	maxDist = -1;
	while (!Q.empty())
	{
		curPos = Q.front();
		Q.pop();
		
		if (dist[curPos.first][curPos.second] > maxDist)
		{
			maxDist = dist[curPos.first][curPos.second];
			maxPos = mp(curPos.first, curPos.second);
		}
		
		for (k = 0; k < 4; k++)
		{
			i = curPos.first + DIR[k][0];
			j = curPos.second + DIR[k][1];
			if (inRange(i, j) && dist[i][j] == -1)
			{
				dist[i][j] = dist[curPos.first][curPos.second] + 1;
				Q.push(mp(i, j));
			}
		}
	}
	
	fprintf(out, "%d %d\n", maxPos.first, maxPos.second);
	
	return 0;
}