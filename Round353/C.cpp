#include <iostream>
#include <map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 100005;
ll a[N];
ll s[N];

map<ll, int> countTable;

int main()
{
	int n, i;
	ll ans = 0;
	map<ll, int>::iterator bestIter;
	map<ll, int>::iterator iter;
	cin >> n;
	
	if (n == 1)
	{
		ans = 0;
		goto SS;
	}
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	s[2] = a[2];
	countTable[s[2]]++;

	for (i = 3; i <= n; i++)
	{
		s[i] =  s[i - 1] + a[i];
		countTable[s[i]]++;
	}
	
	bestIter = countTable.begin();
	for (iter = countTable.begin(); iter != countTable.end(); iter++)
	{
		if ((*iter).second > (*bestIter).second || ((*iter).second == (*bestIter).second && (*iter).first == 0))
		{
			bestIter = iter;
		}
	}
	
	if ((*bestIter).first == 0)
	{
		ans = n - 1 - (*bestIter).second;
	}
	else
	{
		ans = n - (*bestIter).second;
	}
	
	
SS:
	cout << ans << endl;
	

	
	return 0;
}