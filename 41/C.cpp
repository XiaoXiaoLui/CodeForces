#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int pos = s.find("at", 1);
	s.replace(pos, 2, "@");
	
	pos = s.find("dot", 1);
	while (pos != string::npos && pos != s.length() - 3)
	{
		s.replace(pos, 3, ".");
		pos = s.find("dot", 1);
	}
	
	cout << s << endl;
	return 0;
}