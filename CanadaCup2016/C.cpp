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

const int N = 300;
int pos[N];
char a[2][30];

int main()
{
	USE_IOSTREAM;
	string s;
	int p1, p2, i;
	cin >> s;
	fill(pos, pos + N, -1);
	for (i = 0; i < s.size(); i++)
	{
		if (pos[s[i]] == -1)
		{
			pos[s[i]] = i;
		}
		else
		{
			p1 = pos[s[i]];
			p2 = i;
		}
	}
	
	if (p1 + 1 == p2)
	{
		cout <<  "Impossible" << endl;
		return 0;
	}
	
	if (p1 > 12)
	{
		reverse(s.begin(), s.end());
		int tmp = p1;
		p1 = 26 - p2;
		p2 = 26 - tmp;
	}
	
	int p1I, p1J, p2I, p2J, endI, endJ, startI, startJ, curI, curJ, nextI, nextJ;
	p1I = 1;
	p1J = 13 - (p2 - p1 + 1) / 2;
	
	
	if (p1J >= p1)
	{
		startI = 1;
		startJ = p1J - p1;
	}
	else
	{
		startI = 0;
		startJ = p1 - p1J - 1;
	}
	
	for (i = 0, curI = startI, curJ = startJ; i < s.size(); i++)
	{
		a[curI][curJ] = s[i];
		if (i < p1)
		{
			if (curI == 0)
			{
				curJ--;
				if (curJ < 0)
				{
					curI = 1;
					curJ = 0;
				}
			}
			else
			{
				curJ++;
			}
		}
		else if (i == p1)
		{
			if ((p2 - p1) % 2)
			{
				curI = 0;
				curJ++;
			}
			else
			{
				curI = 0;
			}
		}
		else if (i < p2)
		{
			if (curI == 0)
			{
				curJ++;
				if (curJ > 12)
				{
					curI = 1;
					curJ = 12;
				}
			}
			else
			{
				curJ--;
			}
		}
		else if (i == p2)
		{
			if ((p2 - p1) % 2)
			{
				curI = 0;
			}
			else
			{
				curI = 0;
				curJ--;
			}
		}
		else
		{
			if (curI == 0)
			{
				curJ--;
				if (curJ < 0)
				{
					curI = 1;
					curJ = 0;
				}
			}
			else
			{
				curJ++;
			}
		}
	}
	
	
	for (i = 0; i < 2; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}