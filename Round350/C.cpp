#include <iostream>
#include <map>

using namespace std;

#define N 2000002

int a[N];
int b[N];
int c[N];
map<int, int> record;

int main()
{
	int n, m, i, j, c1, c2;
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		record[a[i]]++;
	}
	
	cin >> m;
	
	for (i = 1; i <= m; i++)
	{
		cin >> b[i];
	}
	
	for (i = 1; i <= m; i++)
	{
		cin >> c[i];
	}
	
	
	int max1 = 0;
	int max2 = 0;
	int maxIndex = 1;
	
	for (i = 1; i <= m; i++)
	{
		c1 = record.count(b[i]) > 0 ? record[b[i]] : 0;
		c2 = record.count(c[i]) > 0 ? record[c[i]] : 0;
		
		if (c1 > max1 || (c1 == max1 && c2 > max2))
		{
			maxIndex = i;
			max1= c1;
			max2 = c2;
		}
	}
	
	cout << maxIndex;
	
	return 0;
}