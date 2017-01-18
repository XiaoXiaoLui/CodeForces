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
#define psi pair<string, int>


bool isPalin(const string &s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

struct Compare
{
	bool operator() (const psi &p1, const psi &p2) const
	{
		if (p1.first != p2.first)
		{
			return p1.first < p2.first;
		}
		return p1.second > p2.second;
	}
};


const int N = 1e5 + 100;
const int INF = 2e9;
string s[N];
int w[N];

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int n, len, i, j;
	cin >> n >> len;
	multiset<psi, Compare> S;
	for (i = 1; i <= n; i++)
	{
		cin >> s[i] >> w[i];
		S.insert({s[i], w[i]});
	}
	
	bool bPalin;
	int add = 0;
	int ans = 0;
	for (auto iter = S.begin(); iter != S.end(); )
	{
		string tmp = iter->first;
		bPalin = isPalin(tmp);
		reverse(tmp.begin(), tmp.end());
		auto saveP = *iter;
		auto tmpIter = iter;
		iter++;
		S.erase(tmpIter);
		auto revIter = S.lower_bound({tmp, INF});
		
		if (revIter != S.end() && revIter->first == tmp)
		{
			if (saveP.second > 0 && revIter->second > 0)
			{
				ans += saveP.second + revIter->second;
				if (iter == revIter)
				{
					iter++;
				}
				S.erase(revIter);
			}
			else if (saveP.second > 0)
			{
				if (saveP.second + revIter->second > 0)
				{
					if (bPalin)
					{
						add = max(add, -revIter->second);
					}
					ans += saveP.second + revIter->second;
					if (iter == revIter)
					{
						iter++;
					}
					S.erase(revIter);
				}
				else if (bPalin)
				{
					add = max(add, saveP.second);
				}
			}
			else if (revIter->second > 0)
			{
				if (saveP.second + revIter->second > 0)
				{
					if (bPalin)
					{
						add = max(add, -saveP.second);
					}
					ans += saveP.second + revIter->second;
					if (iter == revIter)
					{
						iter++;
					}
					S.erase(revIter);
				}
				else if (bPalin)
				{
					add = max(add, revIter->second);
					if (iter == revIter)
					{
						iter++;
					}
					S.erase(revIter);
				}
			}
		}
		else if (bPalin && saveP.second > 0)
		{
			add = max(add, saveP.second);
		}
	}
	
	ans += add;
	
	cout << ans << endl;
	
	return 0;
}