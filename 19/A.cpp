#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


const int N = 60;

struct Team
{
	string name;
	int points;
	int miss;
	int score;
	int diff;
};

bool cmpStanding(const Team &a, const Team &b)
{
	return (a.points > b.points || (a.points == b.points && (a.diff > b.diff || (a.diff == b.diff && a.score > b.score))));
}

bool cmpName(const Team &a, const Team &b)
{
	return (a.name < b.name);
}


Team team[N];
map<string, Team> teamInfo;

int main()
{
	int n, i, num, s1, s2, pos;
	string name1, name2, tmpStr;
	char noUse;
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> name1;
		teamInfo[name1];
	}
	
	num = (n - 1) * n / 2;
	for (i = 0; i < num; i++)
	{
		cin >> tmpStr;
		pos = tmpStr.find('-');
		name1 = tmpStr.substr(0, pos);
		name2 = tmpStr.substr(pos + 1);
		
		cin >> s1 >> noUse >> s2;
		
		
		if (s1 > s2)
		{
			teamInfo[name1].points += 3;
		}
		else if (s1 == s2)
		{
			teamInfo[name1].points += 1;
			teamInfo[name2].points += 1;
		}
		else
		{
			teamInfo[name2].points += 3;
		}
		teamInfo[name1].miss += s2;
		teamInfo[name1].score += s1;
		
		teamInfo[name2].miss += s1;
		teamInfo[name2].score += s2;
	}
	
	map<string, Team>::iterator iter;
	for (i = 0, iter = teamInfo.begin(); iter != teamInfo.end(); iter++, i++)
	{
		team[i] = iter->second;
		team[i].name = iter->first;
		team[i].diff = team[i].score - team[i].miss;
	}
	
	sort(team, team + n, cmpStanding);
	sort(team, team + n / 2, cmpName);
	
	for (i = 0; i < n / 2; i++)
	{
		cout << team[i].name << endl;
	}
	
	return 0;
}