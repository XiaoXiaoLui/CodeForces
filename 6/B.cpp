#include <iostream>
#include <set>

using namespace std;

struct Position
{
	int row;
	int col;
};

#define N 101

char matrix[N][N];

int main()
{
	int m, n;
	char chPresident;
	int i, j;
	set<char> deputies;
	
	cin >> m >> n >> chPresident;
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	Position p1;
	Position p2;
	Position p3;
	Position p4;
	
	i = 0;
	j = 0;
	while (i < m)
	{
		if (matrix[i][j] == chPresident)
		{
			break;
		}
		
		j++;
		if (j == n)
		{
			j = 0;
			i++;
		}
	}
	
	p1.row = i;
	p1.col = j;
	
	for (i = p1.row, j = p1.col; j < n && matrix[i][j] == chPresident; j++);
	p2.row = i;
	p2.col = j - 1;
	
	for (i = p2.row, j = p2.col; i < m && matrix[i][j] == chPresident; i++);
	p3.row = i - 1;
	p3.col = j;
	
	p4.row = p3.row;
	p4.col = p1.col;
	
	// find adjacent desk
	
	// left
	if (p1.col != 0)
	{
		for (i = p1.row; i <= p4.row; i++)
		{
			deputies.insert(matrix[i][p1.col - 1]);
		}
	}
	
	// up
	if (p1.row != 0)
	{
		for (j = p1.col; j <= p2.col; j++)
		{
			deputies.insert(matrix[p1.row - 1][j]);
		}
	}
	
	// right
	if (p2.col != n - 1)
	{
		for (i = p2.row; i <= p3.row; i++)
		{
			deputies.insert(matrix[i][p2.col + 1]);
		}
	}
	
	// down
	if (p4.row != m - 1)
	{
		for (j = p4.col; j <= p3.col; j++)
		{
			deputies.insert(matrix[p4.row + 1][j]);
		}
	}
	
	deputies.erase('.');
	cout << deputies.size() << endl;
	
	
	
	return 0;
}