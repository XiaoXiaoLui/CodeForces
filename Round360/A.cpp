#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 200;
bool a[N][N];
bool win[N];
int main()
{
	int n, i, j, d;
	char ch;
	cin >> n >> d;
	bool canWin = true;
	for (i = 1; i <= d; i++)
	{
		canWin = false;
		for (j = 1; j <= n; j++)
		{
			cin >> ch;
			a[i][j] = (ch == '1');
			if (!a[i][j])
			{
				canWin = true;
			}
		}
		win[i] = canWin;
	}
	
	int ans = 0;
	int start = 0;
	for (i = 1; i <= d; i++)
	{
		if (win[i])
		{
			ans = max(ans, i - start);
		}
		else
		{
			start = i;
		}
	}
	
	cout << ans << endl;
	return 0;
}