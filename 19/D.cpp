#include <map>
#include <climits>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;



const int N = 200005;
const int M = 1 << 18;

int xNum;
int rHash[N];
int hash[N];
set<int> ySet[N];
int st[2*M];
int T[N];
int X[N];
int Y[N];
int srt[N];

bool cmpx(int i, int j)
{
	return X[i] < X[j];
}

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
	char type[10];
	int x, y, i, ansX, ansY, index, ny, t;
	map<int, int>::iterator iterMap;
	set<int>::iterator iterSet;
	
	int n;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%s%d%d", type, &X[i], &Y[i]);
		
		if (!strcmp(type, "add"))
		{
			T[i] = 0;	
		}
		else if (!strcmp(type, "remove"))
		{
			T[i] = 1;			
		}
		else
		{
			T[i] = 2;	
		}
		
		srt[i] = i;
	}

	sort(srt, srt + n, cmpx);
	
	for (xNum = -1, i = 0; i < n; i++)
	{
		if (i == 0 || X[srt[i]] > X[srt[i - 1]])
		{
			hash[srt[i]] = ++xNum;
		}
		else
		{
			hash[srt[i]] = xNum;
		}
		rHash[xNum] = X[srt[i]];
	}
	
	for (i = 0; i < n; i++)
	{
		t = T[i];
		x = X[i];
		y = Y[i];
		index = hash[i];
		
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
				printf("-1\n");
			}
			else
			{
				ansY = *ySet[ansX].upper_bound(y);
				ansX = rHash[ansX];
				printf("%d %d\n", ansX, ansY);
			}
		}
	}
	
	return 0;
}