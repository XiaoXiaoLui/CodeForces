#include <iostream>
#include <set>
#include <climits>
#include <cstring>

using namespace std;

const int N = 202;

set<int> joint[N];
set<int> aset;
set<int> bset;
bool visit[N];
int dist[N];

int n;

void dfsSet(set<int> &st, int i)
{
	set<int>::iterator iter;
	
	visit[i] = true;
	st.insert(i);
	for (iter = joint[i].begin(); iter != joint[i].end(); iter++)
	{
		if (!visit[*iter])
		{
			dfsSet(st, *iter);
		}
	}
}

void dfsDist(int i, int &curMax)
{
	set<int>::iterator iter;
	visit[i] = true;
	
	for (iter = joint[i].begin(); iter != joint[i].end(); iter++)
	{
		if (!visit[*iter])
		{
			dist[*iter] = dist[i] + 1;
			curMax = max(dist[*iter], curMax);
			dfsDist(*iter, curMax);
		}
	}
}

void output()
{
	for (int i = 1; i <= n; i++)
	{
		cout << i << " : ";
		for (set<int>::iterator iter = joint[i].begin(); iter != joint[i].end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int main()
{
	int i, j, k, aMax, bMax, ans = 0;
	
	cin >> n;
	
	for (k = 1; k <= n - 1; k++)
	{
		cin >> i >> j;
		joint[i].insert(j);
		joint[j].insert(i);
	}
	
	set<int>::iterator iter, iter2;
	for (i = 1; i <= n; i++)
	{
		for (iter = joint[i].begin(); iter != joint[i].end(); iter++)
		{
			j = *iter;
			if (i > j)
			{
				continue;
			}
			
			joint[i].erase(iter);
			joint[j].erase(i);
			
			memset(visit, 0, sizeof(visit));
			aset.clear();
			bset.clear();
			dfsSet(aset, i);
			dfsSet(bset, j);
			
			aMax = 0;
			bMax = 0;
			

			for (iter2 = aset.begin(); iter2 != aset.end(); iter2++)
			{
				if (joint[*iter2].size() == 1)
				{
					memset(visit, 0, sizeof(visit));
					dist[*iter2] = 0;
					dfsDist(*iter2, aMax);
				}
			}
			

			for(iter2 = bset.begin(); iter2 != bset.end(); iter2++)
			{
				if (joint[*iter2].size() == 1)
				{
					memset(visit, 0, sizeof(visit));
					dist[*iter2] = 0;
					dfsDist(*iter2, bMax);
				}
			}
			
			ans = max(ans, aMax * bMax);
			
			joint[j].insert(i);
			iter = joint[i].insert(j).first;
			
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}