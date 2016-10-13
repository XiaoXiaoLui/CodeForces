#include <iostream>

using namespace std;

enum RESULT
{
	DRAW,
	XWIN,
	OWIN,
	XNEXT,
	ONEXT,
	IILEGAL,
};


enum STATE
{
	OOO,
	XXX,
	EMPTY,
};

const int N = 3;

STATE grid[N][N];
int main()
{
	char ch;
	RESULT result = IILEGAL;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			switch (ch)
			{
			case 'X':
				grid[i][j] = XXX;
				break;
			case '0':
				grid[i][j] = OOO;
				break;
			case '.':
				grid[i][j] = EMPTY;
				break;
			default:
				break;
			}
		}
	}
	
	bool bXline = false;
	bool bOline = false;
	bool bFull = false;
	int xMinusO = 0;
	int xTotal = 0;
	int oTotal = 0;
	int total = 0;
	int iXRow;
	int iXCol;
	int iORow;
	int iOCol;
	
	int i,j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (grid[i][j] == OOO)
			{
				oTotal++;
			}
			else if (grid[i][j] == XXX)
			{
				xTotal++;
			}
		}
	}
	
	total = xTotal + oTotal;
	if (total == N * N)
	{
		bFull = true;
	}
	xMinusO = xTotal - oTotal;
	
	// check if a row or a column form a line
	for (i = 0; i < N; i++)
	{
		iXRow = 0;
		iXCol = 0;
		iORow = 0;
		iOCol = 0;
		for (j = 0; j < N; j++)
		{
			if (grid[i][j] == OOO)
			{
				iORow++;
			}
			else if (grid[i][j] == XXX)
			{
				iXRow++;
			}
			
			if (grid[j][i] == OOO)
			{
				iOCol++;
			}
			else if (grid[j][i] == XXX)
			{
				iXCol++;
			}
		}
		
		if (iXRow == N || iXCol == N)
		{
			bXline = true;
		}
		
		if (iORow == N || iOCol == N)
		{
			bOline = true;
		}
	}
	
	// check if diagonal line
	iXRow = 0;
	iXCol = 0;
	iORow = 0;
	iOCol = 0;
	for (i = 0; i < N; i++)
	{
		if (grid[i][i] == OOO)
		{
			iORow++;
		}
		else if (grid[i][i] == XXX)
		{
			iXRow++;
		}
		
		if (grid[i][N - i - 1] == OOO)
		{
			iOCol++;
		}
		else if (grid[i][N - i - 1] == XXX)
		{
			iXCol++;
		}
	}
	
	if (iXRow == N || iXCol == N)
	{
		bXline = true;
	}
	
	if (iORow == N || iOCol == N)
	{
		bOline = true;
	}
	
	// judge the result according to bXline, bOline, bFull and xMinusO
	if (bXline && !bOline && xMinusO == 1)
	{
		result = XWIN;
	}
	else if (!bXline && bOline && xMinusO == 0)
	{
		result = OWIN;
	}
	else if (!bXline && !bOline && bFull && xMinusO == 1)
	{
		result = DRAW;
	}
	else if (!bXline && !bOline && !bFull && xMinusO == 1)
	{
		result = ONEXT;
	}
	else if (!bXline && !bOline && !bFull && xMinusO == 0)
	{
		result = XNEXT;
	}
	else
	{
		result = IILEGAL;
	}
	
	
	switch (result)
	{
	case DRAW:
		cout << "draw" << endl;
		break;
	case XWIN:
		cout << "the first player won" << endl;
		break;
	case OWIN:
		cout << "the second player won" << endl;
		break;
	case XNEXT:
		cout << "first" << endl;
		break;
	case ONEXT:
		cout << "second" << endl;
		break;
	case IILEGAL:
		cout << "illegal" << endl;
		break;
	}
	
	
	
	
	return 0;
}