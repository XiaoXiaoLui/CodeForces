#include <map>
#include <climits>
#include <iostream>
#include <set>

using namespace std;



const int N = 200005;
const int M = 1 << 18;

set<int> xSet;
int xNum;
int rHash[N];
map<int, int> hash;
set<int> ySet[N];
int st[2*M];
int T[N];
int X[N];
int Y[N];

void buildSegmentTree()
{
	for (int i = 0; i < 2*M; i++)
	{
		st[i] = INT_MIN;
	}
}

void change(int index, int value)
{	
	int i, tmp;
	
	i = M + index;
	st[i] = value;
	
	i >>= 1;
	
	while (i > 0)
	{
		tmp = max(st[i + i], st[i + i + 1]);
		if (tmp == st[i])
		{
			break;
		}
		st[i] = tmp;
		i >>= 1;
	}
}

int find(int i, int y, int start, int l, int r)
{
	int index;
	if (start > r || st[i] <= y)
	{
		return -1;
	}
	if (l == r)
	{
		return (st[l + M] > y) ? l : -1;
	}
	int l1, l2, r1, r2, len;
	len = (r - l + 1) >> 1;
	l1 = l;
	r1 = l + len - 1;
	l2 = r1 + 1;
	r2 = r;
	
	index = find(i + i, y, start, l1, r1);
	
	if (index == -1)
	{
		index = find(i + i + 1, y, start, l2, r2);
	}
	
	return index;
	
}

int findPos(int y, int start)
{	
	int l = 0;
	int r = M - 1;
	
	return find(1, y, start, l, r);
}

int main()
{
	string type;
	int x, y, i, ansX, ansY, index, ny, t;
	map<int, int>::iterator iterMap;
	set<int>::iterator iterSet;
	
	int n;
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> type >> X[i] >> Y[i];
		xSet.insert(X[i]);
		
		if (type == "add")
		{
			T[i] = 0;	
		}
		else if (type == "remove")
		{
			T[i] = 1;			
		}
		else
		{
			T[i] = 2;	
		}
	}

	for (iterSet = xSet.begin(); iterSet != xSet.end(); iterSet++)
	{
		hash[*iterSet] = xNum;
		rHash[xNum] = *iterSet;
		xNum++;
	}
	
	for (i = 0; i < n; i++)
	{
		//cin >> type >> x >> y;
		t = T[i];
		x = X[i];
		y = Y[i];
		index = hash[x];
		
		if (t == 0)
		{
			ySet[index].insert(y);
			
			if (y == *ySet[index].rbegin())
			{
				change(index, y);
			}
		}
		else if (t == 1)
		{
			ySet[index].erase(y);
			
			ny = ySet[index].empty() ? INT_MIN : (*ySet[index].rbegin());
			
			if (ny < y)
			{
				change(index, ny);
			}
		}
		else
		{
			ansX = findPos(y, index + 1);
			
			if (ansX == -1)
			{
				cout << "-1" << endl;
			}
			else
			{
				ansY = *ySet[ansX].upper_bound(y);
				ansX = rHash[ansX];
				cout << ansX << " " << ansY << endl;
			}
		}
	}
	
	return 0;
}