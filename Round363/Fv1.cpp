#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

struct Point
{
	Point()
	{
	}
	Point(ll xx, ll yy) : x(xx), y(yy)
	{
	}
	
	ll x;
	ll y;
};


const int N = 1005;
const int K = 8;
int n, k;
Point m[N];
Point p[K];
int srt[K][N];
int idx[K][N];

inline bool inALine(const Point &place, const Point &m1, const Point &m2)
{
	ll x1, y1, x2, y2;
	x1 = m1.x - place.x;
	y1 = m1.y - place.y;
	x2 = m2.x - place.x;
	y2 = m2.y - place.y;
	
	return (x1*x2 >= 0 && y1*y2 >= 0 && x1*y2 - x2*y1 == 0);
}

struct ComObject
{
	ComObject() : index(0)
	{
	}
	
	ComObject(int i) : index(i)
	{
	}
	
	void setIndex(int i)
	{
		index = i;
	}
	
	bool operator () (const int &i, const int &j) const
	{
		Point place = p[index];
		ll x1, y1, x2, y2;
		x1 = m[i].x - place.x;
		y1 = m[i].y - place.y;
		x2 = m[j].x - place.x;
		y2 = m[j].y - place.y;
		
		if (x1*x2 < 0)
		{
			return x1 < x2;
		}
		
		ll cr = x1*y2 - x2*y1;
		
		// inALine
		if (x1*y2 - x2*y1 == 0)
		{
			if (x1*x2 >= 0 && y1*y2 >= 0)
			{
				return x1*x1 + y1*y1 < x2*x2 + y1*y2;
			}
			else
			{
				return y1 < y2;
			}
		}
		
		if (x1 == 0 && y1 > 0)
		{
			return false;
		}
		
		if (x2 == 0 && y2 > 0)
		{
			return true;
		}
		
		
		
		return (cr > 0);
	
		
	}
	
	int index;
};

int markNum;
int present[N];
/*
vector<int> erasePoints;
inline void killMon(int i)
{
	present[i] = false;
	erasePoints.push_back(i);
}*/

void go(int monIdx, vector<int> &pm)
{
	if (pm.empty())
	{
		return;
	}
	
	int cur = pm.back();
	pm.pop_back();
	
	int *array = srt[cur];
	
	int start, end, m2, blockCount;
	
	//end = lower_bound(array, array + n, monIdx, ComObject(cur)) - array;
	end = idx[cur][monIdx];
	
	while (true)
	{
		
		start = end;
		blockCount = 0;
		while (start > 0)
		{
			if (inALine(p[cur], m[array[start - 1]], m[monIdx]))
			{
				start--;
				if (present[array[start]] != markNum)
				{
					blockCount++;
					if (blockCount > pm.size())
					{
						return;
					}
				}
			}
			else
			{
				break;
			}
		}		
		for (; start < end && present[array[start]] == markNum; start++)
		{
		}
		
		if (start == end)
		{
			present[monIdx] = markNum;
			break;
		}
		
		m2 = array[start];
		go(m2, pm);
		if (present[m2] != markNum)
		{
			break;
		}
	}
}

int main()
{
	int i, j;
	int ans;
	scanf("%d%d", &k, &n);
	for (i = 0; i < k; i++)
	{
		scanf("%lld%lld", &p[i].x, &p[i].y);
	}
	
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", &m[i].x, &m[i].y);
	}
	
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n; j++)
		{
			srt[i][j] = j;
		}
	}
	
	for (i = 0; i < k; i++)
	{
		sort(srt[i], srt[i] + n, ComObject(i));
	}
	
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n; j++)
		{
			idx[i][j] = lower_bound(srt[i], srt[i] + n, j, ComObject(i)) - srt[i];
		}
	}
	
	
	ans = 0;
	for (i = 0; i < n; i++)
	{
		vector<int> pm;
		vector<int> tmp;
		
		for (j = 0; j < k; j++)
		{
			pm.push_back(j);
		}
		
		bool ok = false;
		do
		{
			++markNum;
			tmp = pm;
			go(i, tmp);
			if (present[i] == markNum)
			{
				ok = true;
			}
		
			/*
			for (vector<int>::iterator iter = erasePoints.begin(); iter != erasePoints.end(); iter++)
			{
				present[*iter] = true;
			}
			erasePoints.clear();*/
		} while (next_permutation(pm.begin(), pm.end()) && !ok);
		
		if (ok)
		{
			ans++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}