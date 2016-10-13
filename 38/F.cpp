#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const int N = 33;


struct State
{
	State() : points(0), result(0), first(0), second(0), visit(false), number(0)
	{
	}
	
	bool operator > (const State &other) const
	{
		if (result != other.result)
		{
			return result > other.result;
		}
		
		if (first != other.first)
		{
			return first > other.first;
		}
		
		return second < other.second;
	}
	
	int points;
	int result;
	int first;
	int second;
	
	int number;
	bool visit;
};

map<string, State> stateMap;
string s[N];

State calState(const State &nextState)
{
	State state;
	state.result = 1 - nextState.result;
	state.first = nextState.points + nextState.second;
	state.second = nextState.first;
	
	return state;
}

void dfs(const string str)
{
	if (stateMap[str].visit)
	{
		return;
	}
	
	string nextStr;
	State &curState = stateMap[str];
	State tmpState;
	char ch;
	for (ch = 'a'; ch <= 'z'; ch++)
	{
		nextStr = ch + str;
		if (stateMap.count(nextStr) > 0)
		{
			dfs(nextStr);
			tmpState = calState(stateMap[nextStr]);
			
			if (tmpState > curState)
			{
				curState.result = tmpState.result;
				curState.first = tmpState.first;
				curState.second = tmpState.second;
			}
		}
		
		
		nextStr = str + ch;
		if (stateMap.count(nextStr) > 0)
		{
			dfs(nextStr);
			tmpState = calState(stateMap[nextStr]);
			
			if (tmpState > curState)
			{
				curState.result = tmpState.result;
				curState.first = tmpState.first;
				curState.second = tmpState.second;
			}
		}
	}
	
	
	curState.visit = true;
}


int main()
{
	int n, i, j, k, l, c, start;
	string tmp;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < s[i].length(); j++)
		{
			for (k = 1; j + k - 1 < s[i].length(); k++)
			{
				tmp = s[i].substr(j, k);
				c = 0;
				for (l = 0; l < n; l++)
				{
					start = s[l].find(tmp);
					if (start != string::npos)
					{
						c++;
					}
				}
				stateMap[tmp].number = c;
			}
		}
	}
	
	map<string, State>::iterator iter;
	for (iter = stateMap.begin(); iter != stateMap.end(); iter++)
	{
		tmp = iter->first;
		int valueSum = 0;
		int maxValue = 0;
		for (i = 0; i < tmp.length(); i++)
		{
			valueSum += tmp[i] - 'a' + 1;
			maxValue = max(maxValue, tmp[i] - 'a' + 1);
		}
		iter->second.points = iter->second.number + valueSum * maxValue;
	}
	
	stateMap[""];
	dfs("");
	State &ans = stateMap[""];
	cout << (ans.result ? "First" : "Second") << endl << ans.first << " " << ans.second << endl;
	
	return 0;
}