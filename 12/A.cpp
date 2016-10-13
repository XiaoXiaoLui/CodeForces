#include <iostream>

using namespace std;

const int N = 9;

char a[N][N];

int main()
{
	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
	
	
	bool ret = true;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (a[i][j] != a[2-i][2-j])
			{
				ret = false;
				break;
			}
		}
	}
	
	if (ret)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}