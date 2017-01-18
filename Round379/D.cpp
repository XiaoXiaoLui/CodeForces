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

const int N = 5e5 + 100;

struct Piece
{
	char type;
	int x;
	int y;
};


Piece piece[N];


void nextLine()
{
	while (getchar() != '\n');
}

map<pii, bool> used;
map<int, set<int> > row;
map<int, set<int> > col;
map<int, set<int> > dia1;
map<int, set<int> > dia2;

int main()
{
	// USE_IOSTREAM;
	int x, y, i, x0, y0, n;
	char type;
	scanf("%d", &n);
	scanf("%d%d", &x0, &y0);
	nextLine();
	for (i = 1; i <= n; i++)
	{
		scanf("%c%d%d", &type, &x, &y);
		nextLine();
		piece[i].type = type;
		piece[i].x = x;
		piece[i].y = y;
		
		row[y].insert(x);
		col[x].insert(y);
		dia1[x + y].insert(x);
		dia2[x - y].insert(x);
	}
	
	row[y0].insert(x0);
	col[x0].insert(y0);
	dia1[x0 + y0].insert(x0);
	dia2[x0 - y0].insert(x0);
	
	bool f1, f2;
	bool ok = false;
	for (i = 1; i <= n && !ok; i++)
	{
		if (piece[i].type == 'Q')
		{
			f1 = f2 = true;
		}
		else if (piece[i].type == 'R')
		{
			f1 = true;
			f2 = false;
		}
		else
		{
			f1 = false;
			f2 = true;
		}
		
		x = piece[i].x;
		y = piece[i].y;
		if (f1)
		{
			if (x == x0)
			{
				if (y < y0)
				{
					auto iter = col[x].upper_bound(y);
					if (*iter == y0)
					{
						ok = true;
					}
				}
				else
				{
					auto iter = col[x].upper_bound(y0);
					if (*iter == y)
					{
						ok = true;
					}
				}
			}
			else if (y == y0)
			{
				if (x < x0)
				{
					auto iter = row[y].upper_bound(x);
					if (*iter == x0)
					{
						ok = true;
					}
				}
				else
				{
					auto iter = row[y].upper_bound(x0);
					if (*iter == x)
					{
						ok = true;
					}
				}
			}
		}
		
		if (f2)
		{
			if (x + y == x0 + y0)
			{
				if (x < x0)
				{
					auto iter = dia1[x + y].upper_bound(x);
					if (*iter == x0)
					{
						ok = true;
					}
				}
				else
				{
					auto iter = dia1[x + y].upper_bound(x0);
					if (*iter == x)
					{
						ok = true;
					}
				}
			}
			else if (x - y == x0 - y0)
			{
				if (x < x0)
				{
					auto iter = dia2[x - y].upper_bound(x);
					if (*iter == x0)
					{
						ok = true;
					}
				}
				else
				{
					auto iter = dia2[x - y].upper_bound(x0);
					if (*iter == x)
					{
						ok = true;
					}
				}
			}
		}
	}
	
	if (ok)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}