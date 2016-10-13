#include <iostream>
#include <string>
#include <set>

using namespace std;


int main()
{
	string strLine;
	int amount = 0;
	set<string> nameList;
	size_t pos = 0;
	string name;
	int msgSize = 0;
	
	while (getline(cin, strLine))
	{
		if (cin.eof())
		{
			break;
		}
		
		if (strLine[0] == '+')
		{
			nameList.insert(strLine.substr(1));
		}
		else if (strLine[0] == '-')
		{
			nameList.erase(strLine.substr(1));
		}
		else
		{
			pos = strLine.find_first_of(':');
			if (pos == strLine.length())
			{
				cout << "error in line 35" << endl;
				break;
			}
			
			//name = strLine.substr(0, pos);
			msgSize = strLine.length() - pos - 1;
			
			amount += msgSize * nameList.size();
		}
		
	}
	
	cout << amount << endl;
	
	
	return 0;
}