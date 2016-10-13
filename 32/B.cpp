#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	string str;
	string tmp;
	map<string, int> M;
	M["."] = 0;
	M["-."] = 1;
	M["--"] = 2;
	
	cin >> str;
	for (int i = 0; str[i]; i++)
	{
		tmp += str[i];
		if (M.count(tmp) > 0)
		{
			cout << M[tmp];
			tmp = "";
		}
	}
	cout << endl;
	return 0;
}