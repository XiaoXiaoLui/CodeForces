#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

pii parseNum(const char *s, int n)
{
	int i;
	int a, b;
	a = b = 0;
	if (n > 3 && s[n - 3] == '.')
	{
		for (i = 0; i < n - 3; i++)
		{
			if (s[i] == '.')
			{
				continue;
			}
			a = 10*a + (s[i] - '0');
		}
		b = (s[n - 2] - '0') * 10 + (s[n - 1] - '0');
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			if (s[i] == '.')
			{
				continue;
			}
			
			a = 10*a + (s[i] - '0');
		}
	}
	
	
	return mp(a, b);
}

int main()
{
	string ans, s;
	int a, b, i, j, start, end;
	a = b = 0;
	pii tmp;
	
	cin >> s;
	for (i = 0; i < s.size(); i++)
	{
		for (; i < s.size() && isalpha(s[i]); i++);
		start = i;
		for (; i < s.size() && isdigit(s[i]) || s[i] == '.'; i++);
		end = i;
		tmp = parseNum(s.substr(start, end - start).c_str(), end - start);
		a += tmp.first;
		b += tmp.second;
	}
	
	a += b / 100;
	b %= 100;
	i = 0;
	if (a == 0)
	{
		ans = "0";
	}
	else
	{
		i = 0;
		while (a)
		{
			ans += (a % 10) + '0';
			a /= 10;
			i++;
			if (i == 3 && a)
			{
				i = 0;
				ans += '.';
			}
		}
		reverse(ans.begin(), ans.end());
	}
	
	if (b)
	{
		ans += '.';
		ans +=  (b / 10) + '0';
		ans += (b % 10) + '0';
	}
	
	
	cout << ans << endl;
	return 0;
}