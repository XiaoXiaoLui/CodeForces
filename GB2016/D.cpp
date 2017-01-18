// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 360;
enum Direction
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	UPLEFT,
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT
};

const int OFFSET[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0},
							{-1, 1}, {1, 1}, {-1, -1}, {1, -1}};

int visit[N][N][4];
int mark[N][N];
int t[40];
int n;
int ans;

struct State
{
	State(){}
	State(int xx, int yy, Direction dd, int ll)
	{
		x = xx;
		y = yy;
		dir = dd;
		level = ll;
	}
	int x;
	int y;
	Direction dir;
	int level;
};

void go(int &x, int &y, int len, Direction dir)
{
	for (int i = 0; i < len; i++)
	{
		mark[x][y] = 1;
		x += OFFSET[dir][0];
		y += OFFSET[dir][1];
	}
	x -= OFFSET[dir][0];
	y -= OFFSET[dir][1];
}

void dfs(int x, int y, Direction dir, int level)
{
	if (visit[x][y][dir])
	{
		return;
	}
	
	go(x, y, t[level], dir);
	if (level == n)
	{
		return;
	}

	int x1, x2, y1, y2;
	Direction dir1, dir2;
	switch (dir)
	{
	case UP:
		dir1 = UPLEFT;
		dir2 = UPRIGHT;
		x1 = x - 1;
		x2 = x + 1;
		y1 = y + 1;
		y2 = y + 1;
	break;
	case DOWN:
		dir1 = DOWNLEFT;
		dir2 = DOWNRIGHT;
		x1 = x - 1;
		x2 = x + 1;
		y1 = y2 = y - 1;
	break;
	case LEFT:
		dir1 = DOWNLEFT;
		dir2 = UPLEFT;
		x1 = x2 = x - 1;
		y1 = y - 1;
		y2 = y + 1;
	break;
	case RIGHT:
		dir1 = DOWNRIGHT;
		dir2 = UPRIGHT;
		x1 = x2 = x + 1;
		y1 = y - 1;
		y2 = y + 1;
	break;
	case UPLEFT:
		dir1 = LEFT;
		dir2 = UP;
		x1 = x - 1;
		y1 = y;
		x2 = x;
		y2 = y + 1;
	break;
	case UPRIGHT:
		dir1 = RIGHT;
		dir2 = UP;
		x1 = x + 1;
		y1 = y;
		x2 = x;
		y2 = y + 1;
	break;
	case DOWNLEFT:
		dir1 = LEFT;
		dir2 = DOWN;
		x1 = x - 1;
		y1 = y;
		x2 = x;
		y2 = y - 1;
	break;
	case DOWNRIGHT:
		dir1 = RIGHT;
		dir2 = DOWN;
		x1 = x + 1;
		y1 = y;
		x2 = x;
		y2 = y - 1;
	break;
	}
	
	dfs(x1, y1, dir1, level + 1);
	dfs(x2, y2, dir2, level + 1);
}

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int i;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
	
	queue<State> Q;
	Q.push(State(180, 180, UP, 1));
	
	int x, y, level;
	Direction dir;
	while (!Q.empty())
	{
		State tmp = Q.front();
		Q.pop();
		x = tmp.x;
		y = tmp.y;
		dir = tmp.dir;
		level = tmp.level;
		if (visit[x][y][dir] >= level)
		{
			continue;
		}
		visit[x][y][dir] = level;
		go(x, y, t[level], dir);
		if (level == n)
		{
			continue;
		}
	
		int x1, x2, y1, y2;
		Direction dir1, dir2;
		switch (dir)
		{
		case UP:
			dir1 = UPLEFT;
			dir2 = UPRIGHT;
			x1 = x - 1;
			x2 = x + 1;
			y1 = y + 1;
			y2 = y + 1;
		break;
		case DOWN:
			dir1 = DOWNLEFT;
			dir2 = DOWNRIGHT;
			x1 = x - 1;
			x2 = x + 1;
			y1 = y2 = y - 1;
		break;
		case LEFT:
			dir1 = DOWNLEFT;
			dir2 = UPLEFT;
			x1 = x2 = x - 1;
			y1 = y - 1;
			y2 = y + 1;
		break;
		case RIGHT:
			dir1 = DOWNRIGHT;
			dir2 = UPRIGHT;
			x1 = x2 = x + 1;
			y1 = y - 1;
			y2 = y + 1;
		break;
		case UPLEFT:
			dir1 = LEFT;
			dir2 = UP;
			x1 = x - 1;
			y1 = y;
			x2 = x;
			y2 = y + 1;
		break;
		case UPRIGHT:
			dir1 = RIGHT;
			dir2 = UP;
			x1 = x + 1;
			y1 = y;
			x2 = x;
			y2 = y + 1;
		break;
		case DOWNLEFT:
			dir1 = LEFT;
			dir2 = DOWN;
			x1 = x - 1;
			y1 = y;
			x2 = x;
			y2 = y - 1;
		break;
		case DOWNRIGHT:
			dir1 = RIGHT;
			dir2 = DOWN;
			x1 = x + 1;
			y1 = y;
			x2 = x;
			y2 = y - 1;
		break;
		}
		
		
		Q.push(State(x1, y1, dir1, level + 1));
		Q.push(State(x2, y2, dir2, level + 1));
	}
	
	for (x = 0; x < N; x++)
	{
		for (y = 0; y < N; y++)
		{
			if (mark[x][y])
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}