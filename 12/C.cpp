#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

const int N = 102;
int a[N];
int b[N];

int main()
{
	int n, m, i, j, len, min, max;
	map<string, int> table;
	string tmp;
	
	
	cin >> n >> m;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (i = 0; i < m; i++)
	{
		cin >> tmp;
		
		table[tmp]++;
	}
	
	len = 0;
	for (map<string, int>::iterator iter = table.begin(); iter != table.end(); iter++)
	{
		b[len++] = (*iter).second;
	}
	
	sort(a, a + n);
	sort(b, b + len);
	
	min = max = 0;
	
	for (i = 0; i < len; i++)
	{
		min += b[i] * a[len - 1 - i];
	}
	
	for (i = 0; i <len; i++)
	{
		max += b[i] * a[n - len + i];
	}
	
	cout << min << " " << max << endl;
	
	return 0;
}