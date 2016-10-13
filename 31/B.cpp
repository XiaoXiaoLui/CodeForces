#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;

int main()
{
	int n, i, j, pos;
	string str, tmp;
	bool ok = true;
	cin >> str;
	n = str.length();
	pos = str.rfind('@');
	if (pos == string::npos)
	{
		ok = false;
	}
	
	for (i = 0; i < n && ok; i = j + 1)
	{
		if (str[i] == '@')
		{
			ok = false;
			break;
		}
		for (j = i; j < n && str[j] != '@'; j++);
		if (j == pos)
		{
			j = n - 1;
		}
		else
		{
			j++;
		}
		if (j >= n || str[j] == '@')
		{
			ok = false;
			break;
		}
		ans.push_back(str.substr(i, j - i + 1));
	}
	
	if (ok)
	{
		for (i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << ((i == ans.size() - 1) ? '\n' : ',');
		}
	}
	else
	{
		cout << "No solution" << endl;
	}
	
	
	return 0;
}