#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;



int main()
{
	int i, n, c1, c2, ans;
	
	string s;
	cin >> n >> s;
	
	for (c1 = c2 = 0, i = 0; i < n; i++)
	{
		if (s[i] - '0' == i % 2)
		{
			c1++;
		}
		else
		{
			c2++;
		}
	}
	ans = min(c1, c2);
	
	cout << ans << endl;
	return 0;
}