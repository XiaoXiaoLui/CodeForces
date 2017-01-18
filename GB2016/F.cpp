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
#include <assert.h>
#include <queue>

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

int guessCount = 0;

void guess(int a)
{
	++guessCount;
	if (guessCount > 16)
	{
		exit(5);
	}
	cout << "? " << a << endl << flush;
}

void verify(int a)
{
	cout << "! " << a << endl << flush;
}

void getResult(vector<int> &res)
{
	res.clear();
	int num, a;
	cin >> num;
	while (num--)
	{
		cin >> a;
		res.push_back(a);
	}
}

int multiGuess(int cur, int pre, vector<vector<int> > &path)
{
	path.clear();
	path.push_back(vector<int>(1, pre));
	vector<int> curVec;
	int height = 1;
	while (true)
	{
		height++;
		guess(cur);
		getResult(curVec);
		
		vector<int> tmp;
		tmp.push_back(cur);
		tmp.insert(tmp.end(), curVec.begin(), curVec.end());
		path.push_back(tmp);
		
		if (curVec.size() == 2)
		{
			verify(cur);
			return 0;
		}
		else if (curVec.size() == 1)
		{
			return height;
		}
		
		int next = curVec[0] == pre ? curVec[1] : curVec[0];
		pre = cur;
		cur = next;
	}
	return -1; // error
}

void finalGuess(int cur, int pre)
{
	vector<int> curVec;
	queue<pii> Q;
	Q.push({cur, pre});
	int cnt = 0;
	while (guessCount < 16)
	{
		cur = Q.front().first;
		pre = Q.front().second;
		Q.pop();
		guess(cur);
		getResult(curVec);
		if (curVec.size() == 2)
		{
			verify(cur);
			return;
		}
		
		for (int i = 0; i < curVec.size(); i++)
		{
			if (curVec[i] != pre)
			{
				Q.push({curVec[i], cur});
			}
		}
	}
	
	cur = Q.front().first;
	verify(cur);
}

void goBack(vector<vector<int> > &path, int preHeight, int &curHeight, int &cur, int &pre)
{
	curHeight = (path.size() - preHeight) / 2 + preHeight;
	int idx = curHeight - preHeight;
	for (int i = 1; i < 4; i++)
	{
		if (path[idx][i] != path[idx - 1][0] && path[idx][i] != path[idx + 1][0])
		{
			pre = path[idx][0];
			cur = path[idx][i];
			break;
		}
	}
}

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	vector<int> curVec, tmpVec, hVec(3);
	vector<vector<int> >path[3];
	int t, h, curNum, nextNum, preNum, curH;
	cin >> t;
	int idx = 0;
	while (t--)
	{
		guessCount = 0;
		cin >> h;
		guess(1);
		getResult(curVec);
		if (curVec.size() == 2)
		{
			verify(1);
			continue;
		}
		else if (curVec.size() == 1)
		{
			curNum = curVec[0];
			preNum = 1;
			curH = 2;
		}
		else
		{
			bool hasVerify = false;
			for (int i = 0; i < 3; i++)
			{
				hVec[i] = multiGuess(curVec[i], 1, path[i]);
				if (hVec[i] == 0)
				{
					hasVerify = true;
					break;
				}
			}
			if (hasVerify)
			{
				continue;
			}
			
			sort(hVec.begin(), hVec.end());
			
			idx = 0;
			for (int i = 1; i < 3; i++)
			{
				if (path[i].size() > path[idx].size())
				{
					idx = i;
				}
			}
			
			goBack(path[idx], hVec[0], curH, curNum, preNum);
			curH++;
		}
		
		bool hasVerify = false;
		while (curH <= 4)
		{
			int ret = multiGuess(curNum, preNum, path[0]);
			if (ret == 0)
			{
				hasVerify = true;
				break;
			}
			else
			{
				goBack(path[0], curH - 1, curH, curNum, preNum);
				curH++;
			}
		}
		
		if (!hasVerify)
		{
			finalGuess(curNum, preNum);
		}
	}
	
	return 0;
}