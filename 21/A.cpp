#include <iostream>
#include <string>

using namespace std;


bool check1(const string &str)
{
	int len = str.size();
	
	if (len < 1 || len > 16)
	{
		return false;
	}
	
	for (int i = 0; i < len; i++)
	{
		if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_')
		{
			return false;
		}
	}
	
	return true;
}

bool check2(const string &str)
{
	int len = str.size();
	
	if (len < 1 || len > 32)
	{
		return false;
	}
	
	int index = 0;
	int pos;
	string word;
	
	while (index < len)
	{
		pos = str.find('.', index);
		if (pos != string::npos)
		{
			word = str.substr(index, pos - index);
			index = pos + 1;
		}
		else
		{
			word = str.substr(index, len - index);
			index = len;
		}
		
		if (!check1(word))
		{
			return false;
		}
	}
	
	if (str[len - 1] == '.')
	{
		return false;
	}
	
	return true;
}

int main()
{
	string str, userName, hostName, resource;
	int index1, index2;
	cin >> str;
	bool ok = true;
	
	index1 = str.find('@');
	if (index1 == string::npos)
	{
		ok = false;
	}
	else
	{
		index2 = str.find('/');
		if (index2 != string::npos && index2 < index1)
		{
			ok = false;
		}
		else if (index2 == string::npos)
		{
			userName = str.substr(0, index1);
			hostName = str.substr(index1 + 1, str.size() - index1 - 1);
			if (!check1(userName))
			{
				ok = false;
			}
			if (!check2(hostName))
			{
				ok = false;
			}
			
		}
		else
		{
			userName = str.substr(0, index1);
			hostName = str.substr(index1 + 1, index2 - index1 - 1);
			resource = str.substr(index2 + 1, str.size() - index2 - 1);
			if (!check1(userName))
			{
				ok = false;
			}
			if (!check2(hostName))
			{
				ok = false;
			}
			if (!check1(resource))
			{
				ok = false;
			}
		}
	}
	
	if (ok)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}