#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <set>

using namespace std;

int main()
{
	int n = 0;
	string strName;
	int point = 0;
	int maxScore = 0;
	map<string, int> stat;
	queue<pair<string, int> > record;
	string strWinner;
	set<string> winners;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> strName >> point;
		record.push(pair<string, int>(strName, point));
		stat[strName] += point;
	}
	
	maxScore = 0;
	map<string,int>::iterator  iter;
	for (iter = stat.begin(); iter != stat.end(); ++iter)
	{
		if ((*iter).second > maxScore)
		{
			maxScore = (*iter).second;
			winners.clear();
			winners.insert((*iter).first);
		}
		else if ((*iter).second == maxScore)
		{
			winners.insert((*iter).first);
		}
	}
	
	if (winners.size() == 1)
	{
		strWinner = *winners.begin();
	}
	
	else
	{
		stat.clear();
		
		pair<string, int> item;
		while (!record.empty())
		{
			item = record.front();
			if (winners.count(item.first) > 0)
			{
				stat[item.first] += item.second;
				
				if (stat[item.first] >= maxScore)
				{
					strWinner = item.first;
					break;
				}
			}
			
			record.pop();
		}
	}
	
	cout << strWinner << endl;
	
	return 0;
}