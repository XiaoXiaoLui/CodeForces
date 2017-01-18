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


bool isLucky(int num)
{
	while (num)
	{
		if (num % 10 != 4 && num % 10 != 7)
		{
			return false;
		}
		num /= 10;
	}
	return true;
}

const int N = 1e5 + 100;
int a[N];
int srt[N];
int b[N];
int pos[N];


vector<pii> ans;

bool cmp(int i, int j)
{
	return a[i] < a[j];
}

void swapPos(int i, int j)
{
	int u, v;
	u = b[i];
	v = b[j];
	swap(b[i], b[j]);
	swap(pos[u], pos[v]);
	
	ans.push_back({i, j});
}

int main()
{
	USE_IOSTREAM;
	int n, i, j, u, v;
	int curIdx = 0;
	cin >> n;
	
	
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (!curIdx && isLucky(a[i]))
		{
			curIdx = i;
		}
		srt[i] = i;
		b[i] = i;
		pos[i] = i;
	}
	
	bool needSort = false;
	for (i = 2; i <= n; i++)
	{
		if (a[i - 1] > a[i])
		{
			needSort = true;
			break;
		}
	}
	
	if (!curIdx && needSort)
	{
		cout << -1 << endl;
		return 0;
	}
	else if (!needSort)
	{
		cout << 0 << endl;
		return 0;
	}
	
	sort(srt + 1, srt + 1 + n, cmp);
	
	for (i = 1; i < n; i++)
	{
		if (b[i] == srt[i] || srt[i] == curIdx)
		{
			continue;
		}
		
		j = pos[srt[i]];
		if (pos[curIdx] != i)
		{
			swapPos(i, pos[curIdx]);
		}
		
		swapPos(i, j);
	}
	
	if (b[n] != srt[n])
	{
		swapPos(n, pos[srt[n]]);
	}
	
	cout << ans.size() << endl;
	for (auto tmp : ans)
	{
		cout << tmp.first << " " << tmp.second << endl;
	}
	
	return 0;
}