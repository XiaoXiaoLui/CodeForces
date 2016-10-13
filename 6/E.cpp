#include <iostream>
#include <set>


using namespace std;


struct Region
{
	int start;
	int end;
	Region(){}
	Region(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
	
	bool operator < (const struct Region &other) const 
	{
		return start < other.start;
	}
};

#define N 100004
int h[N];

int main()
{
	int n, allowDiff;
	int i;
	int p1, p2;
	multiset<int> curSet;
	int minHeight;
	int maxHeight;
	int maxLen = 0;
	set<Region> regionSet;
	
	cin >> n >> allowDiff;
	
	for (i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	
	p1 = p2 = 1;
	curSet.insert(h[1]);
	while (p2 <= n)
	{
		minHeight = (*curSet.begin());
		maxHeight = (*curSet.rbegin());
		
		if (maxHeight - minHeight <= allowDiff)
		{
			if (p2 - p1 + 1 > maxLen)
			{
				maxLen = p2 - p1 + 1;
				regionSet.clear();
				regionSet.insert(Region(p1, p2));
			}
			else if (p2 - p1 + 1 == maxLen)
			{
				regionSet.insert(Region(p1, p2));
			}
			p2++;
			curSet.insert(h[p2]);
		}
		else
		{
			curSet.erase(curSet.lower_bound(h[p1]));
			p1++;
		}
	}
	
	cout << maxLen << " " << regionSet.size() << endl;
	set<Region>::iterator iter;
	for (iter = regionSet.begin(); iter != regionSet.end(); ++iter)
	{
		cout << (*iter).start << " " << (*iter).end << endl;
	}
	
	return 0;
}