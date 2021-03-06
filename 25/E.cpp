#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 100005;
string s[3];
int next[3 * N];
int p[3] = {0, 1, 2};

string getMin(const string &s1, const string &s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	int len3 = len1 + len2 + 1;
	
	string s3 = s1 + '+' + s2;
	
	int i, j;
	next[0] = -1;
	for (i = 1; i < len3; i++)
	{
		j = next[i - 1];
		
		while (j != -1 && s3[j + 1] != s3[i])
		{
			j = next[j];
		}
		
		if (s3[j + 1] == s3[i])
		{
			j++;
		}
		next[i] = j;
	}
	
	for (i = len1 + 1; i < len3; i++)
	{
		if (next[i] == len1 - 1)
		{
			return s2;
		}
	}
	
	return s2.substr(0, len2 - (next[len3 - 1] + 1)) + s1;
	
}

int main()
{
	int i;
	int ans = 99999999;
	string tmp;
	
	cin >> s[0] >> s[1] >> s[2];
	
	
	do
	{
		tmp = getMin(s[p[0]], s[p[1]]);
		tmp = getMin(tmp, s[p[2]]);
		ans = min(ans, (int)tmp.size());
	} while (next_permutation(p, p + 3));
	

	cout << ans << endl;
	
	return 0;
}