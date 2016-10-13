#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;


int main()
{
	map<string, int> nameMap;
	int n;
	string name;
	string number;
	stringstream ss;
	
	cin >> n;
	
	for (int i = 0;i < n; i++)
	{
		cin >> name;
		if (nameMap.count(name) > 0)
		{
			nameMap[name]++;
			ss.clear();
			ss << nameMap[name];
			ss >> number;
			name += number;
			cout << name << endl;
		}
		else
		{
			nameMap[name];
			cout << "OK" << endl;
		}
	}
	
	
	
	return 0;
}