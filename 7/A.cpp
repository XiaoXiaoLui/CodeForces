#include <iostream>

using namespace std;

#define N 8
int main()
{
	char grid[N][N];
	bool bFull = true;
	int strokes = 0;
	bool bLineFull;
	
	int i, j;
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'W')
			{
				bFull = false;
			}
		}
	}
	
	if (bFull)
	{
		strokes = N;
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			bool bLineFull = true;
			for (j = 0; j < N; j++)
			{
				if (grid[i][j] == 'W')
				{
					bLineFull = false;
					break;
				}
			}
			
			if (bLineFull)
			{
				strokes++;
			}
		}
		
		for (i = 0; i < N; i++)
		{
			bool bLineFull = true;
			for (j = 0; j < N; j++)
			{
				if (grid[j][i] == 'W')
				{
					bLineFull = false;
					break;
				}
			}
			
			if (bLineFull)
			{
				strokes++;
			}
		}
	}
	
	cout << strokes << endl;
	
	
	return 0;
}