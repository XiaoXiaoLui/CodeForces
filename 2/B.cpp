#include <iostream>
#include <climits>

#define RIGHT 	0
#define DOWN	1

#define N 1003

using namespace std;

struct Elem
{
	//unsigned int number;
	int exp2;
	int exp5;
};

struct Route
{
	int optDir;
	int exp;
};

// a = b^n*x , return n
// for TLE, we use getExp2 and getExp5 instead
int getExp(unsigned int a, int b)
{
	int n = 0;
	
	while (a % b == 0)
	{
		n++;
		a = a / b;
	}
	
	return n;
}

// to be fast use erfen fa
inline int getExp2(unsigned int a)
{
	int min = 0;
	int max = 30;
	int mid = 0;
	
	
	while (max - min != 1)
	{
		mid = (min + max) / 2;
		
		if ((a & ((1 << mid) - 1)) == 0)
		{
			min = mid;
		}
		else
		{
			max = mid;
		}
	}
	
	return min;
}


// to be fast, use erfen fa
//                   0, 1,  2,   3,   4,    5,      6      7      8        9       10        11          12       
unsigned int EXP5[] = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
inline int getExp5(unsigned int a)
{
	int min = 0;
	int max = 13;
	int mid = 0;
	
	while (max - min != 1)
	{
		mid = (min + max) / 2;
		
		if (a % EXP5[mid] == 0)
		{
			min = mid;
		}
		else
		{
			max = mid;
		}
		
	}
	
	return min;
}


Elem matrix[N][N];
Route route2[N][N];
Route route5[N][N];

int i, j;

int main()
{
	
	int n;
	cin >> n;
	int number;
	
	bool bHasZero = false;
	int zeroI = 0;
	int zeroJ = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> number;
			matrix[i][j].exp2 = getExp2(number);
			matrix[i][j].exp5 = getExp5(number);
			
			if (number == 0 && !bHasZero)
			{
				bHasZero = true;
				zeroI = i;
				zeroJ = j;
			}
		}
	}

	// use dp 
	//first init the edge for convience
	route2[n + 1][n].exp = route2[n][n + 1].exp = 0;
	route5[n + 1][n].exp = route5[n][n + 1].exp = 0;
	
	for (i = n - 1; i >= 1; i--)
	{
		route2[n + 1][i].exp = route2[i][n + 1].exp = INT_MAX;
		route5[n + 1][i].exp = route5[i][n + 1].exp = INT_MAX;
	}
	
	// use dp to contruct the map
	// because of TLE, maybe use pointer to be fast
	/*Elem *pData= matrix;
	Route *pRoute2 = route2;
	Route *pRoute5 = route5;
	Elem *pDataEnd = matrix + n*n;*/

	for (i = n; i >= 1; i--)
	{
		for (j = n; j >= 1; j--)
		{
			// for exp 2
			if (route2[i + 1][j].exp <= route2[i][j + 1].exp)
			{
				route2[i][j].exp = route2[i + 1][j].exp + matrix[i][j].exp2;
				route2[i][j].optDir = DOWN;
			}
			else
			{
				route2[i][j].exp = route2[i][j + 1].exp + matrix[i][j].exp2;
				route2[i][j].optDir = RIGHT;
			}
			
			// for exp 5
			if (route5[i + 1][j].exp <= route5[i][j + 1].exp)
			{
				route5[i][j].exp = route5[i + 1][j].exp + matrix[i][j].exp5;
				route5[i][j].optDir = DOWN;
			}
			else
			{
				route5[i][j].exp = route5[i][j + 1].exp + matrix[i][j].exp5;
				route5[i][j].optDir = RIGHT;
			}
		}
	}
	
	bool b2Less5 = route2[1][1].exp <= route5[1][1].exp;
	int least0s = (b2Less5 ? route2[1][1].exp : route5[1][1].exp);
	
	// there is a zero way
	if (bHasZero && least0s > 1)
	{
		cout << "1" << endl;
		for (i = 1; i < zeroI; i++)
		{
			cout << 'D';
		}
		for (j = 1; j < zeroJ; j++)
		{
			cout << 'R';
		}
		for (i = zeroI; i < n; i++)
		{
			cout << 'D';
		}
		for (j = zeroJ; j < n; j++)
		{
			cout << 'R';
		}
	}
	// normal way
	else
	{
	
		cout << least0s << endl;
		if (b2Less5)
		{
			for (i = 1, j = 1; i < n || j < n; )
			{	
				if (route2[i][j].optDir == RIGHT)
				{
					cout << 'R';
					j++;
				}
				else
				{
					cout << 'D';
					i++;
				}
			}
		}
		else
		{
			for (i = 1, j = 1; i < n || j < n; )
			{	
				if (route5[i][j].optDir == RIGHT)
				{
					cout << 'R';
					j++;
				}
				else
				{
					cout << 'D';
					i++;
				}
			}
		}
	}
	
	return 0;
}