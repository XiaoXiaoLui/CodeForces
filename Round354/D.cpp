#include <iostream>
#include <queue>

using namespace std;


struct State
{
	int x;
	int y;
	int rot;
};

const int N = 1002;


int f[N][N][4];
int a[N][N][4];

int main()
{
	int i, j, n, m, xt, yt, xm, ym;
	char ch;
	cin >> n >> m;
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> ch;
			
			switch (ch)
			{
			case '+':
				a[i][j][0] = a[i][j][1] = a[i][j][2] = a[i][j][3] = 1;
				break;
			case '-':
				a[i][j][1]  = a[i][j][3] = 1;
				break;
			case '|':
				a[i][j][0] = a[i][j][2] = 1;
				break;
			case '^':
				a[i][j][0] = 1;
				break;
			case '>':
				a[i][j][3] = 1;
				break;
			case '<':
				a[i][j][1] = 1;
				break;
			case 'v':
				a[i][j][2] = 1;
				break;
			case 'L':
				a[i][j][0] = a[i][j][2] = a[i][j][3] = 1;
				break;
			case 'R':
				a[i][j][0] = a[i][j][1] = a[i][j][2] = 1;
				break;
			case 'U':
				a[i][j][1] = a[i][j][2] = a[i][j][3] = 1;
				break;
			case 'D':
				a[i][j][0] = a[i][j][1] = a[i][j][3] = 1;
				break;
			case '*':
				break;
			}
		}
	}
	
	cin >> xt >> yt >> xm >> ym;
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			f[i][j][0] = f[i][j][1] = f[i][j][2] = f[i][j][3] = -1;
		}
	}
	
	State st, nst;
	queue<State> qu;
	st.x = xt;
	st.y = yt;
	st.rot = 0;
	f[xt][yt][0] = 0;
	qu.push(st);
	int r;
	while (!qu.empty())
	{
		st = qu.front();
		if (st.x == xm && st.y == ym)
		{
			break;
		}
		
		qu.pop();
		r = (st.rot + 1) % 4;
		if (f[st.x][st.y][r] == -1)
		{
			nst = st;
			nst.rot = r;
			qu.push(nst);
			f[st.x][st.y][r] = f[st.x][st.y][st.rot] + 1;
		}
		
		if (st.x - 1 >= 1 && f[st.x - 1][st.y][st.rot] == -1 && a[st.x][st.y][(0 + st.rot) % 4] && a[st.x - 1][st.y][(2 + st.rot) % 4])
		{
			nst = st;
			nst.x--;
			f[nst.x][nst.y][nst.rot] = f[st.x][st.y][st.rot] + 1;
			qu.push(nst);
		}
		
		if (st.y - 1 >= 1 && f[st.x][st.y - 1][st.rot] == -1 && a[st.x][st.y][(1 + st.rot) % 4] && a[st.x][st.y - 1][(3 + st.rot) % 4])
		{
			nst = st;
			nst.y--;
			f[nst.x][nst.y][nst.rot] = f[st.x][st.y][st.rot] + 1;
			qu.push(nst);
		}
		
		if (st.x + 1 <= n && f[st.x + 1][st.y][st.rot] == -1 && a[st.x][st.y][(2 + st.rot) % 4] && a[st.x + 1][st.y][(0 + st.rot) % 4])
		{
			nst = st;
			nst.x++;
			f[nst.x][nst.y][nst.rot] = f[st.x][st.y][st.rot] + 1;
			qu.push(nst);
		}
		
		if (st.y + 1 <= m && f[st.x][st.y + 1][st.rot] == -1 && a[st.x][st.y][(3 + st.rot) % 4] && a[st.x][st.y + 1][(1 + st.rot) % 4])
		{
			nst = st;
			nst.y++;
			f[nst.x][nst.y][nst.rot] = f[st.x][st.y][st.rot] + 1;
			qu.push(nst);
		}
		
	}
	
	int ans = -1;
	int mn = 99999999;
	for (r = 0; r < 4; r++)
	{
		if (f[xm][ym][r] != -1)
		{
			mn = min(mn, f[xm][ym][r]);
		}
	}
	
	if (mn != 99999999)
	{
		ans = mn;
	}
	
	cout << ans << endl;
	
	
	return 0;
}