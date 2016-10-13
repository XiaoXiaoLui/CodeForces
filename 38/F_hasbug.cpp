#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define mp make_pair<int, int>

const int N = 33;

struct State
{	
	int len;
	
	// points get
	int first;
	int second;
	
	int points;
	
	int result; // 1 first win, 0 second win
	
	vector<pii> posLst;
};


string s[N];

State dp[N][N][N];

State ans;

void update(int i1, int j1, int k1, int i2, int j2, int k2)
{
	State &state1 = dp[i1][j1][k1];
	State &state2 = dp[i2][j2][k2];
	if (!state1.result && !state2.result || 
		!(state1.result && state2.result) && (state1.first < state2.points + state2.second) || ((state1.first == state2.points + state2.second) && state1.second > state2.first))
	{
		state1.result = 1 - state2.result;
		state1.first = state2.points + state2.second;
		state1.second = state2.first;
	}
	
	if (state1.len == 1)
	{
		if (!ans.result && !state1.result || 
		!(state1.result && ans.result) && (ans.first < state1.points + state1.second) || ((ans.first == state1.points + state1.second) && ans.second > state1.first))
		{
			ans.result = 1 - state1.result;
			ans.first = state1.points + state1.second;
			ans.second = state1.first;
		}
	}
}

int main()
{
	int n, i, j, k, l, len, start, end;
	string curString;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	int curMax;
	int sum;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < s[i].length(); i++)
		{
			curMax = 0;
			sum = 0;
			for (k = j; k < s[i].length(); k++)
			{
				len = k - j + 1;
				sum += s[i][k] - 'a' + 1;
				curMax = max(curMax, s[i][k] - 'a' + 1);
				curString = s[i].substr(j, len);
				dp[i][j][k].len = len;
				dp[i][j][k].result = 0;
				for (l = 0; l < n; l++)
				{
					start = s[l].find(curString);
					if (start != string::npos)
					{
						dp[i][j][k].posLst.push_back(mp(l, start));
					}
				}
				dp[i][j][k].points = sum * curMax + dp[i][j][k].posLst.size();
				dp[i][j][k].first = dp[i][j][k].second = 0;
			}
		}
	}

	
	pii tmp;
	for (len = 30; len >= 1; len--)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < (int)s[i].length() - len; j++)
			{
				for (k = 0; k < dp[i][j][j + len - 1].posLst.size(); k++)
				{
					tmp = dp[i][j][j + len - 1].posLst[k];
					start = tmp.second;
					end = start + len - 1;
					if (start != 0)
					{
						update(i, j, j + len - 1, tmp.first, start - 1, end);
					}
					if (end != s[i].length() - 1)
					{
						update(i, j, j + len - 1, tmp.first, start, end + 1);
					}
				}
			}
		}
	}
	
	cout << (ans.result ? "First" : "Second") << endl;
	cout << ans.first << " " << ans.second << endl;
	
	return 0;
}