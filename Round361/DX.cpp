#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 2e5 + 5;
int a[N];
int b[N];
int srt1[N];
int srt2[N];

bool cmp1(int i, int j)
{
	return a[i] > a[j] || (a[i] == a[j] && i < j);
}

bool cmp2(int i, int j)
{
	return b[i] > b[j] || (b[i] == b[j] && i < j);
}

int main()
{
	int n, i, j, p, q;
	ll ans = 0LL;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		srt1[i] = srt2[i] = i;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	sort(srt1, srt1 + n, cmp1);
	sort(srt2, srt2 + n, cmp2);
	
	set<int> S;
	S.insert(-1);
	S.insert(n);
	i = 0;
	j = 0;
	deque<int> tmpLst1;
	deque<int> tmpLst2;
	deque<int>::iterator qIter;
	set<int>::iterator sIter1, sIter2;
	ans = 0LL;
	int left, right, last;
	while (i < n && j < n)
	{
		while (i < n && (tmpLst1.empty() || a[srt1[i]] == a[srt1[i - 1]]))
		{
			tmpLst1.push_back(srt1[i]);
			i++;
		}
		
		while (j < n && (tmpLst2.empty() || b[srt2[j]] == b[srt2[j - 1]]))
		{
			tmpLst2.push_back(srt2[j]);
			j++;
		}
		
		if (a[tmpLst1[0]] < b[tmpLst2[0]])
		{
			S.insert(tmpLst2.begin(), tmpLst2.end());
			tmpLst2.clear();
		}
		else if (a[tmpLst1[0]] > b[tmpLst2[0]])
		{
			S.insert(tmpLst1.begin(), tmpLst1.end());
			tmpLst1.clear();
		}
		else
		{
			last = -1;
			for (p = 0, q = 0; p < tmpLst1.size() && q < tmpLst2.size();)
			{
				if (tmpLst1[p] < tmpLst2[q])
				{
					sIter1 = S.upper_bound(tmpLst1[p]);
					sIter2 = sIter1;
					sIter1--;
					//qIter = upper_bound(tmpLst2.begin(), tmpLst2.end(), tmpLst1[p]);
					
					left = *sIter1;
					left = max(left, last);
					
					if (tmpLst2[q] < *sIter2)
					{
						ans += (ll)(tmpLst1[p] - left) * (*sIter2 - tmpLst2[q]);
					}
					
					last = tmpLst1[p];
					p++;
				}
				else if (tmpLst1[p] > tmpLst2[q])
				{
					sIter1 = S.upper_bound(tmpLst2[q]);
					sIter2 = sIter1;
					sIter1--;
					//qIter = upper_bound(tmpLst1.begin(), tmpLst1.end(), tmpLst2[q]);
					
					left = *sIter1;
					left - max(left, last);
					
					if (tmpLst1[p] < *sIter2)
					{
						ans += (ll)(tmpLst2[q] - left) * (*sIter2 - tmpLst1[p]);
					}
					
					last = tmpLst2[q];
					q++;
				}
				else
				{
					sIter1 = S.upper_bound(tmpLst1[p]);
					sIter2 = sIter1;
					sIter1--;
					//qIter = upper_bound(tmpLst2.begin(), tmpLst2.end(), tmpLst1[p]);
					
					left = *sIter1;
					left = max(left, last);
					
		
					ans += (ll)(tmpLst1[p] - left) * (*sIter2 - tmpLst1[p]);
					
					last = tmpLst1[p];
					p++;
					q++;
				}
			}
			S.insert(tmpLst1.begin(), tmpLst1.end());
			S.insert(tmpLst2.begin(), tmpLst2.end());
			tmpLst1.clear();
			tmpLst2.clear();
		}
	}
	
	
	printf(LLD "\n", ans);
	return 0;
}