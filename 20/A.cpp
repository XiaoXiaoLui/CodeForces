#include <iostream>


using namespace std;

const int N = 105;

char a[N];
char b[N];

int main()
{
	cin >> a;
	
	int i, len;
	
	for (i = 0, len = 0; a[i] != '\0'; i++)
	{
		if (i > 0 && a[i] == '/' && a[i - 1] == '/')
		{
			continue;
		}
		b[len++] = a[i];
	}
	
	if (len > 1 && b[len - 1] == '/')
	{
		len--;
	}
	b[len] = '\0';
	
	cout << b << endl;
	
	return 0;
}