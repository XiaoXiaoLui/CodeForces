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

#define USE_IOSTREAM \
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1e5 + 100;
const string STR_SIZE[] = {"", "S", "M", "L", "XL", "XXL", "XXXL"};

int num[10];
pii w[N];
int ans[N];

int str2Num(const string &str)
{
	int i;
	for (i = 1; i <= 6; i++)
	{
		if (STR_SIZE[i] == str)
		{
			return i;
		}
	}
	
	return 0;
}

int main()
{
	USE_IOSTREAM;
	
	int n, i, pos, idx1, idx2;
	string tmp;
	
	for (i = 1; i <= 6; i++)
	{
		cin >> num[i];
	}
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> tmp;
		pos = tmp.find(',');
		if (pos != string::npos)
		{
			idx1 = str2Num(tmp.substr(0, pos));
			idx2 = str2Num(tmp.substr(pos + 1));
			w[i] = mp(10*idx1 + idx2, i);
		}
		else
		{
			idx1 = str2Num(tmp);
			w[i] = mp(10*idx1, i);
		}
	}
	
	sort(w + 1, w + 1 + n);
	for (i = 1; i <= n; i++)
	{
		idx1 = w[i].first / 10;
		idx2 = w[i].first % 10;
		
		if (num[idx1])
		{
			num[idx1]--;
			ans[w[i].second] = idx1;
		}
		else if (num[idx2])
		{
			num[idx2]--;
			ans[w[i].second] = idx2;
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << STR_SIZE[ans[i]] << endl;
	}
	
	
	
	
	return 0;
}