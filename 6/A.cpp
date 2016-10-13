#include <iostream>

using namespace std;

#define N 4
#define TRIANGLE 0
#define SEGMENT 1
#define IMPOSSIBLE 2

// len of a is m + 1
void combinationFirst(int n, int m, int a[])
{
	for (int i = 0; i < m; i++)
	{
		a[i] = i;
	}
	a[m] =  n; // this is for convienience
}

// m <= n
bool combinationNext(int n, int m, int a[])
{
	int pos = 0;
	
	for (pos = 0; pos < m && a[pos] + 1 == a[pos + 1]; pos++);
	
	if (pos == m)
	{
		return false; // no next combination
	}
	
	a[pos]++;
	
	for (int i = 0; i < pos; i++)
	{
		a[i] = i;
	}
	
	return true;
}


// judge if a, b, c can make a triangle
int judge(int a, int b, int c)
{
	int result = IMPOSSIBLE;
	int diff = 0;
	
	if (a >= b && a >= c)
	{
		diff = b + c - a;
	}
	else if (b >= a && b >= c)
	{
		diff = a + c - b;
	}
	else
	{
		diff = a + b - c;
	}
	
	if (diff > 0)
	{
		result = TRIANGLE;
	}
	else if (diff == 0)
	{
		result = SEGMENT;
	}
	else
	{
		result = IMPOSSIBLE;
	}
	
	return result;
	
}

int main()
{
	int sticks[N];
	int a[4];
	int m = 3;
	int result = IMPOSSIBLE;
	int curResult = IMPOSSIBLE;
	
	for (int i = 0; i < N; i++)
	{
		cin >> sticks[i];
	}
	
	combinationFirst(N, m, a);
	
	do
	{
		curResult = judge(sticks[a[0]], sticks[a[1]], sticks[a[2]]);
		
		if (curResult == TRIANGLE)
		{
			result = TRIANGLE;
			break;
		}
		else if (curResult == SEGMENT)
		{
			result = SEGMENT;
		}
		
	} while (combinationNext(N, m, a));
	
	switch (result)
	{
	case TRIANGLE:
		cout << "TRIANGLE" << endl;
		break;
	case SEGMENT:
		cout << "SEGMENT" << endl;
		break;
	case IMPOSSIBLE:
		cout << "IMPOSSIBLE" << endl;
		break;
	default:
		break;
	}
	
	return 0;
}