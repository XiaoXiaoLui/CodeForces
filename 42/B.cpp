#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 8;
int a[10][10];
const int DIR[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
const int DIR2[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


bool inRange(int x, int y)
{
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

void rookFill(pii rook)
{
	int x, y, k;
	for (k = 0; k < 4; k++)
	{
		x = rook.first + DIR2[k][0];
		y = rook.second + DIR2[k][1];
		while (inRange(x, y) && a[x][y] != 2)
		{
			a[x][y] = 1;
			x += DIR2[k][0];
			y += DIR2[k][1];
		}
		
	}
}


void kingFill(pii king)
{
	int x, y, k;
	a[king.first][king.second] = 2;
	for (k = 0; k < 8; k++)
	{
		x = king.first + DIR[k][0];
		y = king.second + DIR[k][1];
		if (inRange(x, y))
		{
			a[x][y] = 1;
		}
	}
}

int main()
{
	pii rook1, rook2, king1, king2;
	int x, y;
	char str[50];
	gets(str);
	rook1.first = str[0] - 'a' + 1;
	rook1.second = str[1] - '0';
	rook2.first = str[3] - 'a' + 1;
	rook2.second = str[4] - '0';
	king1.first = str[6] - 'a' + 1;
	king1.second = str[7] - '0';
	king2.first = str[9] - 'a' + 1;
	king2.second = str[10] - '0';
	
	kingFill(king1);
	rookFill(rook1);
	rookFill(rook2);
	
	
	bool ans = true;
	
	if (!a[king2.first][king2.second])
	{
		ans = false;
	}
	for (int k = 0; k < 8; k++)
	{
		x = king2.first + DIR[k][0];
		y = king2.second + DIR[k][1];
		if (inRange(x, y) && !a[x][y])
		{
			ans = false;
			break;
		}
	}
	
	
	printf("%s\n", ans ? "CHECKMATE" : "OTHER");
	return 0;
}