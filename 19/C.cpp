#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const int N = 100005;

int s[N];
int n, start, maxhs;
map<int, int> hs;
vector<int> indexSet[N];
set<int> repeat[N];


int main()
{
	int i, j, k;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
		
		if (hs.count(s[i]) > 0)
		{
			indexSet[hs[s[i]]].push_back(i);
		}
		else
		{
			hs[s[i]] = maxhs++;
			indexSet[hs[s[i]]].push_back(i);
		}
	}
	
	// construct repeat
	for (i = 0; i < maxhs; i++)
	{
		for (j = 0; j < indexSet[i].size() - 1; j++)
		{
			for (k = j + 1; k < indexSet[i].size(); k++)
			{
				repeat[indexSet[i][k] - indexSet[i][j]].insert(indexSet[i][j]);
			}
		}
	}
	
	bool bFind = true;
	set<int>::iterator iter1, iter2;
	while (bFind)
	{
		bFind = false;
		for (i = 1; i <= n / 2; i++)
		{
			iter1 = repeat[i].lower_bound(start);
			
			if (iter1 == repeat[i].end())
			{
				continue;
			}
			
			iter2 = iter1;
			iter2++;
			k = 1;
			
			
			while (k < i && iter2 != repeat[i].end())
			{
				if ((*iter2) == (*iter1) + 1)
				{
					k++;
				}		
				else
				{
					k = 1;
				}
				iter1 = iter2;
				iter2++;
			}
			
			if (k == i)
			{
				bFind =true;
				start = (*iter1) + 1;
				break;
			}
		}
	}
	
	printf("%d\n", n - start);
	for (i = start; i < n; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	
	return 0;
}

