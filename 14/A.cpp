#include <iostream>


using namespace std;


const int N = 60;

char a[N][N];


int main()
{
	int n, m, i, j, left,right, up, down;
	
	cin >> n >> m;
	
	left = m - 1;
	up = n - 1;
	right = 0;
	down = 0;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] == '*')
			{
				if (j < left)
				{
					left = j;
				}
				if (j > right)
				{
					right = j;
				}
				if (i < up)
				{
					up = i;
				}
				if (i > down)
				{
					down = i;
				}
			}
		}
	}
	
	for (i = up; i <= down; i++)
	{
		for (j = left; j <= right; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	
	
	return 0;
}