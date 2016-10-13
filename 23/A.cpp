#include <iostream>
#include <string>

using namespace std;


int main()
{
	string str;
	string sub;
	int ans = 0;
	int pos;
	
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			sub = str.substr(i, j - i + 1);
			pos = str.find(sub, i + 1);
			
			if (pos != string::npos && j - i + 1 > ans)
			{
				ans = j - i + 1;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}