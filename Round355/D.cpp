#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Position
{
	Position(){}
	Position(int x, int y)
	{
		row = x;
		col = y;
	}
	int row;
	int col;
	int dist;
};

const int N = 305;

int n, m;
vector<Position> box[N * N];
queue<Position> bfs;
int d[N][N];


bool cmp(const Position &pos1, const Position &pos2)
{
	return pos1.dist < pos2.dist;
}

int offset[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool legal(const Position &pos)
{
	return (pos.row >= 1 && pos.row <= n && pos.col >= 1 && pos.col <= m);
}

int main()
{
	int i, j, k, p, a;
	
	
	scanf("%d%d%d", &n, &m, &p);
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a);
			box[a].push_back(Position(i, j));
		}
	}
	
	for (i = 0; i < box[1].size(); i++)
	{
		box[1][i].dist = (box[1][i].row - 1) + (box[1][i].col - 1);
	}
	
	for (i = 2; i <= p; i++)
	{
		if (box[i].size() * box[i - 1].size() < m*n)
		{
			for (j = 0; j < box[i].size(); j++)
			{
				box[i][j].dist = 1e9;
			}
			
			for (j = 0; j < box[i].size(); j++)
			{
				for (k = 0; k < box[i - 1].size(); k++)
				{
					box[i][j].dist = min(box[i][j].dist, box[i - 1][k].dist + abs(box[i][j].row - box[i - 1][k].row) + abs(box[i][j].col - box[i - 1][k].col));
				}
			}
		}
		else
		{
			for (j = 1; j <= n; j++)
			{
				for (k = 1; k <= m; k++)
				{
					d[j][k] = -1;
				}
			}
			
			sort(box[i - 1].begin(), box[i - 1].end(), cmp);
			bfs.push(box[i - 1][0]);
			d[box[i - 1][0].row][box[i - 1][0].col] = box[i - 1][0].dist;
			Position cur, next;
			int p = 0;
			while (!bfs.empty())
			{
				cur = bfs.front();
				bfs.pop();
				for (; p < box[i - 1].size() && box[i - 1][p].dist == cur.dist; p++)
				{
					bfs.push(box[i - 1][p]);
					d[box[i - 1][p].row][box[i - 1][p].col] = box[i - 1][p].dist;
				}
				
				for (j = 0; j < 4; j++)
				{
					next.row = cur.row + offset[j][0];
					next.col = cur.col + offset[j][1];
					
					if (legal(next) && d[next.row][next.col] == -1)
					{
						next.dist = d[next.row][next.col] = d[cur.row][cur.col] + 1;
						bfs.push(next);
					}
				}
			}

			for (j = 0; j < box[i].size(); j++)
			{
				box[i][j].dist = d[box[i][j].row][box[i][j].col];
			}
		}
			
		
	}
	
	printf("%d\n", box[p][0].dist);
	
	return 0;
}