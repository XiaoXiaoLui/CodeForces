// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

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

const int N = 2050;
const int BASE = 1331;
//const ll MOD = 1e9 + 7;

int cnt1[N];
int cnt2[N];
ll ha[N];
ll expo[N];


void kmp(const string &s, const string &pat, int *mark)
{
	int i, j;
	vector<int> next(pat.size());
	next[0] = -1;
	for (i = 1, j = -1; i < pat.size(); i++)
	{
		for (; j != -1 && pat[j + 1] != pat[i]; j = next[j]);
		
		if (pat[j + 1] == pat[i])
		{
			j++;
		}
		next[i] = j;
	}
	
	for (i = 0, j = -1; i < s.size(); i++)
	{
		for (; j != -1 && s[i] != pat[j + 1]; j = next[j]);
		
		if (pat[j + 1] == s[i])
		{
			j++;
		}
		
		if (j + 1 == pat.size())
		{
			mark[i] = 1;
		}
	}
}

ll calHash(int start, int end)
{
	ll curHash;
	if (start > 0)
	{
		curHash = ha[end] - ha[start - 1] * expo[end - start + 1];
	}
	else
	{
		curHash = ha[end];
	}
	
	return curHash;
}

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif
	
	string str, s1, s2;
	cin >> str >> s1 >> s2;
	kmp(str, s1, cnt1);
	kmp(str, s2, cnt2);
	
	int i, j;
	
	expo[0] = 1;
	for (i = 1; i <= str.size(); i++)
	{
		expo[i] = (expo[i - 1] * BASE);
	}
	
	ha[0] = str[0];
	for (i = 1; i < str.size(); i++)
	{
		ha[i] = ha[i - 1] * BASE + str[i];
	}
	
	int ans = 0;
	//set<ll> visitSet;
	vector<ll> vec;
	for (i = 0; i < str.size(); i++)
	{
		if (cnt1[i])
		{
			int end = i + max(0, (int)(s2.size() - s1.size()));
			int start = i + 1 - s1.size();
			
			for (j = end; j < str.size(); j++)
			{
				if (cnt2[j])
				{
					ll curHash = calHash(start, j);
					vec.push_back(curHash);
					/* this cause TLE
					if (visitSet.count(curHash) == 0)
					{
						ans++;
						visitSet.insert(curHash);
					}*/
				}
			}
		}
	}
	
	sort(vec.begin(), vec.end());
	ans = unique(vec.begin(), vec.end()) - vec.begin();
	cout << ans << endl;
	
	return 0;
}