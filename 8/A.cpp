#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int main()
{
	string seq;
	string first;
	string second;
	bool bForward = false;
	bool bBackward = false;
	
	cin >> seq >> first >> second;
	
	size_t pos = 0;
	
	
	// check if forward
	pos = seq.find(first);
	
	if (pos != string::npos)
	{
		pos = seq.find(second, pos + first.length());
		
		if (pos != string::npos)
		{
			bForward = true;
		}
	}
	
	
	// check if backward
	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());
	
	pos = seq.find(second);
	
	if (pos != string::npos)
	{
		pos = seq.find(first, pos + second.length());
		
		if (pos != string::npos)
		{
			bBackward = true;
		}
	}
	
	if (bForward && bBackward)
	{
		cout << "both" << endl;
	}
	else if (bForward)
	{
		cout << "forward" << endl;
	}
	else if (bBackward)
	{
		cout << "backward" << endl;
	}
	else
	{
		cout << "fantasy" << endl;
	}
	
	
	
	
	return 0;
}