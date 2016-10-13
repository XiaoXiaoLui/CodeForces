#include <iostream>


using namespace std;

char str[100003];
int a[26];

int main()
{
	int n;
	cin >> n;
	cin >> str;
	int index, count = 0;
	if (n > 26)
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			index = str[i] - 'a';
			if (a[index])
			{
				count++;
			}
			else
			{
				a[index] = 1;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}

